#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_SHA1_C)
#include "mbedtls/sha1.h"
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
#define SHA1_VALIDATE_RET(cond)                             \
#define SHA1_VALIDATE(cond)  MBEDTLS_INTERNAL_VALIDATE( cond )
#if !defined(MBEDTLS_SHA1_ALT)
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i)                            \
#endif
#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i)                            \
#endif
void mbedtls_sha1_free( mbedtls_sha1_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_sha1_context ) );
}
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if !defined(MBEDTLS_SHA1_PROCESS_ALT)
#define S(x,n) (((x) << (n)) | (((x) & 0xFFFFFFFF) >> (32 - (n))))
#define R(t)                                                    \
#define P(a,b,c,d,e,x)                                          \
#define F(x,y,z) ((z) ^ ((x) & ((y) ^ (z))))
#define K 0x5A827999
#undef K
#undef F
#define F(x,y,z) ((x) ^ (y) ^ (z))
#define K 0x6ED9EBA1
#undef K
#undef F
#define F(x,y,z) (((x) & (y)) | ((z) & ((x) | (y))))
#define K 0x8F1BBCDC
#undef K
#undef F
#define F(x,y,z) ((x) ^ (y) ^ (z))
#define K 0xCA62C1D6
#undef K
#undef F
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#endif /* !MBEDTLS_SHA1_PROCESS_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#endif /* !MBEDTLS_SHA1_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if defined(MBEDTLS_SELF_TEST)
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_SHA1_C */
