#include <stdio.h>
#include <openssl/rand.h>
#include <openssl/engine.h>
#include "internal/refcount.h"
#include "internal/cryptlib.h"
#include "ssl_local.h"
#include "statem/statem_local.h"
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
#define MAX_SESS_ID_ATTEMPTS 10
void SSL_SESSION_free(SSL_SESSION *ss)
{
    int i;

    if (ss == NULL)
        return;
    CRYPTO_DOWN_REF(&ss->references, &i, ss->lock);
    REF_PRINT_COUNT("SSL_SESSION", ss);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_SSL_SESSION, ss, &ss->ex_data);

    OPENSSL_cleanse(ss->master_key, sizeof(ss->master_key));
    OPENSSL_cleanse(ss->session_id, sizeof(ss->session_id));
    X509_free(ss->peer);
    sk_X509_pop_free(ss->peer_chain, X509_free);
    OPENSSL_free(ss->ext.hostname);
    OPENSSL_free(ss->ext.tick);
#ifndef OPENSSL_NO_PSK
    OPENSSL_free(ss->psk_identity_hint);
    OPENSSL_free(ss->psk_identity);
#endif
#ifndef OPENSSL_NO_SRP
    OPENSSL_free(ss->srp_username);
#endif
    OPENSSL_free(ss->ext.alpn_selected);
    OPENSSL_free(ss->ticket_appdata);
    CRYPTO_THREAD_lock_free(ss->lock);
    OPENSSL_clear_free(ss, sizeof(*ss));
}
typedef struct timeout_param_st {
    SSL_CTX *ctx;
    long time;
    LHASH_OF(SSL_SESSION) *cache;
} TIMEOUT_PARAM;
static void SSL_SESSION_list_remove(SSL_CTX *ctx, SSL_SESSION *s)
{
    if ((s->next == NULL) || (s->prev == NULL))
        return;

    if (s->next == (SSL_SESSION *)&(ctx->session_cache_tail)) {
        /* last element in list */
        if (s->prev == (SSL_SESSION *)&(ctx->session_cache_head)) {
            /* only one element in list */
            ctx->session_cache_head = NULL;
            ctx->session_cache_tail = NULL;
        } else {
            ctx->session_cache_tail = s->prev;
            s->prev->next = (SSL_SESSION *)&(ctx->session_cache_tail);
        }
    } else {
        if (s->prev == (SSL_SESSION *)&(ctx->session_cache_head)) {
            /* first element in list */
            ctx->session_cache_head = s->next;
            s->next->prev = (SSL_SESSION *)&(ctx->session_cache_head);
        } else {
            /* middle of list */
            s->next->prev = s->prev;
            s->prev->next = s->next;
        }
    }
    s->prev = s->next = NULL;
}
#ifndef OPENSSL_NO_ENGINE
#endif
