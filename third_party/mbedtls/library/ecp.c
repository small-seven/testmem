#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_ECP_INTERNAL_ALT)
#endif
#if defined(MBEDTLS_ECP_C)
#include "mbedtls/ecp.h"
#include "mbedtls/threading.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if !defined(MBEDTLS_ECP_ALT)
#define ECP_VALIDATE_RET( cond )    \
#define ECP_VALIDATE( cond )        \
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#include <stdio.h>
#define mbedtls_printf     printf
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#include "mbedtls/ecp_internal.h"
#if ( defined(__ARMCC_VERSION) || defined(_MSC_VER) ) && \
#define inline __inline
#endif
#if defined(MBEDTLS_SELF_TEST)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
static void ecp_restart_rsm_free( mbedtls_ecp_restart_mul_ctx *ctx )
{
    unsigned char i;

    if( ctx == NULL )
        return;

    mbedtls_ecp_point_free( &ctx->R );

    if( ctx->T != NULL )
    {
        for( i = 0; i < ctx->T_size; i++ )
            mbedtls_ecp_point_free( ctx->T + i );
        mbedtls_free( ctx->T );
    }

    ecp_restart_rsm_init( ctx );
}
static void ecp_restart_ma_free( mbedtls_ecp_restart_muladd_ctx *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_ecp_point_free( &ctx->mP );
    mbedtls_ecp_point_free( &ctx->R );

    ecp_restart_ma_init( ctx );
}
void mbedtls_ecp_restart_free( mbedtls_ecp_restart_ctx *ctx )
{
    if( ctx == NULL )
        return;

    ecp_restart_rsm_free( ctx->rsm );
    mbedtls_free( ctx->rsm );

    ecp_restart_ma_free( ctx->ma );
    mbedtls_free( ctx->ma );

    mbedtls_ecp_restart_init( ctx );
}
#define ECP_RS_ENTER( SUB )   do {                                      \
#define ECP_RS_LEAVE( SUB )   do {                                      \
#else /* MBEDTLS_ECP_RESTARTABLE */
#define ECP_RS_ENTER( sub )     (void) rs_ctx;
#define ECP_RS_LEAVE( sub )     (void) rs_ctx;
#endif /* MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_ECP_DP_SECP192R1_ENABLED) ||   \
#define ECP_SHORTWEIERSTRASS
#endif
#if defined(MBEDTLS_ECP_DP_CURVE25519_ENABLED) || \
#define ECP_MONTGOMERY
#endif
typedef enum
{
    ECP_TYPE_NONE = 0,
    ECP_TYPE_SHORT_WEIERSTRASS,    /* y^2 = x^3 + a x + b      */
    ECP_TYPE_MONTGOMERY,           /* y^2 = x^3 + a x^2 + x    */
} ecp_curve_type;
#if defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_BP512R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_BP384R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP256K1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_BP256R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP224R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP224K1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP192R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP192K1_ENABLED)
#endif
#define ECP_NB_CURVES   sizeof( ecp_supported_curves ) /    \
void mbedtls_ecp_point_free( mbedtls_ecp_point *pt )
{
    if( pt == NULL )
        return;

    mbedtls_mpi_free( &( pt->X ) );
    mbedtls_mpi_free( &( pt->Y ) );
    mbedtls_mpi_free( &( pt->Z ) );
}
void mbedtls_ecp_group_free( mbedtls_ecp_group *grp )
{
    size_t i;

    if( grp == NULL )
        return;

    if( grp->h != 1 )
    {
        mbedtls_mpi_free( &grp->P );
        mbedtls_mpi_free( &grp->A );
        mbedtls_mpi_free( &grp->B );
        mbedtls_ecp_point_free( &grp->G );
        mbedtls_mpi_free( &grp->N );
    }

    if( grp->T != NULL )
    {
        for( i = 0; i < grp->T_size; i++ )
            mbedtls_ecp_point_free( &grp->T[i] );
        mbedtls_free( grp->T );
    }

    mbedtls_platform_zeroize( grp, sizeof( mbedtls_ecp_group ) );
}
void mbedtls_ecp_keypair_free( mbedtls_ecp_keypair *key )
{
    if( key == NULL )
        return;

    mbedtls_ecp_group_free( &key->grp );
    mbedtls_mpi_free( &key->d );
    mbedtls_ecp_point_free( &key->Q );
}
#if defined(MBEDTLS_SELF_TEST)
#define INC_MUL_COUNT   mul_count++;
#else
#define INC_MUL_COUNT
#endif
#define MOD_MUL( N )                                                    \
#define MOD_SUB( N )                                                    \
#define MOD_ADD( N )                                                    \
#if defined(ECP_SHORTWEIERSTRASS)
#if defined(MBEDTLS_ECP_NORMALIZE_JAC_ALT)
#endif /* MBEDTLS_ECP_NORMALIZE_JAC_ALT */
#if defined(MBEDTLS_ECP_NORMALIZE_JAC_MANY_ALT)
#endif
#if defined(MBEDTLS_SELF_TEST)
#endif
#if defined(MBEDTLS_ECP_DOUBLE_JAC_ALT)
#endif /* MBEDTLS_ECP_DOUBLE_JAC_ALT */
#if defined(MBEDTLS_SELF_TEST)
#endif
#if defined(MBEDTLS_ECP_ADD_MIXED_ALT)
#endif /* MBEDTLS_ECP_ADD_MIXED_ALT */
#if defined(MBEDTLS_ECP_RANDOMIZE_JAC_ALT)
#endif /* MBEDTLS_ECP_RANDOMIZE_JAC_ALT */
#if MBEDTLS_ECP_WINDOW_SIZE < 2 || MBEDTLS_ECP_WINDOW_SIZE > 7
#error "MBEDTLS_ECP_WINDOW_SIZE out of bounds"
#endif
#define COMB_MAX_D      ( MBEDTLS_ECP_MAX_BITS + 1 ) / 2
#define COMB_MAX_PRE    ( 1 << ( MBEDTLS_ECP_WINDOW_SIZE - 1 ) )
#if defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if !defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if MBEDTLS_ECP_FIXED_POINT_OPTIM == 1
#else
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#endif /* ECP_SHORTWEIERSTRASS */
#if defined(ECP_MONTGOMERY)
#if defined(MBEDTLS_ECP_NORMALIZE_MXZ_ALT)
#endif /* MBEDTLS_ECP_NORMALIZE_MXZ_ALT */
#if defined(MBEDTLS_ECP_RANDOMIZE_MXZ_ALT)
#endif /* MBEDTLS_ECP_RANDOMIZE_MXZ_ALT */
#if defined(MBEDTLS_ECP_DOUBLE_ADD_MXZ_ALT)
#endif /* MBEDTLS_ECP_DOUBLE_ADD_MXZ_ALT */
#endif /* ECP_MONTGOMERY */
#if defined(MBEDTLS_ECP_INTERNAL_ALT)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_INTERNAL_ALT)
#endif /* MBEDTLS_ECP_INTERNAL_ALT */
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(ECP_MONTGOMERY)
#endif
#if defined(ECP_SHORTWEIERSTRASS)
#endif
#if defined(MBEDTLS_ECP_INTERNAL_ALT)
#endif /* MBEDTLS_ECP_INTERNAL_ALT */
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(ECP_SHORTWEIERSTRASS)
#endif /* ECP_SHORTWEIERSTRASS */
#if defined(MBEDTLS_ECP_INTERNAL_ALT)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif /* MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_INTERNAL_ALT)
#endif /* MBEDTLS_ECP_INTERNAL_ALT */
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_INTERNAL_ALT)
#endif /* MBEDTLS_ECP_INTERNAL_ALT */
#if defined(ECP_MONTGOMERY)
#endif /* ECP_MONTGOMERY */
#if defined(ECP_MONTGOMERY)
#endif
#if defined(ECP_SHORTWEIERSTRASS)
#endif
#if defined(ECP_MONTGOMERY)
#endif /* ECP_MONTGOMERY */
#if defined(ECP_SHORTWEIERSTRASS)
#endif /* ECP_SHORTWEIERSTRASS */
#if defined(ECP_MONTGOMERY)
#endif /* ECP_MONTGOMERY */
#if defined(ECP_SHORTWEIERSTRASS)
#endif /* ECP_SHORTWEIERSTRASS */
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_ECP_DP_SECP192R1_ENABLED)
#else
#endif
#endif /* MBEDTLS_SELF_TEST */
#endif /* !MBEDTLS_ECP_ALT */
#endif /* MBEDTLS_ECP_C */
