//
// Created by 黄轩 on 2021/8/11.
//

#ifndef ZIGBEETESTBED_WISE_H
#define ZIGBEETESTBED_WISE_H

#include <CC2520_Helper.h>

#define TX_DEV 0
#define RX_DEV 1

void WISE_Send(unsigned char* buf, unsigned char buf_len, CC2520_addr_t *addr);
unsigned char WISE_Recv(unsigned char* buf);

unsigned char WISE_Get_Session_ID(unsigned char* buf);
unsigned char WISE_Get_Start_Delimiter(unsigned char* buf);
unsigned char WISE_Get_End_Delimiter(unsigned char* buf);
void WISE_Fill_Hdr(unsigned char* buf, unsigned char session_id, unsigned char start_del, unsigned end_del);
unsigned char* WISE_Get_Payload(unsigned char* buf);

#endif //ZIGBEETESTBED_WISE_H
