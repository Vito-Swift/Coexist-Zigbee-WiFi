//
// Created by 黄轩 on 2021/8/11.
//

#ifndef ZIGBEETESTBED_WISE_H
#define ZIGBEETESTBED_WISE_H

#include <CC2520_Helper.h>
#include <../cca_utils/cca_utils.h>

#define TX_DEV 0
#define RX_DEV 1

// max channel rate of IEEE802154 is 250kbps
const unsigned int channel_rate = 250;
typedef struct {
    struct cca_stat ccaStat;
    float presto_lambda;     // mean in the Pareto model of the white space
    unsigned int T;          //  preset appropriate T value to pass the K-S test
    unsigned int alpha;
} WISE_Params;

inline void WISE_Init(struct WISE_Params *params,
                      unsigned int T,
                      unsigned int alpha,
                      unsigned int sample_freq) {
    params->alpha = alpha;
    detach_cca_sampling(params->ccaStat, sample_freq, T);
}

inline void WISE_Exit(struct WISE_Params *params) {
    stop_cca_sampling(&params->ccaStat);
}

void WISE_Send(struct WISE_Params *params, unsigned char *buf, unsigned char buf_len, CC2520_addr_t *addr);

unsigned char WISE_Recv(unsigned char *buf);

unsigned char WISE_Get_Session_ID(unsigned char *buf);

unsigned char WISE_Get_Start_Session_Delimiter(unsigned char *buf);

unsigned char WISE_Get_End_Session_Delimiter(unsigned char *buf);

void WISE_Fill_Hdr(unsigned char *buf, unsigned char session_id, unsigned char start_del, unsigned end_del);

unsigned char *WISE_Get_Payload(unsigned char *buf);

void WISE_Fill_PHY_Frame_Len(unsigned char *buf, int len);

unsigned char WISE_Get_SPI_Payload_Len(unsigned char *buf, int len);

unsigned char WISE_Get_Data_Frame_Payload_Len(unsigned char *buf);

#endif //ZIGBEETESTBED_WISE_H
