#include <openssl/opensslconf.h>
#include "internal/cryptlib.h"
#include "bn_local.h"
#define BN_BLINDING_COUNTER     32
void BN_BLINDING_free(BN_BLINDING *r)
{
    if (r == NULL)
        return;
    BN_free(r->A);
    BN_free(r->Ai);
    BN_free(r->e);
    BN_free(r->mod);
    CRYPTO_THREAD_lock_free(r->lock);
    OPENSSL_free(r);
}
