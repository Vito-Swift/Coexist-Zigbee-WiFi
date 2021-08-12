//
// Created by 黄轩 on 2021/8/11.
//


// WISE packet | 1 byte Instruction | 1 byte PHY len | 1 byte WISE hdr | payload |
// WISE header | 6 bit session id | 1 bit start delimiter | 1 bit end delimiter |

unsigned char WISE_Get_Session_ID(unsigned char* buf) {
    return buf[2] >> 2;
}

unsigned char WISE_Get_Start_Session_Delimiter(unsigned char* buf) {
    return (buf[2] & (1 << 1)) >> 1;
}

unsigned char WISE_Get_End_Session_Delimiter(unsigned char* buf) {
    return buf[2] & (1 << 0);
}

void WISE_Fill_Hdr(unsigned char* buf, unsigned char session_id, unsigned char start_del, unsigned end_del) {
    buf[2] = (session_id << 2) | (start_del << 1) | (end_del << 0);
}

unsigned char* WISE_Get_Payload(unsigned char* buf) {
    return buf+3;
}

void WISE_Fill_PHY_Frame_Len(unsigned char* buf, int len) {
    buf[1] = 1+len+2;
}

unsigned char WISE_Get_SPI_Payload_Len(unsigned char* buf, int len) {
    return 1+1+len;
}

unsigned char WISE_Get_Data_Frame_Payload_Len(unsigned char* buf) {
    return buf[1]-1-2;
}