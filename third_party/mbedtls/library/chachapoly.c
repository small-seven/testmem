#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_CHACHAPOLY_C)
#include "mbedtls/chachapoly.h"
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
#if !defined(MBEDTLS_CHACHAPOLY_ALT)
#define CHACHAPOLY_VALIDATE_RET( cond )                                       \
#define CHACHAPOLY_VALIDATE( cond )                                           \
#define CHACHAPOLY_STATE_INIT       ( 0 )
#define CHACHAPOLY_STATE_AAD        ( 1 )
#define CHACHAPOLY_STATE_CIPHERTEXT ( 2 ) /* Encrypting or decrypting */
#define CHACHAPOLY_STATE_FINISHED   ( 3 )
void mbedtls_chachapoly_free( mbedtls_chachapoly_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_chacha20_free( &ctx->chacha20_ctx );
    mbedtls_poly1305_free( &ctx->poly1305_ctx );
    ctx->aad_len        = 0U;
    ctx->ciphertext_len = 0U;
    ctx->state          = CHACHAPOLY_STATE_INIT;
    ctx->mode           = MBEDTLS_CHACHAPOLY_ENCRYPT;
}
#endif /* MBEDTLS_CHACHAPOLY_ALT */
#if defined(MBEDTLS_SELF_TEST)
#define ASSERT( cond, args )            \
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_CHACHAPOLY_C */
