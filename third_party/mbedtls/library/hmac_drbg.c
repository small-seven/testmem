#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_HMAC_DRBG_C)
#include "mbedtls/hmac_drbg.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_FS_IO)
#include <stdio.h>
#endif
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf printf
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_PLATFORM_C */
#if defined(MBEDTLS_THREADING_C)
#endif
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif /* MBEDTLS_DEPRECATED_REMOVED */
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
void mbedtls_hmac_drbg_free( mbedtls_hmac_drbg_context *ctx )
{
    if( ctx == NULL )
        return;

#if defined(MBEDTLS_THREADING_C)
    mbedtls_mutex_free( &ctx->mutex );
#endif
    mbedtls_md_free( &ctx->md_ctx );
    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_hmac_drbg_context ) );
}
#if defined(MBEDTLS_FS_IO)
#endif /* MBEDTLS_FS_IO */
#if defined(MBEDTLS_SELF_TEST)
#if !defined(MBEDTLS_SHA1_C)
#else
#define OUTPUT_LEN  80
#define CHK( c )    if( (c) != 0 )                          \
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_HMAC_DRBG_C */
