//
// Created by 黄轩 on 2021/8/12.
//

#include <WISE.h>
#include <string.h>

int main() {
    CC2520_Init();
    CC2520_Set_Channel(0, 26);
    CC2520_Set_Channel(1, 26);
    CC2520_Set_TX_Power(0, 5);
    CC2520_Set_TX_Power(1, 5);

    CC2520_addr_t addr;
    unsigned char tx_buf[15] = "hello world";
    WISE_Send(tx_buf, strlen(tx_buf), &addr);

    printf("sending\n");

    unsigned char rx_buf[15];
    int len = WISE_Recv(rx_buf);

    printf("%s\n", rx_buf);

    return 0;
}