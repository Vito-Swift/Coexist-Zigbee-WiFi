//
// Created by 黄轩 on 2021/8/12.
//

#include <stdio.h>
#include "CC2520.h"

int main(void){
    unsigned char tx_buf[129];
    unsigned char rx_buf[129];
    unsigned char *buf;
    int i;
    int send_count, receive_count, len;


    CC2520_Init();
    for(i=0; i<129; i++){
        rx_buf[i] = 0;
        tx_buf[i] = 0;
    }

    CC2520_Set_Channel(0, 26);
    CC2520_Set_Channel(1, 26);

    CC2520_Set_TX_Power(0, 5);
    CC2520_Set_TX_Power(1, 5);
    //CC2520_Set_Frame_Filter_PAN_ID(1, 11110);
    //CC2520_Set_Frame_Filter_Short_Addr(1, 22220);
    //CC2520_Frame_Filter_Enable(1, 1);


    IEEE802154_Fill_Data_Frame_Control(tx_buf,
                                       IEEE802154_NO_FRAME_PENDING,
                                       IEEE802154_NO_ACK,
                                       IEEE802154_ADDR_MODE_SHORT_ADDR,
                                       IEEE802154_ADDR_MODE_SHORT_ADDR);
    IEEE802154_Fill_Sequence_Num(tx_buf, 0);
    IEEE802154_Fill_Data_Frame_Short_Addr(tx_buf, 11110, 22220, 33333, 44444);
    buf = IEEE802154_Data_Frame_Get_Payload_Pointer(tx_buf);
    for(i=0; i<114; i++){
        buf[i] = i;  // payload
    }
    IEEE802154_Fill_Data_Frame_PHY_Frame_Len_Field(tx_buf, 114);
    send_count = CC2520_IEEE802154_Data_Frame_Get_SPI_Payload_Len(tx_buf, 114);
    CC2520_Send_Packet_Blocking(1, tx_buf, send_count);
    printf("sending\n");



    while(CC2520_Receive_Packet_Pending(0) == 0);
    receive_count = CC2520_Receive_Packet_Non_Blocking(0, rx_buf);
    printf("receive_count: %d\n", receive_count);
    printf("PHY frame len field: %d\n", IEEE802154_Get_PHY_Frame_Len_Field(rx_buf));
    printf("frame type: %d\n", IEEE802154_Decode_Frame_Control_Frame_Type(rx_buf));
    printf("security enable: %d\n", IEEE802154_Decode_Frame_Control_Security_Enable(rx_buf));
    printf("frame pending: %d\n", IEEE802154_Decode_Frame_Control_Frame_Pending(rx_buf));
    printf("request ack: %d\n", IEEE802154_Decode_Frame_Control_Request_ACK(rx_buf));
    printf("pan id compression: %d\n", IEEE802154_Decode_Frame_Control_PAN_ID_Compression(rx_buf));
    printf("dst addr mode: %d\n", IEEE802154_Decode_Frame_Control_DST_Addr_Mode(rx_buf));
    printf("frame version: %d\n", IEEE802154_Decode_Frame_Control_Frame_Version(rx_buf));
    printf("src addr mode: %d\n", IEEE802154_Decode_Frame_Control_SRC_Addr_Mode(rx_buf));
    printf("seq num: %d\n", IEEE802154_Get_Sequence_Num(rx_buf));
    printf("dst pan id: %d\n", IEEE802154_Get_DST_PAN_ID(rx_buf));
    printf("dst addr: %d\n", IEEE802154_Get_DST_Short_Addr(rx_buf));
    printf("src pan id: %d\n", IEEE802154_Get_SRC_PAN_ID(rx_buf));
    printf("src addr: %d\n", IEEE802154_Get_SRC_Short_Addr(rx_buf));
    buf = IEEE802154_Data_Frame_Get_Payload_Pointer(rx_buf);
    len = IEEE802154_Get_Data_Frame_Payload_Len(rx_buf);
    for(i=0; i<len; i++){
        printf("%d\n", buf[i]);
    }
    printf("CRC correct? %d\n", CC2520_CRC_Correct(rx_buf, receive_count));


    return 0;
}

