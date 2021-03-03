#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_ECJPAKE_C)
#include "mbedtls/ecjpake.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if !defined(MBEDTLS_ECJPAKE_ALT)
#define ECJPAKE_VALIDATE_RET( cond )    \
#define ECJPAKE_VALIDATE( cond )        \
#define ID_MINE     ( ecjpake_id[ ctx->role ] )
#define ID_PEER     ( ecjpake_id[ 1 - ctx->role ] )
void mbedtls_ecjpake_free( mbedtls_ecjpake_context *ctx )
{
    if( ctx == NULL )
        return;

    ctx->md_info = NULL;
    mbedtls_ecp_group_free( &ctx->grp );

    mbedtls_ecp_point_free( &ctx->Xm1 );
    mbedtls_ecp_point_free( &ctx->Xm2 );
    mbedtls_ecp_point_free( &ctx->Xp1 );
    mbedtls_ecp_point_free( &ctx->Xp2 );
    mbedtls_ecp_point_free( &ctx->Xp  );

    mbedtls_mpi_free( &ctx->xm1 );
    mbedtls_mpi_free( &ctx->xm2 );
    mbedtls_mpi_free( &ctx->s   );
}
#define ECJPAKE_HASH_BUF_LEN    ( 3 * ( 4 + MBEDTLS_ECP_MAX_PT_LEN ) + 4 + 6 )
#undef ID_MINE
#undef ID_PEER
#endif /* ! MBEDTLS_ECJPAKE_ALT */
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf     printf
#endif
#if !defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED) || \
#else
#define TEST_ASSERT( x )    \
#undef TEST_ASSERT
#endif /* MBEDTLS_ECP_DP_SECP256R1_ENABLED && MBEDTLS_SHA256_C */
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_ECJPAKE_C */
