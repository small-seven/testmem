#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_ECDSA_C)
#include "mbedtls/ecdsa.h"
#include "mbedtls/asn1write.h"
#include <string.h>
#if defined(MBEDTLS_ECDSA_DETERMINISTIC)
#include "mbedtls/hmac_drbg.h"
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#include "mbedtls/platform_util.h"
#define ECDSA_VALIDATE_RET( cond )    \
#define ECDSA_VALIDATE( cond )        \
#if defined(MBEDTLS_ECP_RESTARTABLE)
static void ecdsa_restart_ver_free( mbedtls_ecdsa_restart_ver_ctx *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_mpi_free( &ctx->u1 );
    mbedtls_mpi_free( &ctx->u2 );

    ecdsa_restart_ver_init( ctx );
}
static void ecdsa_restart_sig_free( mbedtls_ecdsa_restart_sig_ctx *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_mpi_free( &ctx->k );
    mbedtls_mpi_free( &ctx->r );
}
#if defined(MBEDTLS_ECDSA_DETERMINISTIC)
static void ecdsa_restart_det_free( mbedtls_ecdsa_restart_det_ctx *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_hmac_drbg_free( &ctx->rng_ctx );

    ecdsa_restart_det_init( ctx );
}
#endif /* MBEDTLS_ECDSA_DETERMINISTIC */
#define ECDSA_RS_ECP    ( rs_ctx == NULL ? NULL : &rs_ctx->ecp )
#define ECDSA_BUDGET( ops )   \
#define ECDSA_RS_ENTER( SUB )   do {                                 \
#define ECDSA_RS_LEAVE( SUB )   do {                                 \
#else /* MBEDTLS_ECP_RESTARTABLE */
#define ECDSA_RS_ECP    NULL
#define ECDSA_BUDGET( ops )   /* no-op; for compatibility */
#define ECDSA_RS_ENTER( SUB )   (void) rs_ctx
#define ECDSA_RS_LEAVE( SUB )   (void) rs_ctx
#endif /* MBEDTLS_ECP_RESTARTABLE */
#if !defined(MBEDTLS_ECDSA_SIGN_ALT)
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif /* MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#endif /* !MBEDTLS_ECDSA_SIGN_ALT */
#if defined(MBEDTLS_ECDSA_DETERMINISTIC)
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif /* MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECDSA_SIGN_ALT)
#else
#if !defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif /* MBEDTLS_ECP_RESTARTABLE */
#if !defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#endif /* MBEDTLS_ECDSA_SIGN_ALT */
#endif /* MBEDTLS_ECDSA_DETERMINISTIC */
#if !defined(MBEDTLS_ECDSA_VERIFY_ALT)
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif /* MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#endif /* !MBEDTLS_ECDSA_VERIFY_ALT */
#if defined(MBEDTLS_ECDSA_DETERMINISTIC)
#else
#if defined(MBEDTLS_ECDSA_SIGN_ALT)
#else
#endif /* MBEDTLS_ECDSA_SIGN_ALT */
#endif /* MBEDTLS_ECDSA_DETERMINISTIC */
#if !defined(MBEDTLS_DEPRECATED_REMOVED) && \
#endif
#if defined(MBEDTLS_ECDSA_VERIFY_ALT)
#else
#endif /* MBEDTLS_ECDSA_VERIFY_ALT */
#if !defined(MBEDTLS_ECDSA_GENKEY_ALT)
#endif /* !MBEDTLS_ECDSA_GENKEY_ALT */
void mbedtls_ecdsa_free( mbedtls_ecdsa_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_ecp_keypair_free( ctx );
}
#if defined(MBEDTLS_ECP_RESTARTABLE)
#if defined(MBEDTLS_ECDSA_DETERMINISTIC)
#endif
void mbedtls_ecdsa_restart_free( mbedtls_ecdsa_restart_ctx *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_ecp_restart_free( &ctx->ecp );

    ecdsa_restart_ver_free( ctx->ver );
    mbedtls_free( ctx->ver );
    ctx->ver = NULL;

    ecdsa_restart_sig_free( ctx->sig );
    mbedtls_free( ctx->sig );
    ctx->sig = NULL;

#if defined(MBEDTLS_ECDSA_DETERMINISTIC)
    ecdsa_restart_det_free( ctx->det );
    mbedtls_free( ctx->det );
    ctx->det = NULL;
#endif
}
#endif /* MBEDTLS_ECP_RESTARTABLE */
#endif /* MBEDTLS_ECDSA_C */
