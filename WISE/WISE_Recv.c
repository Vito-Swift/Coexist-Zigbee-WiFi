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

//    TODO: add timeout
    while (1) {
        size = CC2520_Receive_Packet_Blocking(RX_DEV, sub_frame);
        if (WISE_Get_Start_Delimiter(sub_frame) == 1) {
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
        size = CC2520_Receive_Packet_Blocking(RX_DEV, sub_frame)+1;
        if (WISE_Get_Session_ID(sub_frame) != session_id) {
            perror("Session not the same\n");
            return -1;
        }
        memcpy(buf+total_size, payload, size-2);
        total_size += size-2;
        if (WISE_Get_End_Delimiter(sub_frame) == 1) {
            break;
        }
    }
    return total_size;
}