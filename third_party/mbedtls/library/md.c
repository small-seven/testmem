#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_MD_C)
#include "mbedtls/md.h"
#include "mbedtls/md_internal.h"
#include "mbedtls/platform_util.h"
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#include <string.h>
#if defined(MBEDTLS_FS_IO)
#include <stdio.h>
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA1_C)
#endif
#if defined(MBEDTLS_RIPEMD160_C)
#endif
#if defined(MBEDTLS_MD5_C)
#endif
#if defined(MBEDTLS_MD4_C)
#endif
#if defined(MBEDTLS_MD2_C)
#endif
#if defined(MBEDTLS_MD2_C)
#endif
#if defined(MBEDTLS_MD4_C)
#endif
#if defined(MBEDTLS_MD5_C)
#endif
#if defined(MBEDTLS_RIPEMD160_C)
#endif
#if defined(MBEDTLS_SHA1_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#if defined(MBEDTLS_MD2_C)
#endif
#if defined(MBEDTLS_MD4_C)
#endif
#if defined(MBEDTLS_MD5_C)
#endif
#if defined(MBEDTLS_RIPEMD160_C)
#endif
#if defined(MBEDTLS_SHA1_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
void mbedtls_md_free( mbedtls_md_context_t *ctx )
{
    if( ctx == NULL || ctx->md_info == NULL )
        return;

    if( ctx->md_ctx != NULL )
        ctx->md_info->ctx_free_func( ctx->md_ctx );

    if( ctx->hmac_ctx != NULL )
    {
        mbedtls_platform_zeroize( ctx->hmac_ctx,
                                  2 * ctx->md_info->block_size );
        mbedtls_free( ctx->hmac_ctx );
    }

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_md_context_t ) );
}
#if ! defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if defined(MBEDTLS_FS_IO)
#endif /* MBEDTLS_FS_IO */
#endif /* MBEDTLS_MD_C */
