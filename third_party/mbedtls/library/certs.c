#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#include "mbedtls/certs.h"
#if defined(MBEDTLS_CERTS_C)
#define TEST_CA_CRT_EC_PEM                                                 \
#define TEST_CA_CRT_EC_DER {                                                 \
#define TEST_CA_KEY_EC_PEM                                                 \
#define TEST_CA_PWD_EC_PEM "PolarSSLTest"
#define TEST_CA_KEY_EC_DER {                                                 \
#define TEST_CA_CRT_RSA_SHA256_PEM                                         \
#define TEST_CA_CRT_RSA_SHA256_DER {                                         \
#define TEST_CA_CRT_RSA_SHA1_PEM                                           \
#define TEST_CA_CRT_RSA_SHA1_DER {                                           \
#define TEST_CA_KEY_RSA_PEM                                                \
#define TEST_CA_PWD_RSA_PEM "PolarSSLTest"
#define TEST_CA_KEY_RSA_DER {                                                \
#define TEST_SRV_CRT_EC_PEM                                                \
#define TEST_SRV_CRT_EC_DER {                                                \
#define TEST_SRV_KEY_EC_PEM                                                \
#define TEST_SRV_KEY_EC_DER {                                                \
#define TEST_SRV_CRT_RSA_SHA256_PEM                                        \
#define TEST_SRV_CRT_RSA_SHA256_DER {                                        \
#define TEST_SRV_CRT_RSA_SHA1_PEM                                          \
#define TEST_SRV_CRT_RSA_SHA1_DER {                                          \
#define TEST_SRV_KEY_RSA_PEM                                               \
#define TEST_SRV_KEY_RSA_DER {                                               \
#define TEST_CLI_CRT_EC_PEM                                                \
#define TEST_CLI_CRT_EC_DER {                                                \
#define TEST_CLI_KEY_EC_PEM                                                \
#define TEST_CLI_KEY_EC_DER {                                                \
#define TEST_CLI_CRT_RSA_PEM                                               \
#define TEST_CLI_CRT_RSA_DER {                                               \
#define TEST_CLI_KEY_RSA_PEM                                               \
#define TEST_CLI_KEY_RSA_DER {                                               \
#if defined(MBEDTLS_PEM_PARSE_C)
#define TEST_CA_KEY_RSA        TEST_CA_KEY_RSA_PEM
#define TEST_CA_PWD_RSA        TEST_CA_PWD_RSA_PEM
#define TEST_CA_CRT_RSA_SHA256 TEST_CA_CRT_RSA_SHA256_PEM
#define TEST_CA_CRT_RSA_SHA1   TEST_CA_CRT_RSA_SHA1_PEM
#define TEST_CA_KEY_EC         TEST_CA_KEY_EC_PEM
#define TEST_CA_PWD_EC         TEST_CA_PWD_EC_PEM
#define TEST_CA_CRT_EC         TEST_CA_CRT_EC_PEM
#define TEST_SRV_KEY_RSA        TEST_SRV_KEY_RSA_PEM
#define TEST_SRV_PWD_RSA        ""
#define TEST_SRV_CRT_RSA_SHA256 TEST_SRV_CRT_RSA_SHA256_PEM
#define TEST_SRV_CRT_RSA_SHA1   TEST_SRV_CRT_RSA_SHA1_PEM
#define TEST_SRV_KEY_EC         TEST_SRV_KEY_EC_PEM
#define TEST_SRV_PWD_EC         ""
#define TEST_SRV_CRT_EC         TEST_SRV_CRT_EC_PEM
#define TEST_CLI_KEY_RSA  TEST_CLI_KEY_RSA_PEM
#define TEST_CLI_PWD_RSA  ""
#define TEST_CLI_CRT_RSA  TEST_CLI_CRT_RSA_PEM
#define TEST_CLI_KEY_EC   TEST_CLI_KEY_EC_PEM
#define TEST_CLI_PWD_EC   ""
#define TEST_CLI_CRT_EC   TEST_CLI_CRT_EC_PEM
#else /* MBEDTLS_PEM_PARSE_C */
#define TEST_CA_KEY_RSA        TEST_CA_KEY_RSA_DER
#define TEST_CA_PWD_RSA        ""
#define TEST_CA_CRT_RSA_SHA256 TEST_CA_CRT_RSA_SHA256_DER
#define TEST_CA_CRT_RSA_SHA1   TEST_CA_CRT_RSA_SHA1_DER
#define TEST_CA_KEY_EC         TEST_CA_KEY_EC_DER
#define TEST_CA_PWD_EC         ""
#define TEST_CA_CRT_EC         TEST_CA_CRT_EC_DER
#define TEST_SRV_KEY_RSA        TEST_SRV_KEY_RSA_DER
#define TEST_SRV_PWD_RSA        ""
#define TEST_SRV_CRT_RSA_SHA256 TEST_SRV_CRT_RSA_SHA256_DER
#define TEST_SRV_CRT_RSA_SHA1   TEST_SRV_CRT_RSA_SHA1_DER
#define TEST_SRV_KEY_EC         TEST_SRV_KEY_EC_DER
#define TEST_SRV_PWD_EC         ""
#define TEST_SRV_CRT_EC         TEST_SRV_CRT_EC_DER
#define TEST_CLI_KEY_RSA  TEST_CLI_KEY_RSA_DER
#define TEST_CLI_PWD_RSA  ""
#define TEST_CLI_CRT_RSA  TEST_CLI_CRT_RSA_DER
#define TEST_CLI_KEY_EC   TEST_CLI_KEY_EC_DER
#define TEST_CLI_PWD_EC   ""
#define TEST_CLI_CRT_EC   TEST_CLI_CRT_EC_DER
#endif /* MBEDTLS_PEM_PARSE_C */
#if defined(MBEDTLS_SHA256_C)
#define TEST_CA_CRT_RSA  TEST_CA_CRT_RSA_SHA256
#define TEST_SRV_CRT_RSA TEST_SRV_CRT_RSA_SHA256
#else
#define TEST_CA_CRT_RSA  TEST_CA_CRT_RSA_SHA1
#define TEST_SRV_CRT_RSA TEST_SRV_CRT_RSA_SHA1
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_RSA_C)
#define TEST_CA_KEY TEST_CA_KEY_RSA
#define TEST_CA_PWD TEST_CA_PWD_RSA
#define TEST_CA_CRT TEST_CA_CRT_RSA
#define TEST_SRV_KEY TEST_SRV_KEY_RSA
#define TEST_SRV_PWD TEST_SRV_PWD_RSA
#define TEST_SRV_CRT TEST_SRV_CRT_RSA
#define TEST_CLI_KEY TEST_CLI_KEY_RSA
#define TEST_CLI_PWD TEST_CLI_PWD_RSA
#define TEST_CLI_CRT TEST_CLI_CRT_RSA
#else /* no RSA, so assume ECDSA */
#define TEST_CA_KEY TEST_CA_KEY_EC
#define TEST_CA_PWD TEST_CA_PWD_EC
#define TEST_CA_CRT TEST_CA_CRT_EC
#define TEST_SRV_KEY TEST_SRV_KEY_EC
#define TEST_SRV_PWD TEST_SRV_PWD_EC
#define TEST_SRV_CRT TEST_SRV_CRT_EC
#define TEST_CLI_KEY TEST_CLI_KEY_EC
#define TEST_CLI_PWD TEST_CLI_PWD_EC
#define TEST_CLI_CRT TEST_CLI_CRT_EC
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_SHA1_C)
#endif
#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_ECDSA_C)
#endif
#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_SHA1_C)
#endif
#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_ECDSA_C)
#endif
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECDSA_C)
#endif /* MBEDTLS_ECDSA_C */
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECDSA_C)
#endif /* MBEDTLS_ECDSA_C */
#if defined(MBEDTLS_PEM_PARSE_C)
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECDSA_C)
#endif /* MBEDTLS_ECDSA_C */
#endif /* MBEDTLS_PEM_PARSE_C */
#endif /* MBEDTLS_CERTS_C */
