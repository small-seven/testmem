#include <string.h>
#include "attributes.h"
#include "avutil.h"
#include "bswap.h"
#include "sha.h"
#include "intreadwrite.h"
#include "mem.h"
typedef struct AVSHA {
    uint8_t  digest_len;  ///< digest length in 32-bit words
    uint64_t count;       ///< number of bytes in buffer
    uint8_t  buffer[64];  ///< 512-bit buffer of input values used in hash updating
    uint32_t state[8];    ///< current hash value
    /** function used to update hash for 512-bit input block */
    void     (*transform)(uint32_t *state, const uint8_t buffer[64]);
} AVSHA;
#define rol(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))
#define blk0(i) (block[i] = AV_RB32(buffer + 4 * (i)))
#define blk(i)  (block[i] = rol(block[(i)-3] ^ block[(i)-8] ^ block[(i)-14] ^ block[(i)-16], 1))
#define R0(v,w,x,y,z,i) z += (((w)&((x)^(y)))^(y))       + blk0(i) + 0x5A827999 + rol(v, 5); w = rol(w, 30);
#define R1(v,w,x,y,z,i) z += (((w)&((x)^(y)))^(y))       + blk (i) + 0x5A827999 + rol(v, 5); w = rol(w, 30);
#define R2(v,w,x,y,z,i) z += ( (w)^(x)       ^(y))       + blk (i) + 0x6ED9EBA1 + rol(v, 5); w = rol(w, 30);
#define R3(v,w,x,y,z,i) z += ((((w)|(x))&(y))|((w)&(x))) + blk (i) + 0x8F1BBCDC + rol(v, 5); w = rol(w, 30);
#define R4(v,w,x,y,z,i) z += ( (w)^(x)       ^(y))       + blk (i) + 0xCA62C1D6 + rol(v, 5); w = rol(w, 30);
#if CONFIG_SMALL
#else
#define R1_0 \
#define R1_20 \
#define R1_40 \
#define R1_60 \
#endif
#define Ch(x,y,z)   (((x) & ((y) ^ (z))) ^ (z))
#define Maj(z,y,x)  ((((x) | (y)) & (z)) | ((x) & (y)))
#define Sigma0_256(x)   (rol((x), 30) ^ rol((x), 19) ^ rol((x), 10))
#define Sigma1_256(x)   (rol((x), 26) ^ rol((x), 21) ^ rol((x),  7))
#define sigma0_256(x)   (rol((x), 25) ^ rol((x), 14) ^ ((x) >> 3))
#define sigma1_256(x)   (rol((x), 15) ^ rol((x), 13) ^ ((x) >> 10))
#undef blk
#define blk(i)  (block[i] = block[i - 16] + sigma0_256(block[i - 15]) + \
#define ROUND256(a,b,c,d,e,f,g,h)   \
#define ROUND256_0_TO_15(a,b,c,d,e,f,g,h)   \
#define ROUND256_16_TO_63(a,b,c,d,e,f,g,h)   \
#if CONFIG_SMALL
#else
#define R256_0 \
#define R256_16 \
#endif
#if FF_API_CRYPTO_SIZE_T
#else
#endif
#if CONFIG_SMALL
#else
#endif
