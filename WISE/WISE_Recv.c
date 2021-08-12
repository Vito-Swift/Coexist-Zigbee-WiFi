//
// Created by 黄轩 on 2021/8/11.
//

#include <WISE.h>
#include <string.h>

unsigned char WISE_Recv(unsigned char* buf) {
    unsigned char sub_frame[129];
    unsigned char size, total_size = 0;
    unsigned char* payload = WISE_Get_Payload(sub_frame);
    unsigned char session_id;
    unsigned char receive_count;

//    TODO: add timeout
    while (1) {
        receive_count = CC2520_Receive_Packet_Blocking(RX_DEV, sub_frame);
        if (WISE_Get_Start_Session_Delimiter(sub_frame)) {
            // TODO: Check addr validation
            CC2520_addr_t addr;
            addr.dst_addr = IEEE802154_Get_DST_Short_Addr(sub_frame);
            addr.dst_pan_id = IEEE802154_Get_DST_PAN_ID(sub_frame);
            addr.src_addr = IEEE802154_Get_SRC_Short_Addr(sub_frame);
            addr.src_pan_id = IEEE802154_Get_SRC_PAN_ID(sub_frame);
            session_id = WISE_Get_Session_ID(sub_frame);
            break;
        }
    }

    while (1) {
        receive_count = CC2520_Receive_Packet_Blocking(RX_DEV, sub_frame);
        size = WISE_Get_Data_Frame_Payload_Len(sub_frame);
        if (WISE_Get_Session_ID(sub_frame) != session_id) {
            perror("Session ID not the same\n");
            return -1;
        }
        memcpy(buf+total_size, payload, size);
        total_size += size;
        if (WISE_Get_End_Session_Delimiter(sub_frame) == 1) {
            break;
        }
    }
    return total_size;
}