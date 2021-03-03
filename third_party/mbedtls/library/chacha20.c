#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_CHACHA20_C)
#include "mbedtls/chacha20.h"
#include "mbedtls/platform_util.h"
#include <stddef.h>
#include <string.h>
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf printf
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST */
#if !defined(MBEDTLS_CHACHA20_ALT)
#if ( defined(__ARMCC_VERSION) || defined(_MSC_VER) ) && \
#define inline __inline
#endif
#define CHACHA20_VALIDATE_RET( cond )                                       \
#define CHACHA20_VALIDATE( cond )                                           \
#define BYTES_TO_U32_LE( data, offset )                           \
#define ROTL32( value, amount ) \
#define CHACHA20_CTR_INDEX ( 12U )
#define CHACHA20_BLOCK_SIZE_BYTES ( 4U * 16U )
void mbedtls_chacha20_free( mbedtls_chacha20_context *ctx )
{
    if( ctx != NULL )
    {
        mbedtls_platform_zeroize( ctx, sizeof( mbedtls_chacha20_context ) );
    }
}
#endif /* !MBEDTLS_CHACHA20_ALT */
#if defined(MBEDTLS_SELF_TEST)
#define ASSERT( cond, args )            \
#endif /* MBEDTLS_SELF_TEST */
#endif /* !MBEDTLS_CHACHA20_C */
