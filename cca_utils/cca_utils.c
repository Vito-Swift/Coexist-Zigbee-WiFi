//
// Created by Vito Wu on 2021/8/11.
//

#include "cca_utils.h"

void *start_cca_sampling(void *vargs) {
    cca_sampling_args_t *args = (cca_sampling_args_t *) vargs;
    args->stat->sample_freq = args->sample_freq;
    args->stat->white_window_start_tt = time(NULL);
    
}