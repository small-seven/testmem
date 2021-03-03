#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_BLOWFISH_C)
#include "mbedtls/blowfish.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if !defined(MBEDTLS_BLOWFISH_ALT)
#define BLOWFISH_VALIDATE_RET( cond )                                       \
#define BLOWFISH_VALIDATE( cond )                                           \
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i)                            \
#endif
#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i)                            \
#endif
void mbedtls_blowfish_free( mbedtls_blowfish_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_blowfish_context ) );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /*MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#endif /* !MBEDTLS_BLOWFISH_ALT */
#endif /* MBEDTLS_BLOWFISH_C */
