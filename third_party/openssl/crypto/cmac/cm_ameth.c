#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/evp.h>
#include <openssl/cmac.h>
#include "crypto/asn1.h"
static void cmac_key_free(EVP_PKEY *pkey)
{
    CMAC_CTX *cmctx = EVP_PKEY_get0(pkey);
    CMAC_CTX_free(cmctx);
}
