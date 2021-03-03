#include <stdio.h>
#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_CHACHA
# include <openssl/evp.h>
# include <openssl/objects.h>
# include "evp_local.h"
# include "crypto/evp.h"
# include "crypto/chacha.h"
typedef struct {
    union {
        double align;   /* this ensures even sizeof(EVP_CHACHA_KEY)%8==0 */
        unsigned int d[CHACHA_KEY_SIZE / 4];
    } key;
#define data(ctx)   ((EVP_CHACHA_KEY *)(ctx)->cipher_data)
#define CHACHA20_POLY1305_MAX_IVLEN     12
# ifndef OPENSSL_NO_POLY1305
#  include "crypto/poly1305.h"
typedef struct {
    EVP_CHACHA_KEY key;
    unsigned int nonce[12/4];
    unsigned char tag[POLY1305_BLOCK_SIZE];
    unsigned char tls_aad[POLY1305_BLOCK_SIZE];
    struct { uint64_t aad, text; } len;
#  define NO_TLS_PAYLOAD_LENGTH ((size_t)-1)
#  define aead_data(ctx)        ((EVP_CHACHA_AEAD_CTX *)(ctx)->cipher_data)
#  define POLY1305_ctx(actx)    ((POLY1305 *)(actx + 1))
#  if !defined(OPENSSL_SMALL_FOOTPRINT)
#   if defined(POLY1305_ASM) && (defined(__x86_64) || defined(__x86_64__) || \
#    define XOR128_HELPERS
#   else
#   endif
#   ifdef XOR128_HELPERS
#   else
#   endif
#  else
#  endif
#  if !defined(OPENSSL_SMALL_FOOTPRINT)
#  endif
# endif
#endif
