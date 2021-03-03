#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_XTEA_C)
#include "mbedtls/xtea.h"
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
#if !defined(MBEDTLS_XTEA_ALT)
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i)                            \
#endif
#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i)                            \
#endif
void mbedtls_xtea_free( mbedtls_xtea_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_xtea_context ) );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* !MBEDTLS_XTEA_ALT */
#if defined(MBEDTLS_SELF_TEST)
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_XTEA_C */
