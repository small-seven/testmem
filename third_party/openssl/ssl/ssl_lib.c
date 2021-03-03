#include <stdio.h>
#include "ssl_local.h"
#include <openssl/objects.h>
#include <openssl/x509v3.h>
#include <openssl/rand.h>
#include <openssl/rand_drbg.h>
#include <openssl/ocsp.h>
#include <openssl/dh.h>
#include <openssl/engine.h>
#include <openssl/async.h>
#include <openssl/ct.h>
#include "internal/cryptlib.h"
#include "internal/refcount.h"
static void tlsa_free(danetls_record *t)
{
    if (t == NULL)
        return;
    OPENSSL_free(t->data);
    EVP_PKEY_free(t->spki);
    OPENSSL_free(t);
}
#ifdef OPENSSL_NO_DTLS1_2
#endif
#ifdef OPENSSL_NO_DTLS1
#endif
#ifdef OPENSSL_NO_DTLS1
#endif
#ifdef OPENSSL_NO_DTLS1_2
#endif
#ifdef OPENSSL_NO_TLS1_3
#endif
#ifdef OPENSSL_NO_TLS1_2
#endif
#ifdef OPENSSL_NO_TLS1_1
#endif
#ifdef OPENSSL_NO_TLS1
#endif
#ifdef OPENSSL_NO_SSL3
#endif
#ifdef OPENSSL_NO_TLS1
#endif
#ifdef OPENSSL_NO_TLS1_1
#endif
#ifdef OPENSSL_NO_TLS1_2
#endif
#ifdef OPENSSL_NO_SSL3
#endif
#ifdef OPENSSL_NO_TLS1
#endif
#ifdef OPENSSL_NO_TLS1_1
#endif
#ifdef OPENSSL_NO_TLS1_2
#endif
#ifdef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_CT
#endif
void SSL_free(SSL *s)
{
    int i;

    if (s == NULL)
        return;
    CRYPTO_DOWN_REF(&s->references, &i, s->lock);
    REF_PRINT_COUNT("SSL", s);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    X509_VERIFY_PARAM_free(s->param);
    dane_final(&s->dane);
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_SSL, s, &s->ex_data);

    /* Ignore return value */
    ssl_free_wbio_buffer(s);

    BIO_free_all(s->wbio);
    BIO_free_all(s->rbio);

    BUF_MEM_free(s->init_buf);

    /* add extra stuff */
    sk_SSL_CIPHER_free(s->cipher_list);
    sk_SSL_CIPHER_free(s->cipher_list_by_id);
    sk_SSL_CIPHER_free(s->tls13_ciphersuites);
    sk_SSL_CIPHER_free(s->peer_ciphers);

    /* Make the next call work :-) */
    if (s->session != NULL) {
        ssl_clear_bad_session(s);
        SSL_SESSION_free(s->session);
    }
    SSL_SESSION_free(s->psksession);
    OPENSSL_free(s->psksession_id);

    clear_ciphers(s);

    ssl_cert_free(s->cert);
    OPENSSL_free(s->shared_sigalgs);
    /* Free up if allocated */

    OPENSSL_free(s->ext.hostname);
    SSL_CTX_free(s->session_ctx);
#ifndef OPENSSL_NO_EC
    OPENSSL_free(s->ext.ecpointformats);
    OPENSSL_free(s->ext.peer_ecpointformats);
    OPENSSL_free(s->ext.supportedgroups);
    OPENSSL_free(s->ext.peer_supportedgroups);
#endif                          /* OPENSSL_NO_EC */
    sk_X509_EXTENSION_pop_free(s->ext.ocsp.exts, X509_EXTENSION_free);
#ifndef OPENSSL_NO_OCSP
    sk_OCSP_RESPID_pop_free(s->ext.ocsp.ids, OCSP_RESPID_free);
#endif
#ifndef OPENSSL_NO_CT
    SCT_LIST_free(s->scts);
    OPENSSL_free(s->ext.scts);
#endif
    OPENSSL_free(s->ext.ocsp.resp);
    OPENSSL_free(s->ext.alpn);
    OPENSSL_free(s->ext.tls13_cookie);
    OPENSSL_free(s->clienthello);
    OPENSSL_free(s->pha_context);
    EVP_MD_CTX_free(s->pha_dgst);

    sk_X509_NAME_pop_free(s->ca_names, X509_NAME_free);
    sk_X509_NAME_pop_free(s->client_ca_names, X509_NAME_free);

    sk_X509_pop_free(s->verified_chain, X509_free);

    if (s->method != NULL)
        s->method->ssl_free(s);

    RECORD_LAYER_release(&s->rlayer);

    SSL_CTX_free(s->ctx);

    ASYNC_WAIT_CTX_free(s->waitctx);

#if !defined(OPENSSL_NO_NEXTPROTONEG)
    OPENSSL_free(s->ext.npn);
#endif

#ifndef OPENSSL_NO_SRTP
    sk_SRTP_PROTECTION_PROFILE_free(s->srtp_profiles);
#endif

    CRYPTO_THREAD_lock_free(s->lock);

    OPENSSL_free(s);
}
#ifndef OPENSSL_NO_SOCK
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_ENGINE
# ifdef OPENSSL_SSL_CLIENT_ENGINE_AUTO
#  define eng_strx(x)     #x
#  define eng_str(x)      eng_strx(x)
# endif
#endif
void SSL_CTX_free(SSL_CTX *a)
{
    int i;

    if (a == NULL)
        return;

    CRYPTO_DOWN_REF(&a->references, &i, a->lock);
    REF_PRINT_COUNT("SSL_CTX", a);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    X509_VERIFY_PARAM_free(a->param);
    dane_ctx_final(&a->dane);

    /*
     * Free internal session cache. However: the remove_cb() may reference
     * the ex_data of SSL_CTX, thus the ex_data store can only be removed
     * after the sessions were flushed.
     * As the ex_data handling routines might also touch the session cache,
     * the most secure solution seems to be: empty (flush) the cache, then
     * free ex_data, then finally free the cache.
     * (See ticket [openssl.org #212].)
     */
    if (a->sessions != NULL)
        SSL_CTX_flush_sessions(a, 0);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_SSL_CTX, a, &a->ex_data);
    lh_SSL_SESSION_free(a->sessions);
    X509_STORE_free(a->cert_store);
#ifndef OPENSSL_NO_CT
    CTLOG_STORE_free(a->ctlog_store);
#endif
    sk_SSL_CIPHER_free(a->cipher_list);
    sk_SSL_CIPHER_free(a->cipher_list_by_id);
    sk_SSL_CIPHER_free(a->tls13_ciphersuites);
    ssl_cert_free(a->cert);
    sk_X509_NAME_pop_free(a->ca_names, X509_NAME_free);
    sk_X509_NAME_pop_free(a->client_ca_names, X509_NAME_free);
    sk_X509_pop_free(a->extra_certs, X509_free);
    a->comp_methods = NULL;
#ifndef OPENSSL_NO_SRTP
    sk_SRTP_PROTECTION_PROFILE_free(a->srtp_profiles);
#endif
#ifndef OPENSSL_NO_SRP
    SSL_CTX_SRP_CTX_free(a);
#endif
#ifndef OPENSSL_NO_ENGINE
    ENGINE_finish(a->client_cert_engine);
#endif

#ifndef OPENSSL_NO_EC
    OPENSSL_free(a->ext.ecpointformats);
    OPENSSL_free(a->ext.supportedgroups);
#endif
    OPENSSL_free(a->ext.alpn);
    OPENSSL_secure_free(a->ext.secure);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);
}
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DH
#else
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifdef CIPHER_DEBUG
#endif
#ifndef OPENSSL_NO_GOST
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifndef OPENSSL_NO_COMP
#else
#endif
#ifndef OPENSSL_NO_COMP
#else
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_PSK
#endif
#if OPENSSL_API_COMPAT < 0x10100000L
#endif
#ifndef OPENSSL_NO_CT
# ifndef OPENSSL_NO_OCSP
# else
# endif
#endif  /* OPENSSL_NO_CT */
#define SSLV2_CIPHER_LEN    3
