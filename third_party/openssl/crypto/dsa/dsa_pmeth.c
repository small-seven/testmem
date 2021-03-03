#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/asn1t.h>
#include <openssl/x509.h>
#include <openssl/evp.h>
#include <openssl/bn.h>
#include "crypto/evp.h"
#include "dsa_local.h"
typedef struct {
    /* Parameter gen parameters */
    int nbits;                  /* size of p in bits (default: 2048) */
    int qbits;                  /* size of q in bits (default: 224) */
    const EVP_MD *pmd;          /* MD for parameter generation */
    /* Keygen callback info */
    int gentmp[2];
    /* message digest */
    const EVP_MD *md;           /* MD for the signature */
} DSA_PKEY_CTX;
