//
// Created by Vito Wu on 2021/8/11.
//

#include <stdio.h>
#include <pthread.h>

#include "cca_utils/cca_utils.h"

int main() {
    cca_stat ccaStat;
    double sample_freq = 10;
    int window_time_span = 5;
    detach_cca_sampling(ccaStat, sample_freq, window_time_span);  // 1000 milli-sec to get a sample

    for (int i = 0; i < 16; i++) {
        printf("Get whitespace age time %d : \t %ld\n", i, get_whitespace_age_usec(&ccaStat));
        usleep(500000); // 0.5 sec
    }

    stop_cca_sampling(&ccaStat);

    return 0;
}