//
// Created by Vito Wu on 2021/8/11.
//

#include <stdio.h>
#include <pthread.h>

#include "cca_utils/cca_utils.h"

int main() {
    cca_stat ccaStat;
    double sample_freq = 200;
    int window_time_space = 50;
    detach_cca_sampling(ccaStat, sample_freq, window_time_space);  // 1000 milli-sec to get a sample

    for (int i = 0; i < 16; i++) {
        printf("Get whitespace age time %d : \t %ld\t", i, get_whitespace_age_usec(&ccaStat));
        printf("whitespace window length: %d\t", ccaStat.cca_window.size());
        printf("Get avg white space age: %f \n", get_avg_whitespace_age_in_window(&ccaStat));
        usleep(500000); // 0.5 sec
    }

    stop_cca_sampling(&ccaStat);

    return 0;
}
