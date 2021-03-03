#include "internal/cryptlib.h"
#include <string.h>
#include "ec_local.h"
#include "internal/refcount.h"
#include <openssl/err.h>
#include <openssl/engine.h>
void EC_KEY_free(EC_KEY *r)
{
    int i;

    if (r == NULL)
        return;

    CRYPTO_DOWN_REF(&r->references, &i, r->lock);
    REF_PRINT_COUNT("EC_KEY", r);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    if (r->meth != NULL && r->meth->finish != NULL)
        r->meth->finish(r);

#ifndef OPENSSL_NO_ENGINE
    ENGINE_finish(r->engine);
#endif

    if (r->group && r->group->meth->keyfinish)
        r->group->meth->keyfinish(r);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EC_KEY, r, &r->ex_data);
    CRYPTO_THREAD_lock_free(r->lock);
    EC_GROUP_free(r->group);
    EC_POINT_free(r->pub_key);
    BN_clear_free(r->priv_key);

    OPENSSL_clear_free((void *)r, sizeof(EC_KEY));
}
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
