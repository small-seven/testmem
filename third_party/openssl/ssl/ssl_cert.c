#include <stdio.h>
#include <sys/types.h>
#include "internal/nelem.h"
#include "internal/o_dir.h"
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <openssl/x509v3.h>
#include <openssl/dh.h>
#include <openssl/bn.h>
#include <openssl/crypto.h>
#include "internal/refcount.h"
#include "ssl_local.h"
#include "ssl_cert_table.h"
#include "internal/thread_once.h"
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_PSK
#endif
void ssl_cert_free(CERT *c)
{
    int i;

    if (c == NULL)
        return;
    CRYPTO_DOWN_REF(&c->references, &i, c->lock);
    REF_PRINT_COUNT("CERT", c);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

#ifndef OPENSSL_NO_DH
    EVP_PKEY_free(c->dh_tmp);
#endif

    ssl_cert_clear_certs(c);
    OPENSSL_free(c->conf_sigalgs);
    OPENSSL_free(c->client_sigalgs);
    OPENSSL_free(c->ctype);
    X509_STORE_free(c->verify_store);
    X509_STORE_free(c->chain_store);
    custom_exts_free(&c->custext);
#ifndef OPENSSL_NO_PSK
    OPENSSL_free(c->psk_identity_hint);
#endif
    CRYPTO_THREAD_lock_free(c->lock);
    OPENSSL_free(c);
}
#ifdef OPENSSL_SYS_VMS
#else
#endif
