/**
 * @author: vitowu
 * @email: vitow@nvidia.com
 * @date: 2/9/2021 
 */

#include <WISE.h>

#include "unistd.h"

unsigned int max_throughput;
unsigned int packet_per_sec;
unsigned int sleep_in_us;
unsigned int testing_duration = 20;     // lasting 20 seconds to benchmark the tx/rx

//void WISE_tx(WISE_Params *params) {
//    CC2520_addr_t addr;
//    unsigned char tx_buf[50] = {0};
//    addr.dst_pan_id = 11110;
//    addr.dst_addr = 22220;
//    addr.src_pan_id = 33333;
//    addr.src_addr = 44444;
//    for (int i = 0; i < 40; i++)
//    {
//        tx_buf[i] = '0' + (i % 10);
//    }
//    WISE_Send(params, tx_buf, 40, &addr);
//}
//
//unsigned int WISE_rx(unsigned char *rx_buf) {
//    int len = WISE_Recv(rx_buf);
//    return len;
//}

void tx() {
    unsigned char tx_buf[129] = {0};
    IEEE802154_Fill_Data_Frame_Control(tx_buf,
                                       IEEE802154_NO_FRAME_PENDING,
                                       IEEE802154_NO_ACK,
                                       IEEE802154_ADDR_MODE_SHORT_ADDR,
                                       IEEE802154_ADDR_MODE_SHORT_ADDR);
    IEEE802154_Fill_Sequence_Num(tx_buf, 0);
    IEEE802154_Fill_Data_Frame_Short_Addr(tx_buf, 11110, 22220, 33333, 44444);
    unsigned char *buf = IEEE802154_Data_Frame_Get_Payload_Pointer(tx_buf);
    for (int i = 0; i < 40; i++)
    {
        buf[i] = '0' + (i % 10);
    }
    IEEE802154_Fill_Data_Frame_PHY_Frame_Len_Field(tx_buf, 60);
    int send_count = CC2520_IEEE802154_Data_Frame_Get_SPI_Payload_Len(tx_buf, 60);
    CC2520_Send_Packet_Blocking(0, tx_buf, send_count);
}

unsigned int rx() {
    unsigned char rx_buf[129];
    unsigned char *buf;
    while (CC2520_Receive_Packet_Pending(1) == 0);
    int recv_count = CC2520_Receive_Packet_Non_Blocking(1, rx_buf);
    buf = IEEE802154_Data_Frame_Get_Payload_Pointer(rx_buf);
    for (int i = 0; i < 40; i++)
    {
        if (buf[i] != '0' + (i % 10)) // message error
            return 0;
    }
    return 60;
}

int main(int argc, char *argv[]) {
    CC2520_Init();

    max_throughput = 10 * 1024; // 10 KBps
    packet_per_sec = max_throughput / 60;
    sleep_in_us = 1000000 / packet_per_sec;
    // if packet interval is larger than 2000, keep it as sending rate (spare 10 us)
    // if packet interval is not larger than 20, sleep 1000 us for each packet send;
//    sleep_in_us = sleep_in_us > 3000 ? sleep_in_us - 3500 : 500;
    sleep_in_us = 250;
    printf("Testing Throughput: %d Kbps\n", max_throughput / 1024);
    printf("Sending Interval: %d us\n", sleep_in_us);

    if (argc < 2)
    {
        printf("Error: please specify the sender or receiver by providing '0' or '1' in startup\n");
        return 1;
    }

    if (argv[1][0] == '0')
    {
        printf("========Benchmark sender program========\n");
        CC2520_Set_Channel(0, 11);
        CC2520_Set_TX_Power(0, 5);

        time_t start_time = time(NULL);
        if (argv[2][0] == '0')
        {
            printf("Original CC2520 Sending...... \n");
            int send_count = 0;
            while (time(NULL) - start_time < testing_duration)
            {
                tx();
                usleep(sleep_in_us);
                send_count++;
            }
            printf("Send finished\n");
            printf("Statistics: \n");
            printf("\tTotal Sent Packet: %d\n", send_count);
            printf("\tTotal Sent Size: %lf Kbits\n", (double) send_count * 60 * 8 / (1024));
            printf("\tThroughput: %lf Kbps\n", (double) send_count * 60 * 8 / (1024 * testing_duration));
        } else
        {
            printf("WISE CC2520 Send: \n");
        }

    }
    if (argv[1][0] == '1')
    {
        printf("========Benchmark receiver program========\n");
        time_t start_time = time(NULL);
        CC2520_Set_Channel(1, 11);
        CC2520_Set_TX_Power(1, 5);

        if (argv[2][0] == '0')
        {
            printf("Original CC2520 Receiving......\n");
            int recv_count = 0;
            while (time(NULL) - start_time + 2 < testing_duration)
            {
                recv_count += rx();
            }
            printf("Recv finished\n");
            printf("Statistics: \n");
            printf("\tTotal Received Size: %lf Kbits\n", (double) recv_count * 8 / 1024);
            printf("\tThroughput: %lf kbps\n", (double) recv_count * 8 / (1024 * testing_duration));
        } else
        {
            printf("WISE CC2520 Recv: \n");
        }

    }
//    WISE_Params params;
//    WISE_Init(&params, 50, 1, 200);
//    if (argc < 2)
//    {
//        printf("Error: please specify the sender or receiver by providing '0' or '1' in startup\n");
//    } else if (argv[1][0] == '0')
//    {
//        CC2520_Set_Channel(0, 11);
//        CC2520_Set_TX_Power(0, 5);
//        CC2520_Set_Channel(1, 11);
//        CC2520_Set_TX_Power(1, 5);
//        WISE_tx(&params);
//    } else if (argv[1][0] == '1')
//    {
//        unsigned char rx_buf[50] = {0};
//        CC2520_Set_Channel(0, 11);
//        CC2520_Set_TX_Power(0, 5);
//        CC2520_Set_Channel(1, 11);
//        CC2520_Set_TX_Power(1, 5);
//        WISE_rx(rx_buf);
//    }
    return 0;
}