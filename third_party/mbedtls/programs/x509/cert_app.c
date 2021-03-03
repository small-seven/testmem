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
#define mbedtls_time            time
#define mbedtls_time_t          time_t
#define mbedtls_fprintf         fprintf
#define mbedtls_printf          printf
#define mbedtls_exit            exit
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */
#if !defined(MBEDTLS_BIGNUM_C) || !defined(MBEDTLS_ENTROPY_C) ||  \
#else
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/net_sockets.h"
#include "mbedtls/ssl.h"
#include "mbedtls/x509.h"
#include "mbedtls/debug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MODE_NONE               0
#define MODE_FILE               1
#define MODE_SSL                2
#define DFL_MODE                MODE_NONE
#define DFL_FILENAME            "cert.crt"
#define DFL_CA_FILE             ""
#define DFL_CRL_FILE            ""
#define DFL_CA_PATH             ""
#define DFL_SERVER_NAME         "localhost"
#define DFL_SERVER_PORT         "4433"
#define DFL_DEBUG_LEVEL         0
#define DFL_PERMISSIVE          0
#define USAGE_IO \
#define USAGE \
#if defined(MBEDTLS_X509_CRL_PARSE_C)
#else
#endif
#if defined(MBEDTLS_X509_CRL_PARSE_C)
#endif
#if defined(MBEDTLS_DEBUG_C)
#endif
#if defined(MBEDTLS_X509_CRL_PARSE_C)
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_ENTROPY_C && MBEDTLS_SSL_TLS_C &&
