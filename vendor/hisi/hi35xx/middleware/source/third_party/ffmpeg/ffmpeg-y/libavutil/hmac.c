#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "attributes.h"
#include "hmac.h"
#include "md5.h"
#include "sha.h"
#include "sha512.h"
#include "mem.h"
#include "version.h"
#define MAX_HASHLEN 64
#define MAX_BLOCKLEN 128
typedef void (*hmac_final)(void *ctx, uint8_t *dst);
#if FF_API_CRYPTO_SIZE_T
typedef void (*hmac_update)(void *ctx, const uint8_t *src, int len);
#else
typedef void (*hmac_update)(void *ctx, const uint8_t *src, size_t len);
#endif
typedef void (*hmac_init)(void *ctx);

struct AVHMAC {
    void *hash;
    int blocklen, hashlen;
    hmac_final  final;
    hmac_update update;
    hmac_init   init;
    uint8_t key[MAX_BLOCKLEN];
    int keylen;
};
#define DEFINE_SHA(bits)                           \
#define DEFINE_SHA512(bits)                        \
void av_hmac_free(AVHMAC *c)
{
    if (!c)
        return;
    av_freep(&c->hash);
    av_free(c);
}
