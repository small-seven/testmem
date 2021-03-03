#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <openssl/err.h>
#include "crypto/evp.h"
typedef struct {
    const EVP_MD *md;           /* MD for HMAC use */
    ASN1_OCTET_STRING ktmp;     /* Temp storage for key */
    HMAC_CTX *ctx;
} HMAC_PKEY_CTX;
