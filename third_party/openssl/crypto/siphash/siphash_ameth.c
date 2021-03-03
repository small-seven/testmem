#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/evp.h>
#include "crypto/asn1.h"
#include "crypto/siphash.h"
#include "siphash_local.h"
#include "crypto/evp.h"
static void siphash_key_free(EVP_PKEY *pkey)
{
    ASN1_OCTET_STRING *os = EVP_PKEY_get0(pkey);

    if (os != NULL) {
        if (os->data != NULL)
            OPENSSL_cleanse(os->data, os->length);
        ASN1_OCTET_STRING_free(os);
    }
}
