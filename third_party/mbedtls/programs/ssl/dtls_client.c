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
#define mbedtls_exit            exit
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif
#if !defined(MBEDTLS_SSL_CLI_C) || !defined(MBEDTLS_SSL_PROTO_DTLS) ||    \
#else
#include <string.h>
#include "mbedtls/net_sockets.h"
#include "mbedtls/debug.h"
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/error.h"
#include "mbedtls/certs.h"
#include "mbedtls/timing.h"
#define SERVER_PORT "4433"
#define SERVER_NAME "localhost"
#ifdef FORCE_IPV4
#define SERVER_ADDR "127.0.0.1"     /* Forces IPv4 */
#else
#define SERVER_ADDR "::1"
#endif
#define MESSAGE     "Echo this"
#define READ_TIMEOUT_MS 1000
#define MAX_RETRY       5
#define DEBUG_LEVEL 0
#if defined(MBEDTLS_DEBUG_C)
#endif
#ifdef MBEDTLS_ERROR_C
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_SSL_CLI_C && MBEDTLS_SSL_PROTO_DTLS && MBEDTLS_NET_C &&
