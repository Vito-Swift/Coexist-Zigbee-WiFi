//
// Created by Vito Wu on 2021/8/11.
//

#ifndef ZIGBEETESTBED_CCA_UTILS_H
#define ZIGBEETESTBED_CCA_UTILS_H

#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
#include <vector>

#define CCA_BUSY 0
#define CCA_CLEAR 1

struct cca_stat {
    // collect 1 / sample_freq of samples in 1 sec
    double sample_freq;

    // auxiliary variable to state the current CSI; 1: clear, 0: busy
    unsigned int channel_status;

    // auxiliary timestamp to record the start time of white space
    struct timespec white_window_start_tt;

    // white space history (the vector size should be
    // equal to the sample_freq * window span(s))
    std::vector<unsigned int> cca_window;
    pthread_mutex_t cca_window_mutex;
    unsigned int cca_window_size;

    // preset appropriate T value to pass the K-S test
    unsigned int window_time_span;

    // statistic variable to record the average lifetime of white space
    // within the window_time_span duration
    float average_white_space_life_time;

    // pthread variables to control the termination of sampling threads
    bool terminate_flag;
    pthread_mutex_t request_mutex;
    pthread_mutex_t terminate_mutex;

    cca_stat() {
        pthread_mutex_init(&request_mutex, nullptr);
        pthread_mutex_init(&terminate_mutex, nullptr);
        pthread_mutex_init(&cca_window_mutex, nullptr);
    }
};

typedef struct {
    cca_stat *stat;
    double sample_freq;
    unsigned int window_time_span;
} cca_sampling_args_t;

void *start_cca_sampling(void *vargs);

// unit: usecond
// return -1 if channel busy
long get_whitespace_age_usec(cca_stat *stat);

float get_avg_whitespace_age_in_window(cca_stat *stat);

void stop_cca_sampling(cca_stat *stat);

inline bool test_cancel(pthread_mutex_t *mutex, bool *val) {
    bool ret = false;
    pthread_mutex_lock(mutex);
    ret = *val;
    pthread_mutex_unlock(mutex);
    return ret;
}

#define detach_cca_sampling(ccaStat, args_sample_freq, args_window_time_span) \
     {    \
        cca_sampling_args_t args;   \
        args.stat = &(ccaStat);   \
        args.window_time_span = (args_window_time_span);                 \
        args.sample_freq = (args_sample_freq); \
        pthread_t sampling_thread; \
        pthread_create(&sampling_thread, NULL, start_cca_sampling, (void *) &args); \
        pthread_detach(sampling_thread); \
     }


#endif //ZIGBEETESTBED_CCA_UTILS_H
