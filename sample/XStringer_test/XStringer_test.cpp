#include <stdio.h>
#include "BRKDEC.h"
// XOR Key: ['0x48', '0x7e', '0x48', '0x29', '0x3f', '0x41', '0x46', '0x23', '0x38', '0x7a', '0x5d', '0x39', '0x4b', '0x41', '0x49', '0xc', '0x34']
volatile unsigned char sEtwEventWriteFull[18];
void init_sEtwEventWriteFull() {
    BRKDEC;
    volatile unsigned char sEtwEventWriteFull_0, sEtwEventWriteFull_1, sEtwEventWriteFull_2, sEtwEventWriteFull_3, sEtwEventWriteFull_4, 
        sEtwEventWriteFull_5, sEtwEventWriteFull_6, sEtwEventWriteFull_7, sEtwEventWriteFull_8, sEtwEventWriteFull_9, sEtwEventWriteFull_10, 
        sEtwEventWriteFull_11, sEtwEventWriteFull_12, sEtwEventWriteFull_13, sEtwEventWriteFull_14, sEtwEventWriteFull_15, sEtwEventWriteFull_16;
    volatile unsigned char sEtwEventWriteFull_0_xor, sEtwEventWriteFull_1_xor, sEtwEventWriteFull_2_xor, sEtwEventWriteFull_3_xor, 
        sEtwEventWriteFull_4_xor, sEtwEventWriteFull_5_xor, sEtwEventWriteFull_6_xor, sEtwEventWriteFull_7_xor, sEtwEventWriteFull_8_xor, 
        sEtwEventWriteFull_9_xor, sEtwEventWriteFull_10_xor, sEtwEventWriteFull_11_xor, sEtwEventWriteFull_12_xor, sEtwEventWriteFull_13_xor, 
        sEtwEventWriteFull_14_xor, sEtwEventWriteFull_15_xor, sEtwEventWriteFull_16_xor;

    for (int i = 0; i < 17; i++) {
        switch (i) {
        case 0:  BRKDEC; sEtwEventWriteFull_9 = 0x8; sEtwEventWriteFull_9_xor = sEtwEventWriteFull_9 + 0xa; sEtwEventWriteFull[9] = sEtwEventWriteFull_9 ^ (sEtwEventWriteFull_9_xor ^ 0x68); break;
        case 1:  BRKDEC; sEtwEventWriteFull_8 = 0x6f; sEtwEventWriteFull_8_xor = sEtwEventWriteFull_8 - 0x46; sEtwEventWriteFull[8] = sEtwEventWriteFull_8 ^ (sEtwEventWriteFull_8_xor ^ 0x11); break;
        case 2:  BRKDEC; sEtwEventWriteFull_13 = 0x7; sEtwEventWriteFull_13_xor = sEtwEventWriteFull_13 - 0x6; sEtwEventWriteFull[13] = sEtwEventWriteFull_13 ^ (sEtwEventWriteFull_13_xor ^ 0x40); break;
        case 3:  BRKDEC; sEtwEventWriteFull_1 = 0xa; sEtwEventWriteFull_1_xor = sEtwEventWriteFull_1 + 0xe; sEtwEventWriteFull[1] = sEtwEventWriteFull_1 ^ (sEtwEventWriteFull_1_xor ^ 0x66); break;
        case 4:  BRKDEC; sEtwEventWriteFull_15 = 0x60; sEtwEventWriteFull_15_xor = sEtwEventWriteFull_15 - 0x59; sEtwEventWriteFull[15] = sEtwEventWriteFull_15 ^ (sEtwEventWriteFull_15_xor ^ 0xb); break;
        case 5:  BRKDEC; sEtwEventWriteFull_11 = 0x4d; sEtwEventWriteFull_11_xor = sEtwEventWriteFull_11 - 0x1b; sEtwEventWriteFull[11] = sEtwEventWriteFull_11 ^ (sEtwEventWriteFull_11_xor ^ 0xb); break;
        case 6:  BRKDEC; sEtwEventWriteFull_3 = 0x6c; sEtwEventWriteFull_3_xor = sEtwEventWriteFull_3 - 0x38; sEtwEventWriteFull[3] = sEtwEventWriteFull_3 ^ (sEtwEventWriteFull_3_xor ^ 0x1d); break;
        case 7:  BRKDEC; sEtwEventWriteFull_10 = 0x34; sEtwEventWriteFull_10_xor = sEtwEventWriteFull_10 + 0x47; sEtwEventWriteFull[10] = sEtwEventWriteFull_10 ^ (sEtwEventWriteFull_10_xor ^ 0x26); break;
        case 8:  BRKDEC; sEtwEventWriteFull_5 = 0x24; sEtwEventWriteFull_5_xor = sEtwEventWriteFull_5 + 0x36; sEtwEventWriteFull[5] = sEtwEventWriteFull_5 ^ (sEtwEventWriteFull_5_xor ^ 0x1b); break;
        case 9:  BRKDEC; sEtwEventWriteFull_4 = 0x49; sEtwEventWriteFull_4_xor = sEtwEventWriteFull_4 - 0x20; sEtwEventWriteFull[4] = sEtwEventWriteFull_4 ^ (sEtwEventWriteFull_4_xor ^ 0x16); break;
        case 10: BRKDEC;  sEtwEventWriteFull_16 = 0x58; sEtwEventWriteFull_16_xor = sEtwEventWriteFull_16 - 0x29; sEtwEventWriteFull[16] = sEtwEventWriteFull_16 ^ (sEtwEventWriteFull_16_xor ^ 0x1b); break;
        case 11: BRKDEC;  sEtwEventWriteFull_14 = 0x3c; sEtwEventWriteFull_14_xor = sEtwEventWriteFull_14 + 0x43; sEtwEventWriteFull[14] = sEtwEventWriteFull_14 ^ (sEtwEventWriteFull_14_xor ^ 0x36); break;
        case 12: BRKDEC;  sEtwEventWriteFull_12 = 0x2e; sEtwEventWriteFull_12_xor = sEtwEventWriteFull_12 + 0x32; sEtwEventWriteFull[12] = sEtwEventWriteFull_12 ^ (sEtwEventWriteFull_12_xor ^ 0x2b); break;
        case 13: BRKDEC;  sEtwEventWriteFull_2 = 0x3f; sEtwEventWriteFull_2_xor = sEtwEventWriteFull_2 + 0x1a; sEtwEventWriteFull[2] = sEtwEventWriteFull_2 ^ (sEtwEventWriteFull_2_xor ^ 0x11); break;
        case 14: BRKDEC;  sEtwEventWriteFull_0 = 0xd; sEtwEventWriteFull_0_xor = sEtwEventWriteFull_0 + 0x51; sEtwEventWriteFull[0] = sEtwEventWriteFull_0 ^ (sEtwEventWriteFull_0_xor ^ 0x16); break;
        case 15: BRKDEC;  sEtwEventWriteFull_7 = 0x57; sEtwEventWriteFull_7_xor = sEtwEventWriteFull_7 - 0x1b; sEtwEventWriteFull[7] = sEtwEventWriteFull_7 ^ (sEtwEventWriteFull_7_xor ^ 0x1f); break;
        case 16: BRKDEC;  sEtwEventWriteFull_6 = 0x28; sEtwEventWriteFull_6_xor = sEtwEventWriteFull_6 + 0x24; sEtwEventWriteFull[6] = sEtwEventWriteFull_6 ^ (sEtwEventWriteFull_6_xor ^ 0xa); break;
        default:
            break;
        }
    }
    sEtwEventWriteFull[17] = 0x0;    
}

int main() {
    init_sEtwEventWriteFull();
    printf((const char*)sEtwEventWriteFull);

    return 0;
}