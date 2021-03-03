#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include "crypto/siphash.h"
#include "siphash_local.h"
#include "crypto/evp.h"
typedef struct siphash_pkey_ctx_st {
    ASN1_OCTET_STRING ktmp;     /* Temp storage for key */
    SIPHASH ctx;
} SIPHASH_PKEY_CTX;
