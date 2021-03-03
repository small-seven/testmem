#include <stdio.h>
#include <limits.h>
#include "internal/cryptlib.h"
#include <openssl/evp.h>
#include "evp_local.h"
#include "crypto/evp.h"
#ifndef CHARSET_EBCDIC
# define conv_bin2ascii(a, table)       ((table)[(a)&0x3f])
#else
# define conv_bin2ascii(a, table)       ((table)[(a)&0x3f])
#endif
#define BIN_PER_LINE    (64/4*3)
#define CHUNKS_PER_LINE (64/4)
#define CHAR_PER_LINE   (64+1)
#define B64_EOLN                0xF0
#define B64_CR                  0xF1
#define B64_EOF                 0xF2
#define B64_WS                  0xE0
#define B64_ERROR               0xFF
#define B64_NOT_BASE64(a)       (((a)|0x13) == 0xF3)
#define B64_BASE64(a)           (!B64_NOT_BASE64(a))
#ifndef CHARSET_EBCDIC
#else
#endif
void EVP_ENCODE_CTX_free(EVP_ENCODE_CTX *ctx)
{
    OPENSSL_free(ctx);
}
