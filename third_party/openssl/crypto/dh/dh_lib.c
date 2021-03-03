#include <stdio.h>
#include "internal/cryptlib.h"
#include "internal/refcount.h"
#include <openssl/bn.h>
#include "dh_local.h"
#include <openssl/engine.h>
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
void DH_free(DH *r)
{
    int i;

    if (r == NULL)
        return;

    CRYPTO_DOWN_REF(&r->references, &i, r->lock);
    REF_PRINT_COUNT("DH", r);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    if (r->meth != NULL && r->meth->finish != NULL)
        r->meth->finish(r);
#ifndef OPENSSL_NO_ENGINE
    ENGINE_finish(r->engine);
#endif

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_DH, r, &r->ex_data);

    CRYPTO_THREAD_lock_free(r->lock);

    BN_clear_free(r->p);
    BN_clear_free(r->g);
    BN_clear_free(r->q);
    BN_clear_free(r->j);
    OPENSSL_free(r->seed);
    BN_clear_free(r->counter);
    BN_clear_free(r->pub_key);
    BN_clear_free(r->priv_key);
    OPENSSL_free(r);
}
