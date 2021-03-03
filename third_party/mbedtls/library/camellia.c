#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_CAMELLIA_C)
#include "mbedtls/camellia.h"
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
#if !defined(MBEDTLS_CAMELLIA_ALT)
#define CAMELLIA_VALIDATE_RET( cond )                                       \
#define CAMELLIA_VALIDATE( cond )                                           \
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i)                            \
#endif
#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i)                            \
#endif
#if defined(MBEDTLS_CAMELLIA_SMALL_MEMORY)
#define SBOX1(n) FSb[(n)]
#define SBOX2(n) (unsigned char)((FSb[(n)] >> 7 ^ FSb[(n)] << 1) & 0xff)
#define SBOX3(n) (unsigned char)((FSb[(n)] >> 1 ^ FSb[(n)] << 7) & 0xff)
#define SBOX4(n) FSb[((n) << 1 ^ (n) >> 7) &0xff]
#else /* MBEDTLS_CAMELLIA_SMALL_MEMORY */
#define SBOX1(n) FSb[(n)]
#define SBOX2(n) FSb2[(n)]
#define SBOX3(n) FSb3[(n)]
#define SBOX4(n) FSb4[(n)]
#endif /* MBEDTLS_CAMELLIA_SMALL_MEMORY */
#define ROTL(DEST, SRC, SHIFT)                                      \
#define FL(XL, XR, KL, KR)                                          \
#define FLInv(YL, YR, KL, KR)                                       \
#define SHIFT_AND_PLACE(INDEX, OFFSET)                      \
void mbedtls_camellia_free( mbedtls_camellia_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_camellia_context ) );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#endif /* !MBEDTLS_CAMELLIA_ALT */
#if defined(MBEDTLS_SELF_TEST)
#define CAMELLIA_TESTS_ECB  2
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#define CAMELLIA_TESTS_CBC  3
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_CAMELLIA_C */
