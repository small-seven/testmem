#include "dh_local.h"
#include <string.h>
#include <openssl/err.h>
void DH_meth_free(DH_METHOD *dhm)
{
    if (dhm != NULL) {
        OPENSSL_free(dhm->name);
        OPENSSL_free(dhm);
    }
}
