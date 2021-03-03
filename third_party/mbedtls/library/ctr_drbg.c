#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_CTR_DRBG_C)
#include "mbedtls/ctr_drbg.h"
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
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST */
#if defined(MBEDTLS_THREADING_C)
#endif
void mbedtls_ctr_drbg_free( mbedtls_ctr_drbg_context *ctx )
{
    if( ctx == NULL )
        return;

#if defined(MBEDTLS_THREADING_C)
    mbedtls_mutex_free( &ctx->mutex );
#endif
    mbedtls_aes_free( &ctx->aes_ctx );
    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_ctr_drbg_context ) );
}
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif /* MBEDTLS_DEPRECATED_REMOVED */
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_FS_IO)
#endif /* MBEDTLS_FS_IO */
#if defined(MBEDTLS_SELF_TEST)
#define CHK( c )    if( (c) != 0 )                          \
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_CTR_DRBG_C */
