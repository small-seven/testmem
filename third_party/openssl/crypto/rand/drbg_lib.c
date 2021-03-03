#include <string.h>
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include "rand_local.h"
#include "internal/thread_once.h"
#include "crypto/rand.h"
#include "crypto/cryptlib.h"
#ifndef RAND_DRBG_GET_RANDOM_NONCE
#endif
void RAND_DRBG_free(RAND_DRBG *drbg)
{
    if (drbg == NULL)
        return;

    if (drbg->meth != NULL)
        drbg->meth->uninstantiate(drbg);
    rand_pool_free(drbg->adin_pool);
    CRYPTO_THREAD_lock_free(drbg->lock);
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_DRBG, drbg, &drbg->ex_data);

    if (drbg->secure)
        OPENSSL_secure_clear_free(drbg, sizeof(*drbg));
    else
        OPENSSL_clear_free(drbg, sizeof(*drbg));
}
#if defined(OPENSSL_RAND_SEED_NONE)
#else
#endif
