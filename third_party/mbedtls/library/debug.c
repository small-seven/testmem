#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_DEBUG_C)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc      calloc
#define mbedtls_free        free
#define mbedtls_time_t      time_t
#define mbedtls_snprintf    snprintf
#endif
#include "mbedtls/debug.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#if ( defined(__ARMCC_VERSION) || defined(_MSC_VER) ) && \
#define inline __inline
#endif
#define DEBUG_BUF_SIZE      512
#if defined(MBEDTLS_THREADING_C)
#else
#endif
#if defined(_WIN32)
#if defined(_TRUNCATE) && !defined(__MINGW32__)
#else
#endif
#else
#endif
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_BIGNUM_C)
#endif /* MBEDTLS_BIGNUM_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_ECP_C)
#endif
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_ECDH_C)
#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
#else
#endif
#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
#else
#endif
#endif /* MBEDTLS_ECDH_C */
#endif /* MBEDTLS_DEBUG_C */
