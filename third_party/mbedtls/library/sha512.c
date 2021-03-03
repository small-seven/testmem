#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_SHA512_C)
#include "mbedtls/sha512.h"
#include "mbedtls/platform_util.h"
#if defined(_MSC_VER) || defined(__WATCOMC__)
#else
#endif
#include <string.h>
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#include <stdlib.h>
#define mbedtls_printf printf
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST */
#define SHA512_VALIDATE_RET(cond)                           \
#define SHA512_VALIDATE(cond)  MBEDTLS_INTERNAL_VALIDATE( cond )
#if !defined(MBEDTLS_SHA512_ALT)
#ifndef GET_UINT64_BE
#define GET_UINT64_BE(n,b,i)                            \
#endif /* GET_UINT64_BE */
#ifndef PUT_UINT64_BE
#define PUT_UINT64_BE(n,b,i)                            \
#endif /* PUT_UINT64_BE */
void mbedtls_sha512_free( mbedtls_sha512_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_sha512_context ) );
}
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if !defined(MBEDTLS_SHA512_PROCESS_ALT)
#define  SHR(x,n) ((x) >> (n))
#define ROTR(x,n) (SHR((x),(n)) | ((x) << (64 - (n))))
#define S0(x) (ROTR(x, 1) ^ ROTR(x, 8) ^  SHR(x, 7))
#define S1(x) (ROTR(x,19) ^ ROTR(x,61) ^  SHR(x, 6))
#define S2(x) (ROTR(x,28) ^ ROTR(x,34) ^ ROTR(x,39))
#define S3(x) (ROTR(x,14) ^ ROTR(x,18) ^ ROTR(x,41))
#define F0(x,y,z) (((x) & (y)) | ((z) & ((x) | (y))))
#define F1(x,y,z) ((z) ^ ((x) & ((y) ^ (z))))
#define P(a,b,c,d,e,f,g,h,x,K)                                  \
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#endif /* !MBEDTLS_SHA512_PROCESS_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#endif /* !MBEDTLS_SHA512_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if defined(MBEDTLS_SELF_TEST)
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_SHA512_C */
