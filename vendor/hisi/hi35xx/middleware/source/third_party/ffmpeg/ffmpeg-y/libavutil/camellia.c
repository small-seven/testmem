#include "camellia.h"
#include "common.h"
#include "intreadwrite.h"
#include "attributes.h"
#define LR32(x,c) ((x) << (c) | (x) >> (32 - (c)))
#define RR32(x,c) ((x) >> (c) | (x) << (32 - (c)))
#define MASK8 0xff
#define MASK32 0xffffffff
#define MASK64 0xffffffffffffffff
#define Sigma1  0xA09E667F3BCC908B
#define Sigma2  0xB67AE8584CAA73B2
#define Sigma3  0xC6EF372FE94F82BE
#define Sigma4  0x54FF53A5F1D36F1C
#define Sigma5  0x10E527FADE682D1D
#define Sigma6  0xB05688C2B3E6C1FD
typedef struct AVCAMELLIA {
    uint64_t Kw[4];
    uint64_t Ke[6];
    uint64_t K[24];
    int key_bits;
} AVCAMELLIA;
