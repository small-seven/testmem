#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_OID_C)
#include "mbedtls/oid.h"
#include "mbedtls/rsa.h"
#include <stdio.h>
#include <string.h>
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#define mbedtls_snprintf snprintf
#endif
#if defined(MBEDTLS_X509_USE_C) || defined(MBEDTLS_X509_CREATE_C)
#include "mbedtls/x509.h"
#endif
#define ADD_LEN(s)      s, MBEDTLS_OID_SIZE(s)
#define FN_OID_TYPED_FROM_ASN1( TYPE_T, NAME, LIST )                    \
#define FN_OID_GET_DESCRIPTOR_ATTR1(FN_NAME, TYPE_T, TYPE_NAME, ATTR1_TYPE, ATTR1) \
#define FN_OID_GET_ATTR1(FN_NAME, TYPE_T, TYPE_NAME, ATTR1_TYPE, ATTR1) \
#define FN_OID_GET_ATTR2(FN_NAME, TYPE_T, TYPE_NAME, ATTR1_TYPE, ATTR1,     \
#define FN_OID_GET_OID_BY_ATTR1(FN_NAME, TYPE_T, LIST, ATTR1_TYPE, ATTR1)   \
#define FN_OID_GET_OID_BY_ATTR2(FN_NAME, TYPE_T, LIST, ATTR1_TYPE, ATTR1,   \
#if defined(MBEDTLS_X509_USE_C) || defined(MBEDTLS_X509_CREATE_C)
typedef struct {
    mbedtls_oid_descriptor_t    descriptor;
    const char          *short_name;
} oid_x520_attr_t;
typedef struct {
    mbedtls_oid_descriptor_t    descriptor;
    int                 ext_type;
} oid_x509_ext_t;
#endif /* MBEDTLS_X509_USE_C || MBEDTLS_X509_CREATE_C */
#if defined(MBEDTLS_MD_C)
typedef struct {
    mbedtls_oid_descriptor_t    descriptor;
    mbedtls_md_type_t           md_alg;
    mbedtls_pk_type_t           pk_alg;
} oid_sig_alg_t;
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_MD2_C)
#endif /* MBEDTLS_MD2_C */
#if defined(MBEDTLS_MD4_C)
#endif /* MBEDTLS_MD4_C */
#if defined(MBEDTLS_MD5_C)
#endif /* MBEDTLS_MD5_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECDSA_C)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_ECDSA_C */
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
#endif /* MBEDTLS_MD_C */
typedef struct {
    mbedtls_oid_descriptor_t    descriptor;
    mbedtls_pk_type_t           pk_alg;
} oid_pk_alg_t;
#if defined(MBEDTLS_ECP_C)
typedef struct {
    mbedtls_oid_descriptor_t    descriptor;
    mbedtls_ecp_group_id        grp_id;
} oid_ecp_grp_t;
#if defined(MBEDTLS_ECP_DP_SECP192R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP192R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP224R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP224R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP256R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP521R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP192K1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP192K1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP224K1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP224K1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP256K1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP256K1_ENABLED */
#if defined(MBEDTLS_ECP_DP_BP256R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_BP256R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_BP384R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_BP384R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_BP512R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_BP512R1_ENABLED */
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_CIPHER_C)
typedef struct {
    mbedtls_oid_descriptor_t    descriptor;
    mbedtls_cipher_type_t       cipher_alg;
} oid_cipher_alg_t;
#endif /* MBEDTLS_CIPHER_C */
#if defined(MBEDTLS_MD_C)
typedef struct {
    mbedtls_oid_descriptor_t    descriptor;
    mbedtls_md_type_t           md_alg;
} oid_md_alg_t;
#if defined(MBEDTLS_MD2_C)
#endif /* MBEDTLS_MD2_C */
#if defined(MBEDTLS_MD4_C)
#endif /* MBEDTLS_MD4_C */
#if defined(MBEDTLS_MD5_C)
#endif /* MBEDTLS_MD5_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
typedef struct {
    mbedtls_oid_descriptor_t    descriptor;
    mbedtls_md_type_t           md_hmac;
} oid_md_hmac_t;
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_MD_C */
#if defined(MBEDTLS_PKCS12_C)
typedef struct {
    mbedtls_oid_descriptor_t    descriptor;
    mbedtls_md_type_t           md_alg;
    mbedtls_cipher_type_t       cipher_alg;
} oid_pkcs12_pbe_alg_t;
#endif /* MBEDTLS_PKCS12_C */
#define OID_SAFE_SNPRINTF                               \
#endif /* MBEDTLS_OID_C */
