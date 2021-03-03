#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include "crypto/poly1305.h"
#include "poly1305_local.h"
#include "crypto/evp.h"
typedef struct {
    ASN1_OCTET_STRING ktmp;     /* Temp storage for key */
    POLY1305 ctx;
} POLY1305_PKEY_CTX;
