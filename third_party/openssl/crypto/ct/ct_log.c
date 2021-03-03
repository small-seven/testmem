#include <stdlib.h>
#include <string.h>
#include <openssl/conf.h>
#include <openssl/ct.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/safestack.h>
#include "internal/cryptlib.h"
typedef struct ctlog_store_load_ctx_st {
    CTLOG_STORE *log_store;
    CONF *conf;
    size_t invalid_log_entries;
} CTLOG_STORE_LOAD_CTX;
static void ctlog_store_load_ctx_free(CTLOG_STORE_LOAD_CTX* ctx)
{
    OPENSSL_free(ctx);
}
void CTLOG_STORE_free(CTLOG_STORE *store)
{
    if (store != NULL) {
        sk_CTLOG_pop_free(store->logs, CTLOG_free);
        OPENSSL_free(store);
    }
}
void CTLOG_free(CTLOG *log)
{
    if (log != NULL) {
        OPENSSL_free(log->name);
        EVP_PKEY_free(log->public_key);
        OPENSSL_free(log);
    }
}
