#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_ARIA_C)
#include "mbedtls/aria.h"
#include <string.h>
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf printf
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST */
#if !defined(MBEDTLS_ARIA_ALT)
#include "mbedtls/platform_util.h"
#if ( defined(__ARMCC_VERSION) || defined(_MSC_VER) ) && \
#define inline __inline
#endif
#define ARIA_VALIDATE_RET( cond )                                       \
#define ARIA_VALIDATE( cond )                                           \
#ifndef GET_UINT32_LE
#define GET_UINT32_LE( n, b, i )                \
#endif
#ifndef PUT_UINT32_LE
#define PUT_UINT32_LE( n, b, i )                                \
#endif
#if defined(MBEDTLS_HAVE_ASM)
#if defined(__arm__) /* rev16 available from v6 up */
#if defined(__GNUC__) && \
#define ARIA_P1 aria_p1
#elif defined(__ARMCC_VERSION) && __ARMCC_VERSION < 6000000 && \
#define ARIA_P1 aria_p1
#endif
#endif /* arm */
#if defined(__GNUC__) && \
#define ARIA_P1(x) ARIA_P2( ARIA_P3( x ) )
#endif /* x86 gnuc */
#endif /* MBEDTLS_HAVE_ASM && GNUC */
#if !defined(ARIA_P1)
#define ARIA_P1(x) ((((x) >> 8) & 0x00FF00FF) ^ (((x) & 0x00FF00FF) << 8))
#endif
#define ARIA_P2(x) (((x) >> 16) ^ ((x) << 16))
#if defined(MBEDTLS_HAVE_ASM)
#if defined(__arm__) /* rev available from v6 up */
#if defined(__GNUC__) && \
#define ARIA_P3 aria_p3
#elif defined(__ARMCC_VERSION) && __ARMCC_VERSION < 6000000 && \
#define ARIA_P3 aria_p3
#endif
#endif /* arm */
#if defined(__GNUC__) && \
#define ARIA_P3 aria_p3
#endif /* x86 gnuc */
#endif /* MBEDTLS_HAVE_ASM && GNUC */
#if !defined(ARIA_P3)
#define ARIA_P3(x) ARIA_P2( ARIA_P1 ( x ) )
#endif
void mbedtls_aria_free( mbedtls_aria_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_aria_context ) );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#endif /* !MBEDTLS_ARIA_ALT */
#if defined(MBEDTLS_SELF_TEST)
#if (defined(MBEDTLS_CIPHER_MODE_CBC) || defined(MBEDTLS_CIPHER_MODE_CFB) || \
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) || defined(MBEDTLS_CIPHER_MODE_CFB))
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#define ARIA_SELF_TEST_IF_FAIL              \
#if (defined(MBEDTLS_CIPHER_MODE_CFB) || defined(MBEDTLS_CIPHER_MODE_CTR))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) || \
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_ARIA_C */
