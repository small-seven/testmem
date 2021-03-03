#include "internal/constant_time.h"
#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/asn1t.h>
#include <openssl/x509.h>
#include <openssl/rsa.h>
#include <openssl/bn.h>
#include <openssl/evp.h>
#include <openssl/x509v3.h>
#include <openssl/cms.h>
#include "crypto/evp.h"
#include "rsa_local.h"
typedef struct {
    /* Key gen parameters */
    int nbits;
    BIGNUM *pub_exp;
    int primes;
    /* Keygen callback info */
    int gentmp[2];
    /* RSA padding mode */
    int pad_mode;
    /* message digest */
    const EVP_MD *md;
    /* message digest for MGF1 */
    const EVP_MD *mgf1md;
    /* PSS salt length */
    int saltlen;
    /* Minimum salt length or -1 if no PSS parameter restriction */
    int min_saltlen;
    /* Temp buffer */
    unsigned char *tbuf;
    /* OAEP label */
    unsigned char *oaep_label;
    size_t oaep_labellen;
} RSA_PKEY_CTX;
#define rsa_pss_restricted(rctx) (rctx->min_saltlen != -1)
#ifndef OPENSSL_NO_CMS
#endif
#ifndef OPENSSL_NO_CMS
#endif
