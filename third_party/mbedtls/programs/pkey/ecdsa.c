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
#if defined(MBEDTLS_ECDSA_C) && \
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/ecdsa.h"
#include "mbedtls/sha256.h"
#include <string.h>
#endif
#define VERBOSE
#define ECPARAMS    MBEDTLS_ECP_DP_SECP192R1
#if !defined(ECPARAMS)
#define ECPARAMS    mbedtls_ecp_curve_list()->grp_id
#endif
#if !defined(MBEDTLS_ECDSA_C) || !defined(MBEDTLS_SHA256_C) || \
#else
#if defined(VERBOSE)
#else
#define dump_buf( a, b, c )
#define dump_pubkey( a, b )
#endif
#if defined(_WIN32)
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_ECDSA_C && MBEDTLS_ENTROPY_C && MBEDTLS_CTR_DRBG_C &&
