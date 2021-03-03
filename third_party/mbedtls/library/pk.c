#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PK_C)
#include "mbedtls/pk.h"
#include "mbedtls/pk_internal.h"
#include "mbedtls/platform_util.h"
#if defined(MBEDTLS_RSA_C)
#include "mbedtls/rsa.h"
#endif
#if defined(MBEDTLS_ECP_C)
#include "mbedtls/ecp.h"
#endif
#if defined(MBEDTLS_ECDSA_C)
#include "mbedtls/ecdsa.h"
#endif
#include <limits.h>
#include <stdint.h>
#define PK_VALIDATE_RET( cond )    \
#define PK_VALIDATE( cond )        \
void mbedtls_pk_free( mbedtls_pk_context *ctx )
{
    if( ctx == NULL )
        return;

    if ( ctx->pk_info != NULL )
        ctx->pk_info->ctx_free_func( ctx->pk_ctx );

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_pk_context ) );
}
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
void mbedtls_pk_restart_free( mbedtls_pk_restart_ctx *ctx )
{
    if( ctx == NULL || ctx->pk_info == NULL ||
        ctx->pk_info->rs_free_func == NULL )
    {
        return;
    }

    ctx->pk_info->rs_free_func( ctx->rs_ctx );

    ctx->pk_info = NULL;
    ctx->rs_ctx = NULL;
}
#endif /* MBEDTLS_ECDSA_C && MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_RSA_C)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#if defined(MBEDTLS_ECDSA_C)
#endif
#if defined(MBEDTLS_PK_RSA_ALT_SUPPORT)
#endif /* MBEDTLS_PK_RSA_ALT_SUPPORT */
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif /* MBEDTLS_ECDSA_C && MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#else /* MBEDTLS_ECDSA_C && MBEDTLS_ECP_RESTARTABLE */
#endif /* MBEDTLS_ECDSA_C && MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_PKCS1_V21)
#if SIZE_MAX > UINT_MAX
#endif /* SIZE_MAX > UINT_MAX */
#else
#endif /* MBEDTLS_RSA_C && MBEDTLS_PKCS1_V21 */
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#else /* MBEDTLS_ECDSA_C && MBEDTLS_ECP_RESTARTABLE */
#endif /* MBEDTLS_ECDSA_C && MBEDTLS_ECP_RESTARTABLE */
#endif /* MBEDTLS_PK_C */
