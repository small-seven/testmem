#include <stdio.h>
#include <errno.h>
#include <openssl/crypto.h>
#include "bio_local.h"
#include "internal/cryptlib.h"
#define HAS_LEN_OPER(o)        ((o) == BIO_CB_READ || (o) == BIO_CB_WRITE || \
int BIO_free(BIO *a)
{
    int ret;

    if (a == NULL)
        return 0;

    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
        return 1;
    REF_ASSERT_ISNT(ret < 0);

    if (a->callback != NULL || a->callback_ex != NULL) {
        ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (ret <= 0)
            return ret;
    }

    if ((a->method != NULL) && (a->method->destroy != NULL))
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}
void BIO_vfree(BIO *a)
{
    BIO_free(a);
}
#ifndef OPENSSL_NO_SOCK
#endif
