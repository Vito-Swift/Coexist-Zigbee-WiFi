#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "CC2520.h"

int main(void) {
    unsigned char tx_buf[129];
    int i;
    int send_count, len;
    CC2520_Init();
    bzero(tx_buf, 129);

    // F_c = 2405 + 5 * (k - 11) [MHz]
    // e.g, F_11 = 2405 MHz
    CC2520_Set_Channel(0, 11);
    CC2520_Set_TX_Power(0, 5);

    IEEE802154_Fill_Data_Frame_Control(tx_buf,
                                       IEEE802154_NO_FRAME_PENDING,
                                       IEEE802154_NO_ACK,
                                       IEEE802154_ADDR_MODE_SHORT_ADDR,
                                       IEEE802154_ADDR_MODE_SHORT_ADDR);

    IEEE802154_Fill_Sequence_Num(tx_buf, 0);

    // arg list: *Buf, dst_panid, dst_addr, src_panid, src_addr 
    IEEE802154_Fill_Data_Frame_Short_Addr(tx_buf, 11110, 22220, 33333, 44444);

    // obtain the pointer of the start point of packet payload
    unsigned char *buf = IEEE802154_Data_Frame_Get_Payload_Pointer(tx_buf);
    char data[] = "Hello World!\0";
    memcpy(buf, data, sizeof(data));
    i = 0;
    while (1)
    {
        printf("Sending no. %d\tdst_pan: %d\tdst_addr: %d\tsrc_pan: %d\tsrc_addr: %d\n",
               i++, 11110, 22220, 33333, 44444);
        IEEE802154_Fill_Data_Frame_PHY_Frame_Len_Field(tx_buf, 114);
        send_count = CC2520_IEEE802154_Data_Frame_Get_SPI_Payload_Len(tx_buf, 114);
        CC2520_Send_Packet_Blocking(0, tx_buf, send_count);
        sleep(1);
    }

    return 0;
}
