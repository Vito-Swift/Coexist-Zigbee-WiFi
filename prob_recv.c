#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "CC2520.h"

int main(void) {
    unsigned char rx_buf[129];
    unsigned char* buf;
    int i = 0;
    int recv_count, len;
    CC2520_Init();
    bzero(rx_buf, 129);
    
    CC2520_Set_Channel(1, 11);
    CC2520_Set_TX_Power(1, 5);
    while (1) {
        while(CC2520_Receive_Packet_Pending(1) == 0);
        recv_count = CC2520_Receive_Packet_Non_Blocking(1, rx_buf);
        printf("Received no: %d\tsrc_pan: %d\tsrc_addr: %d\tPayload: %s\n",
                i++, IEEE802154_Get_SRC_PAN_ID(rx_buf),
                IEEE802154_Get_SRC_Short_Addr(rx_buf),
                IEEE802154_Data_Frame_Get_Payload_Pointer(rx_buf));
       usleep(10000); 
    }
}
