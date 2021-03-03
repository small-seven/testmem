#include <stdio.h>
#include <openssl/objects.h>
#include "internal/nelem.h"
#include "ssl_local.h"
#include <openssl/md5.h>
#include <openssl/dh.h>
#include <openssl/rand.h>
#include "internal/cryptlib.h"
#define TLS13_NUM_CIPHERS       OSSL_NELEM(tls13_ciphers)
#define SSL3_NUM_CIPHERS        OSSL_NELEM(ssl3_ciphers)
#define SSL3_NUM_SCSVS          OSSL_NELEM(ssl3_scsvs)
#if !defined(OPENSSL_NO_CHACHA) && !defined(OPENSSL_NO_POLY1305)
#endif
#ifndef OPENSSL_NO_WEAK_SSL_CIPHERS
#endif
# ifndef OPENSSL_NO_WEAK_SSL_CIPHERS
# endif
# ifndef OPENSSL_NO_WEAK_SSL_CIPHERS
# endif
# ifndef OPENSSL_NO_WEAK_SSL_CIPHERS
# endif
# ifndef OPENSSL_NO_WEAK_SSL_CIPHERS
# endif
# ifndef OPENSSL_NO_WEAK_SSL_CIPHERS
# endif
# ifndef OPENSSL_NO_WEAK_SSL_CIPHERS
# endif
#  ifndef OPENSSL_NO_WEAK_SSL_CIPHERS
#  endif
# ifndef OPENSSL_NO_WEAK_SSL_CIPHERS
# endif
#if !defined(OPENSSL_NO_CHACHA) && !defined(OPENSSL_NO_POLY1305)
#endif                          /* !defined(OPENSSL_NO_CHACHA) &&
#ifndef OPENSSL_NO_CAMELLIA
#endif                          /* OPENSSL_NO_CAMELLIA */
#ifndef OPENSSL_NO_GOST
#endif                          /* OPENSSL_NO_GOST */
#ifndef OPENSSL_NO_IDEA
#endif
#ifndef OPENSSL_NO_SEED
#endif                          /* OPENSSL_NO_SEED */
#ifndef OPENSSL_NO_WEAK_SSL_CIPHERS
#endif                          /* OPENSSL_NO_WEAK_SSL_CIPHERS */
#ifndef OPENSSL_NO_ARIA
#endif /* OPENSSL_NO_ARIA */
#ifndef OPENSSL_NO_SRP
#endif
void ssl3_free(SSL *s)
{
    if (s == NULL || s->s3 == NULL)
        return;

    ssl3_cleanup_key_block(s);

#if !defined(OPENSSL_NO_EC) || !defined(OPENSSL_NO_DH)
    EVP_PKEY_free(s->s3->peer_tmp);
    s->s3->peer_tmp = NULL;
    EVP_PKEY_free(s->s3->tmp.pkey);
    s->s3->tmp.pkey = NULL;
#endif

    OPENSSL_free(s->s3->tmp.ctype);
    sk_X509_NAME_pop_free(s->s3->tmp.peer_ca_names, X509_NAME_free);
    OPENSSL_free(s->s3->tmp.ciphers_raw);
    OPENSSL_clear_free(s->s3->tmp.pms, s->s3->tmp.pmslen);
    OPENSSL_free(s->s3->tmp.peer_sigalgs);
    OPENSSL_free(s->s3->tmp.peer_cert_sigalgs);
    ssl3_free_digest_list(s);
    OPENSSL_free(s->s3->alpn_selected);
    OPENSSL_free(s->s3->alpn_proposed);

#ifndef OPENSSL_NO_SRP
    SSL_SRP_CTX_free(s);
#endif
    OPENSSL_clear_free(s->s3, sizeof(*s->s3));
    s->s3 = NULL;
}
#if !defined(OPENSSL_NO_EC) || !defined(OPENSSL_NO_DH)
#endif                          /* !OPENSSL_NO_EC */
#if !defined(OPENSSL_NO_NEXTPROTONEG)
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_EC
#endif                          /* !OPENSSL_NO_EC */
#ifndef OPENSSL_NO_HEARTBEATS
#endif
#ifndef OPENSSL_NO_EC
#endif
#if !defined(OPENSSL_NO_DH) || !defined(OPENSSL_NO_EC)
#else
#endif
#if !defined(OPENSSL_NO_DH) || !defined(OPENSSL_NO_EC)
#else
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_EC
#endif                          /* !OPENSSL_NO_EC */
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_CHACHA
#endif
#ifdef CIPHER_DEBUG
#endif
#ifndef OPENSSL_NO_CHACHA
# endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_PSK
#endif                          /* OPENSSL_NO_PSK */
#ifdef CIPHER_DEBUG
#endif
#ifndef OPENSSL_NO_EC
#endif                          /* OPENSSL_NO_EC */
#if !defined(OPENSSL_NO_EC)
#endif
#ifndef OPENSSL_NO_CHACHA
#endif
#ifndef OPENSSL_NO_GOST
#endif
#ifndef OPENSSL_NO_DH
# ifndef OPENSSL_NO_RSA
# endif
# ifndef OPENSSL_NO_DSA
# endif
#endif                          /* !OPENSSL_NO_DH */
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_PSK
#else
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DH
#endif
