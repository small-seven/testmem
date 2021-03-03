#include <string.h>
#include "ec_local.h"
#include <openssl/err.h>
#include <openssl/asn1t.h>
#include <openssl/objects.h>
#include "internal/nelem.h"
#ifndef OPENSSL_NO_EC2M
#endif
typedef struct x9_62_pentanomial_st {
    int32_t k1;
    int32_t k2;
    int32_t k3;
} X9_62_PENTANOMIAL;
typedef struct x9_62_characteristic_two_st {
    int32_t m;
    ASN1_OBJECT *type;
    union {
        char *ptr;
        /* NID_X9_62_onBasis */
        ASN1_NULL *onBasis;
        /* NID_X9_62_tpBasis */
        ASN1_INTEGER *tpBasis;
        /* NID_X9_62_ppBasis */
        X9_62_PENTANOMIAL *ppBasis;
        /* anything else */
        ASN1_TYPE *other;
    } p;
typedef struct x9_62_fieldid_st {
    ASN1_OBJECT *fieldType;
    union {
        char *ptr;
        /* NID_X9_62_prime_field */
        ASN1_INTEGER *prime;
        /* NID_X9_62_characteristic_two_field */
        X9_62_CHARACTERISTIC_TWO *char_two;
        /* anything else */
        ASN1_TYPE *other;
    } p;
typedef struct x9_62_curve_st {
    ASN1_OCTET_STRING *a;
    ASN1_OCTET_STRING *b;
    ASN1_BIT_STRING *seed;
} X9_62_CURVE;
typedef struct ec_privatekey_st {
    int32_t version;
    ASN1_OCTET_STRING *privateKey;
    ECPKPARAMETERS *parameters;
    ASN1_BIT_STRING *publicKey;
} EC_PRIVATEKEY;
#ifdef OPENSSL_NO_EC2M
#else
#endif
#ifdef OPENSSL_NO_EC2M
#else
#endif
#ifndef OPENSSL_NO_EC_NISTP_64_GCC_128
#endif /* !def(OPENSSL_NO_EC_NISTP_64_GCC_128) */
void ECDSA_SIG_free(ECDSA_SIG *sig)
{
    if (sig == NULL)
        return;
    BN_clear_free(sig->r);
    BN_clear_free(sig->s);
    OPENSSL_free(sig);
}
