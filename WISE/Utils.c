//
// Created by 黄轩 on 2021/8/11.
//


//| Instruction | 6 bit session id | 1 bit start delimiter | 1 bit end delimiter | MAC hdr | payload |

unsigned char WISE_Get_Session_ID(unsigned char* buf) {
    return buf[1] >> 2;
}

unsigned char WISE_Get_Start_Delimiter(unsigned char* buf) {
    return buf[1] & (1 << 1);
}

unsigned char WISE_Get_End_Delimiter(unsigned char* buf) {
    return buf[1] & (1 << 0);
}

void WISE_Fill_Hdr(unsigned char* buf, unsigned char session_id, unsigned char start_del, unsigned end_del) {
    buf[1] = (session_id << 2) | (start_del << 1) | (end_del << 0);
}

unsigned char* WISE_Get_Payload(unsigned char* buf) {
    return buf+2;
}