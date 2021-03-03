#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/x509.h>
#include <openssl/asn1.h>
#include "dsa_local.h"
#include <openssl/bn.h>
#include <openssl/cms.h>
#include "crypto/asn1.h"
#include "crypto/evp.h"
static void int_dsa_free(EVP_PKEY *pkey)
{
    DSA_free(pkey->pkey.dsa);
}
#ifndef OPENSSL_NO_CMS
#endif
