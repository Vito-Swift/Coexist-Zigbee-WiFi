//
// Created by 黄轩 on 2021/8/11.
//

#include <WISE.h>
#include <string.h>
#include <time.h>

unsigned char get_subframe_size() {
    return 20;
}

void WISE_Send(unsigned char* buf, unsigned char buf_len, CC2520_addr_t *addr) {
//    Normal zigbee TX process
    unsigned char mac_hdr[13] = {0};
    unsigned char hdr_len = 11;
    IEEE802154_Fill_Data_Frame_Control(mac_hdr,
                                       IEEE802154_NO_FRAME_PENDING,
                                       IEEE802154_NO_ACK,
                                       IEEE802154_ADDR_MODE_SHORT_ADDR,
                                       IEEE802154_ADDR_MODE_SHORT_ADDR);
    IEEE802154_Fill_Sequence_Num(mac_hdr, 0);
    IEEE802154_Fill_Data_Frame_Short_Addr(mac_hdr,
                                          addr->dst_pan_id,
                                          addr->dst_addr,
                                          addr->src_pan_id,
                                          addr->src_addr);

//    WISE start
    srand(time(NULL));
    unsigned char session_id = rand() % 0x40;
    unsigned char size;
//    TODO: need timeout of one transmission

    // session registration frame
    WISE_Fill_Hdr(mac_hdr, session_id, 1, 0);
    while (1) {
        size = get_subframe_size();
        if (size >= hdr_len+2) {
            CC2520_Send_Packet_Blocking(TX_DEV, mac_hdr, hdr_len+1);
            break;
        }
    }
    // payload sub-frame
    unsigned char total_size = 0;
    unsigned char sub_frame[129];
    unsigned char* payload = WISE_Get_Payload(sub_frame);
    while (1) {
        size = get_subframe_size();
        if (total_size+size-2 > buf_len) {
            size = buf_len - total_size + 2;
            memcpy(payload, buf+total_size, size-2);
            WISE_Fill_Hdr(sub_frame, session_id, 0, 1);
            CC2520_Send_Packet_Blocking(TX_DEV, sub_frame, size-1);
            break;
        }
        memcpy(payload, buf+total_size, size-2);
        WISE_Fill_Hdr(sub_frame, session_id, 0, 0);
        CC2520_Send_Packet_Blocking(TX_DEV, sub_frame, size-1);
        total_size += size - 2;
    }
}