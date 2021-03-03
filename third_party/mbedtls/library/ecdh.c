#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_ECDH_C)
#include "mbedtls/ecdh.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#define ECDH_VALIDATE_RET( cond )    \
#define ECDH_VALIDATE( cond )        \
#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
typedef mbedtls_ecdh_context mbedtls_ecdh_context_mbed;
#endif

static mbedtls_ecp_group_id mbedtls_ecdh_grp_id(
    const mbedtls_ecdh_context *ctx )
{
#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
    return( ctx->grp.id );
#else
    return( ctx->grp_id );
#endif
}
#if !defined(MBEDTLS_ECDH_GEN_PUBLIC_ALT)
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#endif /* !MBEDTLS_ECDH_GEN_PUBLIC_ALT */
#if !defined(MBEDTLS_ECDH_COMPUTE_SHARED_ALT)
#endif /* !MBEDTLS_ECDH_COMPUTE_SHARED_ALT */
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
#else
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
#else
#endif
static void ecdh_free_internal( mbedtls_ecdh_context_mbed *ctx )
{
    mbedtls_ecp_group_free( &ctx->grp );
    mbedtls_mpi_free( &ctx->d  );
    mbedtls_ecp_point_free( &ctx->Q   );
    mbedtls_ecp_point_free( &ctx->Qp  );
    mbedtls_mpi_free( &ctx->z  );

#if defined(MBEDTLS_ECP_RESTARTABLE)
    mbedtls_ecp_restart_free( &ctx->rs );
#endif
}
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
void mbedtls_ecdh_free( mbedtls_ecdh_context *ctx )
{
    if( ctx == NULL )
        return;

#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
    mbedtls_ecp_point_free( &ctx->Vi );
    mbedtls_ecp_point_free( &ctx->Vf );
    mbedtls_mpi_free( &ctx->_d );
    ecdh_free_internal( ctx );
#else
    switch( ctx->var )
    {
        case MBEDTLS_ECDH_VARIANT_MBEDTLS_2_0:
            ecdh_free_internal( &ctx->ctx.mbed_ecdh );
            break;
        default:
            break;
    }

    ctx->point_format = MBEDTLS_ECP_PF_UNCOMPRESSED;
    ctx->var = MBEDTLS_ECDH_VARIANT_NONE;
    ctx->grp_id = MBEDTLS_ECP_DP_NONE;
#endif
}
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif /* MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif
#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
#else
#endif
#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
#else
#endif
#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
#else
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif /* MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
#else
#endif
#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
#else
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif /* MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
#else
#endif
#endif /* MBEDTLS_ECDH_C */
