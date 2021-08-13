//
// Created by Vito Wu on 2021/8/11.
//

#ifndef ZIGBEETESTBED_CCA_UTILS_H
#define ZIGBEETESTBED_CCA_UTILS_H

#include <pthread.h>
#include <unistd.h>
#include <ctime>
#include <iostream>

#define CCA_BUSY 0
#define CCA_CLEAR 1

struct cca_stat {
    double sample_freq;
    unsigned int channel_status;    // 1: clear, 0: busy
    struct timespec white_window_start_tt;
    bool terminate_flag;

    pthread_mutex_t request_mutex;
    pthread_mutex_t terminate_mutex;

    cca_stat() {
        pthread_mutex_init(&request_mutex, nullptr);
        pthread_mutex_init(&terminate_mutex, nullptr);
    }
};

typedef struct {
    cca_stat *stat;
    double sample_freq;
} cca_sampling_args_t;

void *start_cca_sampling(void *vargs);

// unit: usecond
// return -1 if channel busy
long get_whitespace_age_usec(cca_stat *stat);

void stop_cca_sampling(cca_stat *stat);

inline bool test_cancel(pthread_mutex_t *mutex, bool *val) {
    bool ret = false;
    pthread_mutex_lock(mutex);
    ret = *val;
    pthread_mutex_unlock(mutex);
    return ret;
}

#define detach_cca_sampling(ccaStat, sample_freq) \
     {    \
        cca_sampling_args_t args;   \
        args.stat = &(ccaStat); \
        args.sample_freq = (sample_freq); \
        pthread_t sampling_thread; \
        pthread_create(&sampling_thread, nullptr, start_cca_sampling, (void *) &args); \
        pthread_detach(sampling_thread); \
     }


#endif //ZIGBEETESTBED_CCA_UTILS_H
