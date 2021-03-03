#include "twofish.h"
#include "common.h"
#include "intreadwrite.h"
#include "attributes.h"
#define LR(x, n) ((x) << (n) | (x) >> (32 - (n)))
#define RR(x, n) ((x) >> (n) | (x) << (32 - (n)))
typedef struct AVTWOFISH {
    uint32_t K[40];
    uint32_t S[4];
    int ksize;
    uint32_t MDS1[256];
    uint32_t MDS2[256];
    uint32_t MDS3[256];
    uint32_t MDS4[256];
} AVTWOFISH;
