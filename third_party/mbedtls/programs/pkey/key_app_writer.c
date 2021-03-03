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
#if defined(MBEDTLS_PK_WRITE_C) && defined(MBEDTLS_FS_IO)
#include "mbedtls/error.h"
#include "mbedtls/pk.h"
#include "mbedtls/error.h"
#include <stdio.h>
#include <string.h>
#endif
#if defined(MBEDTLS_PEM_WRITE_C)
#define USAGE_OUT \
#else
#define USAGE_OUT \
#endif
#if defined(MBEDTLS_PEM_WRITE_C)
#define DFL_OUTPUT_FILENAME     "keyfile.pem"
#define DFL_OUTPUT_FORMAT       OUTPUT_FORMAT_PEM
#else
#define DFL_OUTPUT_FILENAME     "keyfile.der"
#define DFL_OUTPUT_FORMAT       OUTPUT_FORMAT_DER
#endif
#define DFL_MODE                MODE_NONE
#define DFL_FILENAME            "keyfile.key"
#define DFL_DEBUG_LEVEL         0
#define DFL_OUTPUT_MODE         OUTPUT_MODE_NONE
#define MODE_NONE               0
#define MODE_PRIVATE            1
#define MODE_PUBLIC             2
#define OUTPUT_MODE_NONE               0
#define OUTPUT_MODE_PRIVATE            1
#define OUTPUT_MODE_PUBLIC             2
#define OUTPUT_FORMAT_PEM              0
#define OUTPUT_FORMAT_DER              1
#define USAGE \
#if !defined(MBEDTLS_PK_PARSE_C) || \
#else
#if defined(MBEDTLS_PEM_WRITE_C)
#endif
#if defined(MBEDTLS_PEM_WRITE_C)
#endif
#if defined(MBEDTLS_PEM_WRITE_C)
#endif
#if defined(MBEDTLS_RSA_C)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#if defined(MBEDTLS_RSA_C)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#ifdef MBEDTLS_ERROR_C
#else
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_PK_PARSE_C && MBEDTLS_PK_WRITE_C && MBEDTLS_FS_IO */
