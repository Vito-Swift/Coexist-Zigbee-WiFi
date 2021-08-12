//
// Created by Vito Wu on 2021/8/11.
//

#include <stdio.h>
#include <pthread.h>

#include "cca_utils/cca_utils.h"

int main() {
    cca_stat ccaStat;
    cca_sampling_args_t args;
    args.stat = &ccaStat;
    args.sample_freq = 10;      // 1000 milli-sec to get a sample

    pthread_t sampling_thread;
    pthread_create(&sampling_thread, nullptr, start_cca_sampling, (void *) &args);
    pthread_detach(sampling_thread);

    for (int i = 0; i < 16; i++) {
        printf("Get whitespace age time %d : \t %ld\n", i, get_whitespace_age_usec(&ccaStat));
        usleep(500000); // 0.5 sec
    }

    stop_cca_sampling(&ccaStat);

    return 0;
}