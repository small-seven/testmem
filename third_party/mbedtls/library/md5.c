#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_MD5_C)
#include "mbedtls/md5.h"
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
#if !defined(MBEDTLS_MD5_ALT)
#ifndef GET_UINT32_LE
#define GET_UINT32_LE(n,b,i)                            \
#endif
#ifndef PUT_UINT32_LE
#define PUT_UINT32_LE(n,b,i)                                    \
#endif
void mbedtls_md5_free( mbedtls_md5_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_md5_context ) );
}
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if !defined(MBEDTLS_MD5_PROCESS_ALT)
#define S(x,n)                                                          \
#define P(a,b,c,d,k,s,t)                                        \
#define F(x,y,z) ((z) ^ ((x) & ((y) ^ (z))))
#undef F
#define F(x,y,z) ((y) ^ ((z) & ((x) ^ (y))))
#undef F
#define F(x,y,z) ((x) ^ (y) ^ (z))
#undef F
#define F(x,y,z) ((y) ^ ((x) | ~(z)))
#undef F
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#endif /* !MBEDTLS_MD5_PROCESS_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#endif /* !MBEDTLS_MD5_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if defined(MBEDTLS_SELF_TEST)
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_MD5_C */
