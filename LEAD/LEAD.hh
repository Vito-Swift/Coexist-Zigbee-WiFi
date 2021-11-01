//
// Created by Vito Wu on 31/10/2021.
//

#ifndef ZIGBEETESTBED_LEAD_HH
#define ZIGBEETESTBED_LEAD_HH

#include <correct.h>
#include <CC2520_Helper.h>

struct LEAD_DM {
    correct_convolutional *conv;
    int dev_id;
};


inline void LEAD_init(LEAD_DM *dm, size_t inv_rate, int dev_id) {
    dm->conv = correct_convolutional_create(inv_rate, 7, correct_conv_r12_6_polynomial);
    dm->dev_id = dev_id;
    CC2520_Init();
    CC2520_Set_Channel(dev_id, 11);
    CC2520_Set_TX_Power(dev_id, 5);
    printf("[%s] conv rate: %d, dev id: %d\n", __func__, inv_rate, dev_id);
}

inline void LEAD_destroy(LEAD_DM *dm) {
    correct_convolutional_destroy(dm->conv);
    printf("[%s] interface is released\n", __func__);
}

void LEAD_send(LEAD_DM *dm, uint16_t plen, uint8_t *pbuffer, CC2520_addr_t *addr);

int32_t LEAD_recv(LEAD_DM *dm, uint8_t *pbuffer, CC2520_addr_t *addr);

#endif //ZIGBEETESTBED_LEAD_HH
