#include "internal/cryptlib.h"
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include "crypto/x509.h"
#include "pcy_local.h"
void policy_cache_free(X509_POLICY_CACHE *cache)
{
    if (!cache)
        return;
    policy_data_free(cache->anyPolicy);
    sk_X509_POLICY_DATA_pop_free(cache->data, policy_data_free);
    OPENSSL_free(cache);
}
