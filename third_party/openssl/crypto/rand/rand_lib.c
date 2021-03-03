#include <stdio.h>
#include <time.h>
#include "internal/cryptlib.h"
#include <openssl/opensslconf.h>
#include "crypto/rand.h"
#include <openssl/engine.h>
#include "internal/thread_once.h"
#include "rand_local.h"
#include "e_os.h"
#ifndef OPENSSL_NO_ENGINE
#endif
#ifdef OPENSSL_RAND_SEED_RDTSC
# error "RDTSC enabled?  Should not be possible!"
#endif
#ifdef OPENSSL_RAND_SEED_RDCPU
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
void rand_pool_free(RAND_POOL *pool)
{
    if (pool == NULL)
        return;

    /*
     * Although it would be advisable from a cryptographical viewpoint,
     * we are not allowed to clear attached buffers, since they are passed
     * to rand_pool_attach() as `const unsigned char*`.
     * (see corresponding comment in rand_pool_attach()).
     */
    if (!pool->attached) {
        if (pool->secure)
            OPENSSL_secure_clear_free(pool->buffer, pool->alloc_len);
        else
            OPENSSL_clear_free(pool->buffer, pool->alloc_len);
    }

    OPENSSL_free(pool);
}
#define ENTROPY_TO_BYTES(bits, entropy_factor) \
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#else
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#if OPENSSL_API_COMPAT < 0x10100000L
#endif
