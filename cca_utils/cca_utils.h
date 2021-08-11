//
// Created by Vito Wu on 2021/8/11.
//

#ifndef ZIGBEETESTBED_CCA_UTILS_H
#define ZIGBEETESTBED_CCA_UTILS_H

#include <pthread.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    double sample_freq;
    time_t white_window_start_tt;
} cca_stat;

typedef struct {
    cca_stat *stat;
    double sample_freq;
} cca_sampling_args_t;

void *start_cca_sampling(void *vargs);

#endif //ZIGBEETESTBED_CCA_UTILS_H
