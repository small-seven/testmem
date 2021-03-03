#include <stdio.h>
#include "internal/cryptlib.h"
#include "internal/refcount.h"
#include <openssl/bn.h>
#include <openssl/err.h>
#include <openssl/objects.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/rsa.h>
#include <openssl/dsa.h>
#include <openssl/dh.h>
#include <openssl/cmac.h>
#include <openssl/engine.h>
#include "crypto/asn1.h"
#include "crypto/evp.h"
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_CMAC
#else
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_POLY1305
#endif
#ifndef OPENSSL_NO_SIPHASH
#endif
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x == NULL)
        return;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);
    EVP_PKEY_free_it(x);
    CRYPTO_THREAD_lock_free(x->lock);
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
    OPENSSL_free(x);
}
#ifndef OPENSSL_NO_ENGINE
#endif
