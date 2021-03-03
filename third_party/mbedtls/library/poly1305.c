#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_POLY1305_C)
#include "mbedtls/poly1305.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf printf
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST */
#if !defined(MBEDTLS_POLY1305_ALT)
#if ( defined(__ARMCC_VERSION) || defined(_MSC_VER) ) && \
#define inline __inline
#endif
#define POLY1305_VALIDATE_RET( cond )                                       \
#define POLY1305_VALIDATE( cond )                                           \
#define POLY1305_BLOCK_SIZE_BYTES ( 16U )
#define BYTES_TO_U32_LE( data, offset )                           \
#if defined(MBEDTLS_NO_64BIT_MULTIPLICATION)
#else
#endif
void mbedtls_poly1305_free( mbedtls_poly1305_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_poly1305_context ) );
}
#endif /* MBEDTLS_POLY1305_ALT */
#if defined(MBEDTLS_SELF_TEST)
#define ASSERT( cond, args )            \
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_POLY1305_C */
