#define _POSIX_C_SOURCE 200112L
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
#include "mbedtls/base64.h"
#include "mbedtls/error.h"
#include "mbedtls/net_sockets.h"
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/certs.h"
#include "mbedtls/x509.h"
#include <stdlib.h>
#include <string.h>
#if !defined(_MSC_VER) || defined(EFIX64) || defined(EFI32)
#include <unistd.h>
#else
#include <io.h>
#endif
#if defined(_WIN32) || defined(_WIN32_WCE)
#include <winsock2.h>
#include <windows.h>
#if defined(_MSC_VER)
#if defined(_WIN32_WCE)
#pragma comment( lib, "ws2.lib" )
#else
#pragma comment( lib, "ws2_32.lib" )
#endif
#endif /* _MSC_VER */
#endif
#define DFL_SERVER_NAME         "localhost"
#define DFL_SERVER_PORT         "465"
#define DFL_USER_NAME           "user"
#define DFL_USER_PWD            "password"
#define DFL_MAIL_FROM           ""
#define DFL_MAIL_TO             ""
#define DFL_DEBUG_LEVEL         0
#define DFL_CA_FILE             ""
#define DFL_CRT_FILE            ""
#define DFL_KEY_FILE            ""
#define DFL_FORCE_CIPHER        0
#define DFL_MODE                0
#define DFL_AUTHENTICATION      0
#define MODE_SSL_TLS            0
#define MODE_STARTTLS           0
#if defined(MBEDTLS_BASE64_C)
#define USAGE_AUTH \
#else
#define USAGE_AUTH \
#endif /* MBEDTLS_BASE64_C */
#if defined(MBEDTLS_FS_IO)
#define USAGE_IO \
#else
#define USAGE_IO \
#endif /* MBEDTLS_FS_IO */
#define USAGE \
#if defined(MBEDTLS_ERROR_C)
#endif
#if defined(MBEDTLS_BASE64_C)
#else
#endif
#if defined(MBEDTLS_FS_IO)
#endif
#if defined(MBEDTLS_CERTS_C) && defined(MBEDTLS_PEM_PARSE_C)
#else
#endif
#if defined(MBEDTLS_FS_IO)
#endif
#if defined(MBEDTLS_CERTS_C)
#else
#endif
#if defined(MBEDTLS_FS_IO)
#endif
#if defined(MBEDTLS_CERTS_C) && defined(MBEDTLS_PEM_PARSE_C)
#else
#endif
#if defined(MBEDTLS_BASE64_C)
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_ENTROPY_C && MBEDTLS_SSL_TLS_C &&
