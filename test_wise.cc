//
// Created by 黄轩 on 2021/8/12.
//

#include <WISE.h>
#include <string.h>

void tx(WISE_Params *params) {
    CC2520_addr_t addr;
    unsigned char tx_buf[50];
    addr.dst_pan_id = 11110;
    addr.dst_addr = 22220;
    addr.src_pan_id = 33333;
    addr.src_addr = 44444;
    for (int i = 0; i < 40; i++)
    {
        tx_buf[i] = '0' + (i % 10);
    }
    WISE_Send(params, tx_buf, 40, &addr);
    printf("sending\n");
}

void rx() {
    unsigned char rx_buf[50] = {0};
    int len = WISE_Recv(rx_buf);
    printf("receiving: %s\n", rx_buf);
}

int main(int argc, char *argv[]) {
    CC2520_Init();
    WISE_Params params;
//    WISE_Init(&params, 50, 1, 200);
    if (argc == 1)
    {
        CC2520_Set_Channel(0, 26);
        CC2520_Set_TX_Power(0, 5);
        CC2520_Set_Channel(1, 26);
        CC2520_Set_TX_Power(1, 5);
        tx(&params);
        rx();
    } else if (argv[1][0] == '0')
    {
        CC2520_Set_Channel(0, 26);
        CC2520_Set_TX_Power(0, 5);
        CC2520_Set_Channel(1, 26);
        CC2520_Set_TX_Power(1, 5);
        tx(&params);
    } else if (argv[1][0] == '1')
    {
        CC2520_Set_Channel(0, 26);
        CC2520_Set_TX_Power(0, 5);
        CC2520_Set_Channel(1, 26);
        CC2520_Set_TX_Power(1, 5);
        rx();
    }
    return 0;
}