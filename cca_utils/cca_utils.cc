//
// Created by Vito Wu on 2021/8/11.
//

#include "cca_utils.h"
#include "CC2520.h"

static long diff_in_ns(struct timespec t1, struct timespec t2) {
    struct timespec diff;
    if (t2.tv_nsec - t1.tv_nsec < 0) {
        diff.tv_sec = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec * 1000000000.0 + diff.tv_nsec);
}

void *start_cca_sampling(void *vargs) {
    auto *args = (cca_sampling_args_t *) vargs;
    args->stat->sample_freq = args->sample_freq;

    pthread_mutex_lock(&args->stat->terminate_mutex);
    args->stat->terminate_flag = false;
    pthread_mutex_unlock(&args->stat->terminate_mutex);
    CC2520_Init();
    CC2520_Set_Channel(1, 11);

    pthread_mutex_lock(&args->stat->request_mutex);
    timespec_get(&(args->stat->white_window_start_tt), TIME_UTC);

    args->stat->channel_status = CC2520_Get_CCA(1);
    pthread_mutex_unlock(&args->stat->request_mutex);

    auto sample_interval = (unsigned int) ((1 / (double) args->stat->sample_freq) * 1000000);

    while (!test_cancel(&(args->stat->terminate_mutex), &(args->stat->terminate_flag))) {
        pthread_mutex_lock(&args->stat->request_mutex);
        unsigned int prev_channel_status = args->stat->channel_status;
        args->stat->channel_status = CC2520_Get_CCA(1);

        if (prev_channel_status == CCA_BUSY && args->stat->channel_status == CCA_CLEAR) {
            timespec_get(&args->stat->white_window_start_tt, TIME_UTC);
        }
        pthread_mutex_unlock(&args->stat->request_mutex);
        usleep(sample_interval);
    }
    pthread_exit(nullptr);
}

long get_whitespace_age_usec(cca_stat *stat) {
    pthread_mutex_lock(&stat->request_mutex);
    auto whitespace_start_tt = stat->white_window_start_tt;
    auto channel_status = stat->channel_status;

    if (channel_status == CCA_BUSY) {
        pthread_mutex_unlock(&stat->request_mutex);
        return -1;
    }

    timespec now{};
    timespec_get(&now, TIME_UTC);
    pthread_mutex_unlock(&stat->request_mutex);
    return diff_in_ns(whitespace_start_tt, now) / 1000;
}


void stop_cca_sampling(cca_stat *stat) {
    pthread_mutex_lock(&(stat->terminate_mutex));
    stat->terminate_flag = true;
    pthread_mutex_unlock(&(stat->terminate_mutex));
}