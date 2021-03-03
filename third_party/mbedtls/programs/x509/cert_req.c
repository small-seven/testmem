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
#if !defined(MBEDTLS_X509_CSR_WRITE_C) || !defined(MBEDTLS_FS_IO) ||  \
#else
#include "mbedtls/x509_csr.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DFL_FILENAME            "keyfile.key"
#define DFL_PASSWORD            NULL
#define DFL_DEBUG_LEVEL         0
#define DFL_OUTPUT_FILENAME     "cert.req"
#define DFL_SUBJECT_NAME        "CN=Cert,O=mbed TLS,C=UK"
#define DFL_KEY_USAGE           0
#define DFL_FORCE_KEY_USAGE     0
#define DFL_NS_CERT_TYPE        0
#define DFL_FORCE_NS_CERT_TYPE  0
#define DFL_MD_ALG              MBEDTLS_MD_SHA256
#define USAGE \
#if defined(MBEDTLS_MD5_C)
#endif /* MBEDTLS_MD5_C */
#if defined(MBEDTLS_MD4_C)
#endif /* MBEDTLS_MD5_C */
#if defined(MBEDTLS_MD2_C)
#endif /* MBEDTLS_MD2_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#ifdef MBEDTLS_ERROR_C
#else
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_X509_CSR_WRITE_C && MBEDTLS_PK_PARSE_C && MBEDTLS_FS_IO &&
