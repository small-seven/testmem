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
#define mbedtls_free            free
#define mbedtls_calloc          calloc
#define mbedtls_printf          printf
#define mbedtls_exit            exit
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */
#if defined(MBEDTLS_BASE64_C) && defined(MBEDTLS_FS_IO)
#include "mbedtls/error.h"
#include "mbedtls/base64.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif
#define DFL_FILENAME            "file.pem"
#define DFL_OUTPUT_FILENAME     "file.der"
#define USAGE \
#if !defined(MBEDTLS_BASE64_C) || !defined(MBEDTLS_FS_IO)
#else
#ifdef MBEDTLS_ERROR_C
#endif
#ifdef MBEDTLS_ERROR_C
#endif
#ifdef MBEDTLS_ERROR_C
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_BASE64_C && MBEDTLS_FS_IO */
