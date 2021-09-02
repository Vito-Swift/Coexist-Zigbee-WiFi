//
// Created by 黄轩 on 2021/8/11.
//

#include <WISE.h>
#include <string.h>
#include <time.h>
#include <math.h>

unsigned char get_subframe_size(WISE_Params *params, unsigned char buf_len) {
    if (CC2520_Get_CCA(TX_DEV))
    {
        // unit in ms
        float avg_whitespace_age = get_avg_whitespace_age_in_window(&params->ccaStat);
        // unit in ms
        float current_whitespace_age = get_whitespace_age_usec(&params->ccaStat) * 1000;
        int opt_subframe_size =
            floor(current_whitespace_age * channel_rate *
                ((pow(1 - params->T, -1 * (avg_whitespace_age - params->alpha) / avg_whitespace_age)) - 1));
        return opt_subframe_size > buf_len ? buf_len : opt_subframe_size;
    }
    return 0;
}

void WISE_Send(WISE_Params *params, unsigned char *buf, unsigned char buf_len, CC2520_addr_t *addr) {
//    Normal zigbee TX process
    unsigned char mac_hdr[129] = {0};
    unsigned char hdr_len = 11;
    IEEE802154_Fill_Data_Frame_Control(mac_hdr + 1,
                                       IEEE802154_NO_FRAME_PENDING,
                                       IEEE802154_NO_ACK,
                                       IEEE802154_ADDR_MODE_SHORT_ADDR,
                                       IEEE802154_ADDR_MODE_SHORT_ADDR);
    IEEE802154_Fill_Sequence_Num(mac_hdr + 1, 0);
    IEEE802154_Fill_Data_Frame_Short_Addr(mac_hdr + 1,
                                          addr->dst_pan_id,
                                          addr->dst_addr,
                                          addr->src_pan_id,
                                          addr->src_addr);

//    WISE start
    srand(time(NULL));
    unsigned char session_id = rand() % 0x40;
    unsigned char size;
    unsigned char send_count;
//    TODO: need timeout of one transmission

    // session registration frame
    WISE_Fill_Hdr(mac_hdr, session_id, 1, 0);
    WISE_Fill_PHY_Frame_Len(mac_hdr, hdr_len);
    send_count = WISE_Get_SPI_Payload_Len(mac_hdr, hdr_len);
    while (1)
    {
        size = get_subframe_size(params, buf_len);
        if (size >= hdr_len)
        {
            CC2520_Send_Packet_Blocking(TX_DEV, mac_hdr, send_count);
//            printf("[DEBUG] send srf\n");
            break;
        }
    }

    // payload sub-frame
    unsigned char total_size = 0;
    unsigned char sub_frame[129];
    unsigned char *payload = WISE_Get_Payload(sub_frame);
    while (1)
    {
        size = get_subframe_size(params, buf_len);
        if (size <= 0) continue;
        if (total_size + size >= buf_len)
        {
            size = buf_len - total_size;
            memcpy(payload, buf + total_size, size);
            WISE_Fill_Hdr(sub_frame, session_id, 0, 1);
            WISE_Fill_PHY_Frame_Len(sub_frame, size);
            send_count = WISE_Get_SPI_Payload_Len(sub_frame, size);
            CC2520_Send_Packet_Blocking(TX_DEV, sub_frame, send_count);
            break;
        }
        memcpy(payload, buf + total_size, size);
        WISE_Fill_Hdr(sub_frame, session_id, 0, 0);
        WISE_Fill_PHY_Frame_Len(sub_frame, size);
        send_count = WISE_Get_SPI_Payload_Len(sub_frame, size);
        CC2520_Send_Packet_Blocking(TX_DEV, sub_frame, send_count);
        total_size += size;
    }
}