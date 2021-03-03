#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_DES_C)
#include "mbedtls/des.h"
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
#if !defined(MBEDTLS_DES_ALT)
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i)                            \
#endif
#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i)                            \
#endif
#define DES_IP(X,Y)                                                       \
#define DES_FP(X,Y)                                                       \
#define DES_ROUND(X,Y)                              \
#define SWAP(a,b)                                       \
void mbedtls_des_free( mbedtls_des_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_des_context ) );
}
void mbedtls_des3_free( mbedtls_des3_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_des3_context ) );
}
#define WEAK_KEY_COUNT 16
#if !defined(MBEDTLS_DES_SETKEY_ALT)
#endif /* !MBEDTLS_DES_SETKEY_ALT */
#if !defined(MBEDTLS_DES_CRYPT_ECB_ALT)
#endif /* !MBEDTLS_DES_CRYPT_ECB_ALT */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if !defined(MBEDTLS_DES3_CRYPT_ECB_ALT)
#endif /* !MBEDTLS_DES3_CRYPT_ECB_ALT */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* !MBEDTLS_DES_ALT */
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_DES_C */
