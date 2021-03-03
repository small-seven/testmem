#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_GCM_C)
#include "mbedtls/gcm.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_AESNI_C)
#include "mbedtls/aesni.h"
#endif
#if defined(MBEDTLS_SELF_TEST) && defined(MBEDTLS_AES_C)
#include "mbedtls/aes.h"
#include "mbedtls/platform.h"
#if !defined(MBEDTLS_PLATFORM_C)
#include <stdio.h>
#define mbedtls_printf printf
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST && MBEDTLS_AES_C */
#if !defined(MBEDTLS_GCM_ALT)
#define GCM_VALIDATE_RET( cond ) \
#define GCM_VALIDATE( cond ) \
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i)                            \
#endif
#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i)                            \
#endif
#if defined(MBEDTLS_AESNI_C) && defined(MBEDTLS_HAVE_X86_64)
#endif
#if defined(MBEDTLS_AESNI_C) && defined(MBEDTLS_HAVE_X86_64)
#endif /* MBEDTLS_AESNI_C && MBEDTLS_HAVE_X86_64 */
void mbedtls_gcm_free( mbedtls_gcm_context *ctx )
{
    if( ctx == NULL )
        return;
    mbedtls_cipher_free( &ctx->cipher_ctx );
    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_gcm_context ) );
}
#endif /* !MBEDTLS_GCM_ALT */
#if defined(MBEDTLS_SELF_TEST) && defined(MBEDTLS_AES_C)
#define MAX_TESTS   6
#endif /* MBEDTLS_SELF_TEST && MBEDTLS_AES_C */
#endif /* MBEDTLS_GCM_C */
