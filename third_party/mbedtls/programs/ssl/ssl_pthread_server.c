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
#define mbedtls_fprintf    fprintf
#define mbedtls_printf     printf
#define mbedtls_snprintf   snprintf
#define mbedtls_exit            exit
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif
#if !defined(MBEDTLS_BIGNUM_C) || !defined(MBEDTLS_CERTS_C) ||            \
#else
#include <stdlib.h>
#include <string.h>
#if defined(_WIN32)
#include <windows.h>
#endif
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/certs.h"
#include "mbedtls/x509.h"
#include "mbedtls/ssl.h"
#include "mbedtls/net_sockets.h"
#include "mbedtls/error.h"
#if defined(MBEDTLS_SSL_CACHE_C)
#include "mbedtls/ssl_cache.h"
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#include "mbedtls/memory_buffer_alloc.h"
#endif
#define HTTP_RESPONSE \
#define DEBUG_LEVEL 0
#define MAX_NUM_THREADS 5
typedef struct {
    mbedtls_net_context client_fd;
    int thread_complete;
    const mbedtls_ssl_config *config;
} thread_info_t;
typedef struct {
    int active;
    thread_info_t   data;
    pthread_t       thread;
} pthread_info_t;
#ifdef MBEDTLS_ERROR_C
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#endif
#ifdef MBEDTLS_ERROR_C
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_CERTS_C && MBEDTLS_ENTROPY_C &&
