//
// Created by Vito Wu on 31/10/2021.
//

#include <cmath>
#include <cstring>
#include "LEAD.hh"

#define max_block_len (4096UL)

void LEAD_send(LEAD_DM *dm,
               uint16_t plen,
               uint8_t *pbuffer,
               CC2520_addr_t *addr) {
    printf("[%s] invoked\n", __func__);
    uint16_t packet_len = plen;
    unsigned char tx_buf[129] = {0};

    // resize convolution code
    size_t enclen = correct_convolutional_encode_len(dm->conv, packet_len);
    size_t enclen_bytes = (enclen % 8) ? (enclen / 8 + 1) : enclen / 8;
    auto encoded_packet = (uint8_t *) malloc(enclen_bytes);
    printf("[%s] resize encoded length (in bytes): %d\n", __func__, enclen_bytes);

    // convolution encode on packet buffer
    correct_convolutional_encode(dm->conv, pbuffer, packet_len, encoded_packet);
    printf("[%s] encode packet is generated\n", __func__);

    // fill-in headers and packet frame
    IEEE802154_Fill_Data_Frame_Control(tx_buf,
                                       IEEE802154_NO_FRAME_PENDING,
                                       IEEE802154_NO_ACK,
                                       IEEE802154_ADDR_MODE_SHORT_ADDR,
                                       IEEE802154_ADDR_MODE_SHORT_ADDR);
    IEEE802154_Fill_Data_Frame_Short_Addr(tx_buf, addr->dst_pan_id, addr->dst_addr,
                                          addr->src_pan_id, addr->src_addr);
    uint8_t *buf = IEEE802154_Data_Frame_Get_Payload_Pointer(tx_buf);
    memcpy(buf, encoded_packet, enclen_bytes);
    IEEE802154_Fill_Data_Frame_PHY_Frame_Len_Field(tx_buf, 114);
    int send_count = CC2520_IEEE802154_Data_Frame_Get_SPI_Payload_Len(tx_buf, 114);

    // send
    CC2520_Send_Packet_Blocking(dm->dev_id, encoded_packet, send_count);
    printf("[%s] TX!\n", __func__);
}