#include "dsa_local.h"
#include <string.h>
#include <openssl/err.h>
void DSA_meth_free(DSA_METHOD *dsam)
{
    if (dsam != NULL) {
        OPENSSL_free(dsam->name);
        OPENSSL_free(dsam);
    }
}
