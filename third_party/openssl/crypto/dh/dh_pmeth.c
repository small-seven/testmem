#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/asn1t.h>
#include <openssl/x509.h>
#include <openssl/evp.h>
#include "dh_local.h"
#include <openssl/bn.h>
#include <openssl/dsa.h>
#include <openssl/objects.h>
#include "crypto/evp.h"
typedef struct {
    /* Parameter gen parameters */
    int prime_len;
    int generator;
    int use_dsa;
    int subprime_len;
    int pad;
    /* message digest used for parameter generation */
    const EVP_MD *md;
    int rfc5114_param;
    int param_nid;
    /* Keygen callback info */
    int gentmp[2];
    /* KDF (if any) to use for DH */
    char kdf_type;
    /* OID to use for KDF */
    ASN1_OBJECT *kdf_oid;
    /* Message digest to use for key derivation */
    const EVP_MD *kdf_md;
    /* User key material */
    unsigned char *kdf_ukm;
    size_t kdf_ukmlen;
    /* KDF output length */
    size_t kdf_outlen;
} DH_PKEY_CTX;
#ifdef OPENSSL_NO_DSA
#else
#endif
#ifdef OPENSSL_NO_CMS
#else
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_CMS
#endif
