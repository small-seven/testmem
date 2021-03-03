#include <string.h>
#include <openssl/evp.h>
#include "crypto/evp.h"
#include "evp_local.h"
void EVP_CIPHER_meth_free(EVP_CIPHER *cipher)
{
    OPENSSL_free(cipher);
}
