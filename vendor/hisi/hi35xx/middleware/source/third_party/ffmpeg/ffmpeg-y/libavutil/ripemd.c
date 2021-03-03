#include <string.h>
#include "attributes.h"
#include "avutil.h"
#include "bswap.h"
#include "intreadwrite.h"
#include "ripemd.h"
#include "mem.h"
typedef struct AVRIPEMD {
    uint8_t  digest_len;  ///< digest length in 32-bit words
    uint64_t count;       ///< number of bytes in buffer
    uint8_t  buffer[64];  ///< 512-bit buffer of input values used in hash updating
    uint32_t state[10];   ///< current hash value
    /** function used to update hash for 512-bit input block */
    void     (*transform)(uint32_t *state, const uint8_t buffer[64]);
} AVRIPEMD;
#define rol(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))
#define ROUND128_0_TO_15(a,b,c,d,e,f,g,h)                               \
#define ROUND128_16_TO_31(a,b,c,d,e,f,g,h)                              \
#define ROUND128_32_TO_47(a,b,c,d,e,f,g,h)                              \
#define ROUND128_48_TO_63(a,b,c,d,e,f,g,h)                              \
#define R128_0                          \
#define R128_16                         \
#define R128_32                         \
#define R128_48                         \
#if CONFIG_SMALL
#else
#endif
#if CONFIG_SMALL
#else
#endif
#define ROTATE(x,y) \
#define ROUND160_0_TO_15(a,b,c,d,e,f,g,h,i,j)                               \
#define ROUND160_16_TO_31(a,b,c,d,e,f,g,h,i,j)                              \
#define ROUND160_32_TO_47(a,b,c,d,e,f,g,h,i,j)                              \
#define ROUND160_48_TO_63(a,b,c,d,e,f,g,h,i,j)                              \
#define ROUND160_64_TO_79(a,b,c,d,e,f,g,h,i,j)                              \
#define R160_0                              \
#define R160_16                             \
#define R160_32                             \
#define R160_48                             \
#define R160_64                             \
#if CONFIG_SMALL
#else
#endif
#if CONFIG_SMALL
#else
#endif
#if FF_API_CRYPTO_SIZE_T
#else
#endif
#if CONFIG_SMALL
#else
#endif
