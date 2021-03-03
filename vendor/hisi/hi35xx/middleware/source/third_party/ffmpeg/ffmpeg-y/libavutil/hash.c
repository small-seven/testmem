#include <stdint.h>
#include "hash.h"
#include "adler32.h"
#include "crc.h"
#include "md5.h"
#include "murmur3.h"
#include "ripemd.h"
#include "sha.h"
#include "sha512.h"
#include "avstring.h"
#include "base64.h"
#include "error.h"
#include "intreadwrite.h"
#include "mem.h"
typedef struct AVHashContext {
    void *ctx;
    enum hashtype type;
    const AVCRC *crctab;
    uint32_t crc;
} AVHashContext;
#if FF_API_CRYPTO_SIZE_T
#else
#endif
