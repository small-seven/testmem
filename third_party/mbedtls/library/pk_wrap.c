#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PK_C)
#include "mbedtls/pk_internal.h"
#include "mbedtls/rsa.h"
#include <string.h>
#if defined(MBEDTLS_ECP_C)
#include "mbedtls/ecp.h"
#endif
#if defined(MBEDTLS_ECDSA_C)
#include "mbedtls/ecdsa.h"
#endif
#if defined(MBEDTLS_PK_RSA_ALT_SUPPORT)
#include "mbedtls/platform_util.h"
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#include <limits.h>
#include <stdint.h>
#if defined(MBEDTLS_RSA_C)
#if SIZE_MAX > UINT_MAX
#endif /* SIZE_MAX > UINT_MAX */
#if SIZE_MAX > UINT_MAX
#endif /* SIZE_MAX > UINT_MAX */
static void *rsa_alloc_wrap( void )
{
    void *ctx = mbedtls_calloc( 1, sizeof( mbedtls_rsa_context ) );

    if( ctx != NULL )
        mbedtls_rsa_init( (mbedtls_rsa_context *) ctx, 0, 0 );

    return( ctx );
}
static void rsa_free_wrap( void *ctx )
{
    mbedtls_rsa_free( (mbedtls_rsa_context *) ctx );
    mbedtls_free( ctx );
}
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECP_C)
#if defined(MBEDTLS_ECDSA_C)
#if defined(MBEDTLS_ECP_RESTARTABLE)
typedef struct
{
    mbedtls_ecdsa_restart_ctx ecdsa_rs;
    mbedtls_ecdsa_context ecdsa_ctx;
} eckey_restart_ctx;
static void eckey_rs_free( void *ctx )
{
    eckey_restart_ctx *rs_ctx;

    if( ctx == NULL)
        return;

    rs_ctx = ctx;
    mbedtls_ecdsa_restart_free( &rs_ctx->ecdsa_rs );
    mbedtls_ecdsa_free( &rs_ctx->ecdsa_ctx );

    mbedtls_free( ctx );
}
#endif /* MBEDTLS_ECP_RESTARTABLE */
#endif /* MBEDTLS_ECDSA_C */
static void *eckey_alloc_wrap( void )
{
    void *ctx = mbedtls_calloc( 1, sizeof( mbedtls_ecp_keypair ) );

    if( ctx != NULL )
        mbedtls_ecp_keypair_init( ctx );

    return( ctx );
}
static void eckey_free_wrap( void *ctx )
{
    mbedtls_ecp_keypair_free( (mbedtls_ecp_keypair *) ctx );
    mbedtls_free( ctx );
}
#if defined(MBEDTLS_ECDSA_C)
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#else /* MBEDTLS_ECDSA_C */
#endif /* MBEDTLS_ECDSA_C */
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_ECDSA_C)
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif /* MBEDTLS_ECP_RESTARTABLE */
static void *ecdsa_alloc_wrap( void )
{
    void *ctx = mbedtls_calloc( 1, sizeof( mbedtls_ecdsa_context ) );

    if( ctx != NULL )
        mbedtls_ecdsa_init( (mbedtls_ecdsa_context *) ctx );

    return( ctx );
}
static void ecdsa_free_wrap( void *ctx )
{
    mbedtls_ecdsa_free( (mbedtls_ecdsa_context *) ctx );
    mbedtls_free( ctx );
}
#if defined(MBEDTLS_ECP_RESTARTABLE)
static void ecdsa_rs_free( void *ctx )
{
    mbedtls_ecdsa_restart_free( ctx );
    mbedtls_free( ctx );
}
#endif /* MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#endif /* MBEDTLS_ECDSA_C */
#if defined(MBEDTLS_PK_RSA_ALT_SUPPORT)
#if SIZE_MAX > UINT_MAX
#endif /* SIZE_MAX > UINT_MAX */
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
static void *rsa_alt_alloc_wrap( void )
{
    void *ctx = mbedtls_calloc( 1, sizeof( mbedtls_rsa_alt_context ) );

    if( ctx != NULL )
        memset( ctx, 0, sizeof( mbedtls_rsa_alt_context ) );

    return( ctx );
}
static void rsa_alt_free_wrap( void *ctx )
{
    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_rsa_alt_context ) );
    mbedtls_free( ctx );
}
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_RSA_C)
#else
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#endif /* MBEDTLS_PK_RSA_ALT_SUPPORT */
#endif /* MBEDTLS_PK_C */
