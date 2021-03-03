#include <string.h>
#include "rsa_local.h"
#include <openssl/err.h>
void RSA_meth_free(RSA_METHOD *meth)
{
    if (meth != NULL) {
        OPENSSL_free(meth->name);
        OPENSSL_free(meth);
    }
}
