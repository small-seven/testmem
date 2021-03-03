#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* for memcpy() and strcmp() */
#include "apps.h"
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/x509.h>
#include <openssl/ssl.h>
#include <openssl/bn.h>
#ifndef OPENSSL_NO_DH
# include <openssl/dh.h>
#endif
#include "s_apps.h"
#define COOKIE_SECRET_LENGTH    16
#ifndef OPENSSL_NO_SOCK
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_HEARTBEATS
#endif
#ifdef TLSEXT_TYPE_next_proto_neg
#endif
#ifdef TLSEXT_TYPE_encrypt_then_mac
#endif
#ifdef TLSEXT_TYPE_application_layer_protocol_negotiation
#endif
#ifdef TLSEXT_TYPE_extended_master_secret
#endif
#ifndef OPENSSL_NO_SOCK
#endif
#ifdef CERT_CB_TEST_RETRY
#endif
void ssl_excert_free(SSL_EXCERT *exc)
{
    SSL_EXCERT *curr;

    if (exc == NULL)
        return;
    while (exc) {
        X509_free(exc->cert);
        EVP_PKEY_free(exc->key);
        sk_X509_pop_free(exc->chain, X509_free);
        curr = exc;
        exc = exc->next;
        OPENSSL_free(curr);
    }
}
#define TLSA_TAIL_SIZE 12
#ifndef OPENSSL_NO_EC
#else
#endif
typedef struct {
    BIO *out;
    int verbose;
    int (*old_cb) (const SSL *s, const SSL_CTX *ctx, int op, int bits, int nid,
                   void *other, void *ex);
} security_debug_ex;
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DH
#endif
