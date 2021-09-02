#include <stdio.h>
#include <unistd.h>
#include "CC2520.h"

int main(void) {
    unsigned char txbuf[129];
    
    CC2520_Init();
    CC2520_Set_Channel(0, 11);
    while (1) {
        printf("%d\n", CC2520_Get_CCA(0));
       sleep(1); 
    }
}
