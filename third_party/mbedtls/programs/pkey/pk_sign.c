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
#define mbedtls_snprintf        snprintf
#define mbedtls_printf          printf
#define mbedtls_exit            exit
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */
#if !defined(MBEDTLS_BIGNUM_C) || !defined(MBEDTLS_ENTROPY_C) ||  \
#else
#include "mbedtls/error.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/md.h"
#include "mbedtls/pk.h"
#include <stdio.h>
#include <string.h>
#if MBEDTLS_ECDSA_MAX_LEN > MBEDTLS_MPI_MAX_SIZE
#define SIGNATURE_MAX_SIZE MBEDTLS_ECDSA_MAX_LEN
#else
#define SIGNATURE_MAX_SIZE MBEDTLS_MPI_MAX_SIZE
#endif
#if defined(_WIN32)
#endif
#if defined(MBEDTLS_ERROR_C)
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_ENTROPY_C &&
