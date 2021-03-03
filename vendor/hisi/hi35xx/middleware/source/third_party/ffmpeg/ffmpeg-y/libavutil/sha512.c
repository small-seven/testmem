#include <string.h>
#include "attributes.h"
#include "avutil.h"
#include "bswap.h"
#include "sha512.h"
#include "intreadwrite.h"
#include "mem.h"
typedef struct AVSHA512 {
    uint8_t  digest_len;  ///< digest length in 64-bit words
    uint64_t count;       ///< number of bytes in buffer
    uint8_t  buffer[128]; ///< 1024-bit buffer of input values used in hash updating
    uint64_t state[8];    ///< current hash value
} AVSHA512;
#define ror(value, bits) (((value) >> (bits)) | ((value) << (64 - (bits))))
#define Ch(x,y,z)   (((x) & ((y) ^ (z))) ^ (z))
#define Maj(z,y,x)  ((((x) | (y)) & (z)) | ((x) & (y)))
#define Sigma0_512(x)   (ror((x), 28) ^ ror((x), 34) ^ ror((x), 39))
#define Sigma1_512(x)   (ror((x), 14) ^ ror((x), 18) ^ ror((x), 41))
#define sigma0_512(x)   (ror((x),  1) ^ ror((x),  8) ^ ((x) >> 7))
#define sigma1_512(x)   (ror((x), 19) ^ ror((x), 61) ^ ((x) >> 6))
#define blk0(i) (block[i] = AV_RB64(buffer + 8 * (i)))
#define blk(i)  (block[i] = block[i - 16] + sigma0_512(block[i - 15]) + \
#define ROUND512(a,b,c,d,e,f,g,h)   \
#define ROUND512_0_TO_15(a,b,c,d,e,f,g,h)   \
#define ROUND512_16_TO_80(a,b,c,d,e,f,g,h)   \
#if CONFIG_SMALL
#else
#define R512_0 \
#define R512_16 \
#endif
#if FF_API_CRYPTO_SIZE_T
#else
#endif
#if CONFIG_SMALL
#else
#endif
