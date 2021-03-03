#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_NIST_KW_C)
#include "mbedtls/nist_kw.h"
#include "mbedtls/platform_util.h"
#include <stdint.h>
#include <string.h>
#if defined(MBEDTLS_SELF_TEST) && defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf printf
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST && MBEDTLS_AES_C */
#if !defined(MBEDTLS_NIST_KW_ALT)
#define KW_SEMIBLOCK_LENGTH    8
#define MIN_SEMIBLOCKS_COUNT   3
static inline unsigned char mbedtls_nist_kw_safer_memcmp( const void *a, const void *b, size_t n )
{
    size_t i;
    volatile const unsigned char *A = (volatile const unsigned char *) a;
    volatile const unsigned char *B = (volatile const unsigned char *) b;
    volatile unsigned char diff = 0;

    for( i = 0; i < n; i++ )
    {
        /* Read volatile data in order before computing diff.
         * This avoids IAR compiler warning:
         * 'the order of volatile accesses is undefined ..' */
        unsigned char x = A[i], y = B[i];
        diff |= x ^ y;
    }

    return( diff );
}
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i)                            \
#endif
#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i)                            \
#endif
void mbedtls_nist_kw_free( mbedtls_nist_kw_context *ctx )
{
    mbedtls_cipher_free( &ctx->cipher_ctx );
    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_nist_kw_context ) );
}
#if SIZE_MAX > 0x1FFFFFFFFFFFFF8
#endif
#if SIZE_MAX > 0xFFFFFFFF
#endif
#if SIZE_MAX > 0x200000000000000
#endif
#if SIZE_MAX > 0x100000000
#endif
#endif /* !MBEDTLS_NIST_KW_ALT */
#if defined(MBEDTLS_SELF_TEST) && defined(MBEDTLS_AES_C)
#define KW_TESTS 3
#endif /* MBEDTLS_SELF_TEST && MBEDTLS_AES_C */
#endif /* MBEDTLS_NIST_KW_C */
