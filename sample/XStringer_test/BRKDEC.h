#ifndef BRKDEC
#define BRKDEC

#include <intrin.h>
#include <cstdint>

constexpr unsigned long long const_hash(const char* input) {
    return *input ? static_cast<unsigned long long>(*input) + 33 * const_hash(input + 1) : 5381;
}

#define BRKDEC_RANDOM (const_hash(__DATE__ __TIME__) + __COUNTER__ * __LINE__)

#define BRKDEC_OBFUSCATE \
{ \
    volatile unsigned char BRKDEC_STUB[31]; \
    BRKDEC_STUB[0] = 0xEB; \
    BRKDEC_STUB[1] = 0x08; \
    BRKDEC_STUB[2] = 0x48; \
    BRKDEC_STUB[3] = 0x89; \
    BRKDEC_STUB[4] = 0x8C; \
    BRKDEC_STUB[5] = 0x24; \
    BRKDEC_STUB[6] = (unsigned char)((BRKDEC_RANDOM >> 0) & 0xFF); \
    BRKDEC_STUB[7] = (unsigned char)((BRKDEC_RANDOM >> 8) & 0xFF); \
    BRKDEC_STUB[8] = (unsigned char)((BRKDEC_RANDOM >> 16) & 0xFF); \
    BRKDEC_STUB[9] = (unsigned char)((BRKDEC_RANDOM >> 24) & 0xFF); \
    BRKDEC_STUB[10] = 0xC3; \
    BRKDEC_STUB[11] = (unsigned char)((BRKDEC_RANDOM + 1) & 0xFF); \
    BRKDEC_STUB[12] = (unsigned char)((BRKDEC_RANDOM + 2) & 0xFF); \
    BRKDEC_STUB[13] = 0xEB; \
    BRKDEC_STUB[14] = 0x08; \
    BRKDEC_STUB[15] = 0x48; \
    BRKDEC_STUB[16] = 0x89; \
    BRKDEC_STUB[17] = 0x8C; \
    BRKDEC_STUB[18] = 0x24; \
    BRKDEC_STUB[19] = (unsigned char)((BRKDEC_RANDOM >> 0) & 0xFF); \
    BRKDEC_STUB[20] = (unsigned char)((BRKDEC_RANDOM >> 8) & 0xFF); \
    BRKDEC_STUB[21] = 0xC3; \
    BRKDEC_STUB[22] = (unsigned char)((BRKDEC_RANDOM + 3) & 0xFF); \
    BRKDEC_STUB[23] = (unsigned char)((BRKDEC_RANDOM + 4) & 0xFF); \
    BRKDEC_STUB[24] = 0xEB; \
    BRKDEC_STUB[25] = 0x08; \
    BRKDEC_STUB[26] = 0x48; \
    BRKDEC_STUB[27] = 0x89; \
    BRKDEC_STUB[28] = 0x8C; \
    BRKDEC_STUB[29] = 0x24; \
    BRKDEC_STUB[30] = (unsigned char)((BRKDEC_RANDOM >> 16) & 0xFF); \
    if (_AddressOfReturnAddress() == 0) { \
        ((void(*)(void))(uintptr_t)(BRKDEC_STUB))(); \
    } \
}

#define BRKDEC_STACK \
{ \
    volatile unsigned long long BRKDEC_FAKE_RET[6]; \
    BRKDEC_FAKE_RET[0] = BRKDEC_RANDOM; \
    BRKDEC_FAKE_RET[1] = BRKDEC_RANDOM + __COUNTER__; \
    BRKDEC_FAKE_RET[2] = BRKDEC_RANDOM ^ 0xDEADBEEF; \
    BRKDEC_FAKE_RET[3] = (BRKDEC_RANDOM >> 16) | (BRKDEC_RANDOM << 16); \
    BRKDEC_FAKE_RET[4] = BRKDEC_RANDOM * __COUNTER__; \
    BRKDEC_FAKE_RET[5] = (unsigned long long)_AddressOfReturnAddress(); \
    if (BRKDEC_FAKE_RET[0] > 0) { \
        BRKDEC_FAKE_RET[0] = BRKDEC_FAKE_RET[1] - BRKDEC_FAKE_RET[0]; \
    } \
}

#define BRKDEC_JUMP \
{ \
    volatile int BRKDEC_X = (int)(BRKDEC_RANDOM % 6); \
    switch(BRKDEC_X) { \
        case 0: break; \
        case 1: break; \
        case 2: break; \
        case 3: break; \
        case 4: break; \
        case 5: break; \
        default: break; \
    } \
}

#define BRKDEC_DATA \
{ \
    volatile unsigned char BRKDEC_DATA[10]; \
    for (int i = 0; i < 10; i++) { \
        BRKDEC_DATA[i] = (unsigned char)((BRKDEC_RANDOM >> (i * 4)) & 0xFF); \
    } \
    volatile unsigned char* BRKDEC_PTR = BRKDEC_DATA; \
    for (int i = 0; i < 10; i++) { \
        BRKDEC_PTR[i] ^= (unsigned char)((BRKDEC_RANDOM >> (i * 2)) & 0xFF); \
    } \
}

#define BRKDEC_CRASH \
{ \
    volatile unsigned long long BRKDEC_FAKE_FUNC[10]; \
    for (int BRKDEC_j = 0; BRKDEC_j < 10; BRKDEC_j++) { \
        BRKDEC_FAKE_FUNC[BRKDEC_j] = BRKDEC_RANDOM + BRKDEC_j; \
    } \
    volatile unsigned long long* BRKDEC_FUNC_PTR = BRKDEC_FAKE_FUNC; \
    BRKDEC_FUNC_PTR += (BRKDEC_RANDOM % 5); \
    if (_AddressOfReturnAddress() == 0) { \
        ((void(*)(void))(*BRKDEC_FUNC_PTR))(); \
    } \
}

#define BRKDEC \
{ \
    BRKDEC_OBFUSCATE; \
    BRKDEC_STACK; \
    BRKDEC_JUMP; \
    BRKDEC_DATA; \
    BRKDEC_CRASH; \
}

#endif