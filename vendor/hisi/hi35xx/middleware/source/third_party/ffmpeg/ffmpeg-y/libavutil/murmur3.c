#include <stdint.h>
#include "mem.h"
#include "intreadwrite.h"
#include "murmur3.h"
typedef struct AVMurMur3 {
    uint64_t h1, h2;
    uint8_t state[16];
    int state_pos;
    uint64_t len;
} AVMurMur3;
#define ROT(a, b) (((a) << (b)) | ((a) >> (64 - (b))))
#if FF_API_CRYPTO_SIZE_T
#else
#endif
