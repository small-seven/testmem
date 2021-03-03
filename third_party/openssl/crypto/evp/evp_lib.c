#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/evp.h>
#include <openssl/objects.h>
#include "crypto/evp.h"
#include "evp_local.h"
void EVP_MD_meth_free(EVP_MD *md)
{
    OPENSSL_free(md);
}
