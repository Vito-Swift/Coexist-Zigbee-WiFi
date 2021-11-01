//
// Created by Vito Wu on 31/10/2021.
//

#include <cmath>
#include <cstring>
#include "LEAD.hh"

// return 0 if decode fail; otherwise decode successful
uint8_t CC2520_Recv_Decode_Finalization(int dev_id) {
    unsigned int exc_word = CC2520_Read_Exception(dev_id);
    if (CC2520_Decode_Exception(exc_word, CC2520_EXC_RX_OVERFLOW)) {
        printf("[%s] decode exception: CC2520_EXC_RX_OVERFLOW\n", __func__);
        CC2520_Instruction(dev_id, CC2520_INS_SFLUSHRX);
        CC2520_Instruction(dev_id, CC2520_INS_SRFOFF);
        CC2520_Instruction(dev_id, CC2520_INS_SRXON);
        CC2520_Clear_Exception(dev_id, CC2520_EXC_RX_OVERFLOW);
        return 0;
    }
    return 1;
}

// return -1 if decode fail or CRC incorrect;
// otherwise return the length of received frame (in bytes)
int32_t LEAD_recv(LEAD_DM *dm, uint8_t *pbuf) {
    int32_t recvlen;
    unsigned char rx_buf[129] = {0};
    unsigned char *buf;
    unsigned int exc_word;
    while (CC2520_Receive_Packet_Pending(1) == 0) {
        if (!CC2520_Recv_Decode_Finalization(dm->dev_id))
            return -1;
    }
    if (!CC2520_Recv_Decode_Finalization(dm->dev_id))
        return -1;

    int recv_count = CC2520_Receive_Packet_Non_Blocking(dm->dev_id, rx_buf);
    int recv_body_len = IEEE802154_Get_Data_Frame_Payload_Len(rx_buf);
    if (!CC2520_CRC_Correct(rx_buf, recv_count))
        return -1;

    return recvlen;
}