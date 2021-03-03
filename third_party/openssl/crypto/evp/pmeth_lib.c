#include <stdio.h>
#include <stdlib.h>
#include "internal/cryptlib.h"
#include <openssl/engine.h>
#include <openssl/evp.h>
#include <openssl/x509v3.h>
#include "crypto/asn1.h"
#include "crypto/evp.h"
#include "internal/numbers.h"
typedef int sk_cmp_fn_type(const char *const *a, const char *const *b);

static STACK_OF(EVP_PKEY_METHOD) *app_pkey_methods = NULL;

/* This array needs to be in order of NIDs */
static const EVP_PKEY_METHOD *standard_methods[] = {
#ifndef OPENSSL_NO_RSA
    &rsa_pkey_meth,
#endif
#ifndef OPENSSL_NO_DH
    &dh_pkey_meth,
#endif
#ifndef OPENSSL_NO_DSA
    &dsa_pkey_meth,
#endif
#ifndef OPENSSL_NO_EC
    &ec_pkey_meth,
#endif
    &hmac_pkey_meth,
#ifndef OPENSSL_NO_CMAC
    &cmac_pkey_meth,
#endif
#ifndef OPENSSL_NO_RSA
    &rsa_pss_pkey_meth,
#endif
#ifndef OPENSSL_NO_DH
    &dhx_pkey_meth,
#endif
#ifndef OPENSSL_NO_SCRYPT
    &scrypt_pkey_meth,
#endif
    &tls1_prf_pkey_meth,
#ifndef OPENSSL_NO_EC
    &ecx25519_pkey_meth,
    &ecx448_pkey_meth,
#endif
    &hkdf_pkey_meth,
#ifndef OPENSSL_NO_POLY1305
    &poly1305_pkey_meth,
#endif
#ifndef OPENSSL_NO_SIPHASH
    &siphash_pkey_meth,
#endif
#ifndef OPENSSL_NO_EC
    &ed25519_pkey_meth,
    &ed448_pkey_meth,
#endif
#ifndef OPENSSL_NO_SM2
    &sm2_pkey_meth,
#endif
};
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
void EVP_PKEY_meth_free(EVP_PKEY_METHOD *pmeth)
{
    if (pmeth && (pmeth->flags & EVP_PKEY_FLAG_DYNAMIC))
        OPENSSL_free(pmeth);
}
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
int EVP_PKEY_meth_remove(const EVP_PKEY_METHOD *pmeth)
{
    const EVP_PKEY_METHOD *ret;

    ret = sk_EVP_PKEY_METHOD_delete_ptr(app_pkey_methods, pmeth);

    return ret == NULL ? 0 : 1;
}
void EVP_PKEY_CTX_free(EVP_PKEY_CTX *ctx)
{
    if (ctx == NULL)
        return;
    if (ctx->pmeth && ctx->pmeth->cleanup)
        ctx->pmeth->cleanup(ctx);
    EVP_PKEY_free(ctx->pkey);
    EVP_PKEY_free(ctx->peerkey);
#ifndef OPENSSL_NO_ENGINE
    ENGINE_finish(ctx->engine);
#endif
    OPENSSL_free(ctx);
}
