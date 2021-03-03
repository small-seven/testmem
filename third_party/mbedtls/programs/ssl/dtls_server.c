#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf     printf
#define mbedtls_fprintf    fprintf
#define mbedtls_time_t     time_t
#define mbedtls_exit            exit
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif
#ifdef FORCE_IPV4
#define BIND_IP     "0.0.0.0"     /* Forces IPv4 */
#else
#define BIND_IP     "::"
#endif
#if !defined(MBEDTLS_SSL_SRV_C) || !defined(MBEDTLS_SSL_PROTO_DTLS) ||    \
#else
#if defined(_WIN32)
#include <windows.h>
#endif
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/certs.h"
#include "mbedtls/x509.h"
#include "mbedtls/ssl.h"
#include "mbedtls/ssl_cookie.h"
#include "mbedtls/net_sockets.h"
#include "mbedtls/error.h"
#include "mbedtls/debug.h"
#include "mbedtls/timing.h"
#if defined(MBEDTLS_SSL_CACHE_C)
#include "mbedtls/ssl_cache.h"
#endif
#define READ_TIMEOUT_MS 10000   /* 5 seconds */
#define DEBUG_LEVEL 0
#if defined(MBEDTLS_SSL_CACHE_C)
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#endif
#if defined(MBEDTLS_DEBUG_C)
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#endif
#ifdef MBEDTLS_ERROR_C
#endif
#ifdef MBEDTLS_ERROR_C
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_SSL_SRV_C && MBEDTLS_SSL_PROTO_DTLS &&
