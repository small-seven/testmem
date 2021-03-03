#include <stdint.h>
#include "bswap.h"
#include "intreadwrite.h"
#include "mem.h"
#include "md5.h"
typedef struct AVMD5 {
    uint64_t len;
    uint8_t  block[64];
    uint32_t ABCD[4];
} AVMD5;
#define CORE(i, a, b, c, d)                                             \
#if CONFIG_SMALL
#else
#define CORE2(i)                                                        \
#define CORE4(i) CORE2(i); CORE2((i + 4)); CORE2((i + 8)); CORE2((i + 12))
#endif
#if FF_API_CRYPTO_SIZE_T
#else
#endif
#if FF_API_CRYPTO_SIZE_T
#else
#endif
