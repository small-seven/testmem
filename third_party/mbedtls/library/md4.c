#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_MD4_C)
#include "mbedtls/md4.h"
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
#if !defined(MBEDTLS_MD4_ALT)
#ifndef GET_UINT32_LE
#define GET_UINT32_LE(n,b,i)                            \
#endif
#ifndef PUT_UINT32_LE
#define PUT_UINT32_LE(n,b,i)                                    \
#endif
void mbedtls_md4_free( mbedtls_md4_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_md4_context ) );
}
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if !defined(MBEDTLS_MD4_PROCESS_ALT)
#define S(x,n) (((x) << (n)) | (((x) & 0xFFFFFFFF) >> (32 - (n))))
#define F(x, y, z) (((x) & (y)) | ((~(x)) & (z)))
#define P(a,b,c,d,x,s)                           \
#undef P
#undef F
#define F(x,y,z) (((x) & (y)) | ((x) & (z)) | ((y) & (z)))
#define P(a,b,c,d,x,s)                          \
#undef P
#undef F
#define F(x,y,z) ((x) ^ (y) ^ (z))
#define P(a,b,c,d,x,s)                                  \
#undef F
#undef P
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#endif /* !MBEDTLS_MD4_PROCESS_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#endif /* !MBEDTLS_MD4_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if defined(MBEDTLS_SELF_TEST)
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_MD4_C */
