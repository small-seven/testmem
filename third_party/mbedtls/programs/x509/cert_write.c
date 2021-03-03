#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#include <stdlib.h>
#define mbedtls_printf          printf
#define mbedtls_exit            exit
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */
#if !defined(MBEDTLS_X509_CRT_WRITE_C) || \
#else
#include "mbedtls/x509_crt.h"
#include "mbedtls/x509_csr.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/md.h"
#include "mbedtls/error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(MBEDTLS_X509_CSR_PARSE_C)
#define USAGE_CSR                                                           \
#else
#define USAGE_CSR ""
#endif /* MBEDTLS_X509_CSR_PARSE_C */
#define DFL_ISSUER_CRT          ""
#define DFL_REQUEST_FILE        ""
#define DFL_SUBJECT_KEY         "subject.key"
#define DFL_ISSUER_KEY          "ca.key"
#define DFL_SUBJECT_PWD         ""
#define DFL_ISSUER_PWD          ""
#define DFL_OUTPUT_FILENAME     "cert.crt"
#define DFL_SUBJECT_NAME        "CN=Cert,O=mbed TLS,C=UK"
#define DFL_ISSUER_NAME         "CN=CA,O=mbed TLS,C=UK"
#define DFL_NOT_BEFORE          "20010101000000"
#define DFL_NOT_AFTER           "20301231235959"
#define DFL_SERIAL              "1"
#define DFL_SELFSIGN            0
#define DFL_IS_CA               0
#define DFL_MAX_PATHLEN         -1
#define DFL_KEY_USAGE           0
#define DFL_NS_CERT_TYPE        0
#define DFL_VERSION             3
#define DFL_AUTH_IDENT          1
#define DFL_SUBJ_IDENT          1
#define DFL_CONSTRAINTS         1
#define DFL_DIGEST              MBEDTLS_MD_SHA256
#define USAGE \
#if defined(MBEDTLS_X509_CSR_PARSE_C)
#endif
#if defined(MBEDTLS_X509_CSR_PARSE_C)
#endif
#if defined(MBEDTLS_X509_CSR_PARSE_C)
#endif /* MBEDTLS_X509_CSR_PARSE_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_X509_CSR_PARSE_C)
#endif /* MBEDTLS_X509_CSR_PARSE_C */
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_X509_CRT_WRITE_C && MBEDTLS_X509_CRT_PARSE_C &&
