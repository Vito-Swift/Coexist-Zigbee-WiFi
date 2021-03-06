//
// Created by Vito Wu on 2021/8/13.
//

#include <iostream>
#include <fstream>
#include <thread>
#include <csignal>

#include "threadsafe_queue.hh"
#include "CC2520.h"

#define SAMPLE_TIME 600     // 10 minutes
#define SAMPLE_FREQ 1000    // 0.001 sec to get a sample

struct program_metadata_t {
    int channel;
    pthread_t writer_thread;
    pthread_t reader_thread;
    bool terminate_flag;
    pthread_mutex_t terminate_mutex;
    Queue<unsigned int> cca_queue;
    std::string output_filename;

    program_metadata_t() {
        pthread_mutex_init(&terminate_mutex, nullptr);
        terminate_flag = false;
    }
};

typedef struct {
    program_metadata_t *metadata;
} pthread_args_t;

program_metadata_t prog_metadata;


void *file_writer(void *vargs);

void *CCA_reader(void *vargs);

bool test_cancel(pthread_mutex_t *mutex, bool *val);

void interrupt_handler(int dummy);

std::string get_datetime_string(time_t t);

int main() {
    signal(SIGINT, interrupt_handler);
	
    for (int i = 11; i < 26; i += 2) {
        if (i != 11) {
            pthread_mutex_lock(&prog_metadata.terminate_mutex);
            prog_metadata.terminate_flag = false;
            prog_metadata.cca_queue.open();
            pthread_mutex_unlock(&prog_metadata.terminate_mutex);
        }
        time_t start_time = time(nullptr);
        prog_metadata.output_filename = "/home/pi/cca_output/cca_output-" + get_datetime_string(start_time) + "-channel" + std::to_string(i) + ".txt";
        prog_metadata.channel=i;
        pthread_args_t args{.metadata = &prog_metadata};
        pthread_create(&prog_metadata.writer_thread, nullptr, CCA_reader, (void *) &args);
        pthread_create(&prog_metadata.writer_thread, nullptr, file_writer, (void *) &args);
        pthread_detach(prog_metadata.reader_thread);
        pthread_detach(prog_metadata.writer_thread);

        while (time(nullptr) < start_time + SAMPLE_TIME) {
            usleep(100000); // sleep for 100 ms
        }

        // terminate both threads
        pthread_mutex_lock(&prog_metadata.terminate_mutex);
        prog_metadata.terminate_flag = true;
        prog_metadata.cca_queue.close();
        pthread_mutex_unlock(&prog_metadata.terminate_mutex);
        sleep(1);
    }

    return EXIT_SUCCESS;
}

void *file_writer(void *vargs) {
    auto metadata = ((pthread_args_t *) vargs)->metadata;
    std::ofstream of(metadata->output_filename);

    if (!of.good()) {
        pthread_mutex_lock(&metadata->terminate_mutex);
        metadata->terminate_flag = true;
        metadata->cca_queue.close();
        pthread_mutex_unlock(&metadata->terminate_mutex);
    }

    while (!test_cancel(&metadata->terminate_mutex, &metadata->terminate_flag)) {
        unsigned int cca;
        if (!metadata->cca_queue.dequeue(cca))  // queue is closed
            break;
        of << cca;
        of.flush();
    }
    of.close();

    pthread_exit(nullptr);
}

void *CCA_reader(void *vargs) {
    auto metadata = ((pthread_args_t *) vargs)->metadata;
    auto sample_interval = (unsigned int) ((1 / (double) SAMPLE_FREQ) * 1000000);

    CC2520_Init();
    CC2520_Set_Channel(0, metadata->channel);

    while (!test_cancel(&metadata->terminate_mutex, &metadata->terminate_flag)) {
        metadata->cca_queue.enqueue(CC2520_Get_CCA(0));
        usleep(sample_interval);
    }
    pthread_exit(nullptr);
}

std::string get_datetime_string(time_t t) {
    struct tm *timeinfo = localtime(&t);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d-%H-%M-%S", timeinfo);
    std::string str(buf);
    return str;
}

void interrupt_handler(int dummy) {
    printf("Catch CTRL-C signal.\n");
    printf("Terminate detached threads and exit.\n");
    pthread_mutex_lock(&prog_metadata.terminate_mutex);
    prog_metadata.terminate_flag = true;
    prog_metadata.cca_queue.close();
    pthread_mutex_unlock(&prog_metadata.terminate_mutex);
    usleep(500000);
    exit(0);
}

bool test_cancel(pthread_mutex_t *mutex, bool *val) {
    bool ret = false;
    pthread_mutex_lock(mutex);
    ret = *val;
    pthread_mutex_unlock(mutex);
    return ret;
}
