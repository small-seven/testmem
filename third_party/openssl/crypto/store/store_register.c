#include <string.h>
#include "crypto/ctype.h"
#include <assert.h>
#include <openssl/err.h>
#include <openssl/lhash.h>
#include "store_local.h"
void OSSL_STORE_LOADER_free(OSSL_STORE_LOADER *loader)
{
    OPENSSL_free(loader);
}
