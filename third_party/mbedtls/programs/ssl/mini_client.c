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
#endif
#if defined(unix) || defined(__unix__) || defined(__unix) || defined(__APPLE__)
#define UNIX
#endif
#if !defined(MBEDTLS_CTR_DRBG_C) || !defined(MBEDTLS_ENTROPY_C) || \
#else
#include <string.h>
#include "mbedtls/net_sockets.h"
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT_BE 0x1151      /* 4433 */
#define PORT_LE 0x5111
#define ADDR_BE 0x7f000001  /* 127.0.0.1 */
#define ADDR_LE 0x0100007f
#define HOSTNAME "localhost" /* for cert verification if enabled */
#define GET_REQUEST "GET / HTTP/1.0\r\n\r\n"
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#endif
