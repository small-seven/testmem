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
#define mbedtls_time_t          time_t
#define mbedtls_exit            exit
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */
#if defined(MBEDTLS_AES_C) && defined(MBEDTLS_DHM_C) && \
#include "mbedtls/net_sockets.h"
#include "mbedtls/aes.h"
#include "mbedtls/dhm.h"
#include "mbedtls/rsa.h"
#include "mbedtls/sha1.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include <stdio.h>
#include <string.h>
#endif
#define SERVER_NAME "localhost"
#define SERVER_PORT "11999"
#if !defined(MBEDTLS_AES_C) || !defined(MBEDTLS_DHM_C) ||     \
#else
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_AES_C && MBEDTLS_DHM_C && MBEDTLS_ENTROPY_C &&
