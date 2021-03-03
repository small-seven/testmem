#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_CCM_C)
#include "mbedtls/ccm.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_SELF_TEST) && defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf printf
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST && MBEDTLS_AES_C */
#if !defined(MBEDTLS_CCM_ALT)
#define CCM_VALIDATE_RET( cond ) \
#define CCM_VALIDATE( cond ) \
#define CCM_ENCRYPT 0
#define CCM_DECRYPT 1
void mbedtls_ccm_free( mbedtls_ccm_context *ctx )
{
    if( ctx == NULL )
        return;
    mbedtls_cipher_free( &ctx->cipher_ctx );
    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_ccm_context ) );
}
#define UPDATE_CBC_MAC                                                      \
#define CTR_CRYPT( dst, src, len  )                                            \
#endif /* !MBEDTLS_CCM_ALT */
#if defined(MBEDTLS_SELF_TEST) && defined(MBEDTLS_AES_C)
#define NB_TESTS 3
#define CCM_SELFTEST_PT_MAX_LEN 24
#define CCM_SELFTEST_CT_MAX_LEN 32
#endif /* MBEDTLS_SELF_TEST && MBEDTLS_AES_C */
#endif /* MBEDTLS_CCM_C */
