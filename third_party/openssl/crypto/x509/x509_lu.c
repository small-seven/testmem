#include <stdio.h>
#include "internal/cryptlib.h"
#include "internal/refcount.h"
#include <openssl/x509.h>
#include "crypto/x509.h"
#include <openssl/x509v3.h>
#include "x509_local.h"
void X509_LOOKUP_free(X509_LOOKUP *ctx)
{
    if (ctx == NULL)
        return;
    if ((ctx->method != NULL) && (ctx->method->free != NULL))
        (*ctx->method->free) (ctx);
    OPENSSL_free(ctx);
}
void X509_STORE_free(X509_STORE *vfy)
{
    int i;
    STACK_OF(X509_LOOKUP) *sk;
    X509_LOOKUP *lu;

    if (vfy == NULL)
        return;
    CRYPTO_DOWN_REF(&vfy->references, &i, vfy->lock);
    REF_PRINT_COUNT("X509_STORE", vfy);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    sk = vfy->get_cert_methods;
    for (i = 0; i < sk_X509_LOOKUP_num(sk); i++) {
        lu = sk_X509_LOOKUP_value(sk, i);
        X509_LOOKUP_shutdown(lu);
        X509_LOOKUP_free(lu);
    }
    sk_X509_LOOKUP_free(sk);
    sk_X509_OBJECT_pop_free(vfy->objs, X509_OBJECT_free);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_X509_STORE, vfy, &vfy->ex_data);
    X509_VERIFY_PARAM_free(vfy->param);
    CRYPTO_THREAD_lock_free(vfy->lock);
    OPENSSL_free(vfy);
}
void X509_OBJECT_free(X509_OBJECT *a)
{
    x509_object_free_internal(a);
    OPENSSL_free(a);
}
