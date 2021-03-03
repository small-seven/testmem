#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_DHM_C)
#include "mbedtls/dhm.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_PEM_PARSE_C)
#include "mbedtls/pem.h"
#endif
#if defined(MBEDTLS_ASN1_PARSE_C)
#include "mbedtls/asn1.h"
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#include <stdio.h>
#define mbedtls_printf     printf
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#if !defined(MBEDTLS_DHM_ALT)
#define DHM_VALIDATE_RET( cond )    \
#define DHM_VALIDATE( cond )        \
#define DHM_MPI_EXPORT( X, n )                                          \
void mbedtls_dhm_free( mbedtls_dhm_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_mpi_free( &ctx->pX );
    mbedtls_mpi_free( &ctx->Vf );
    mbedtls_mpi_free( &ctx->Vi );
    mbedtls_mpi_free( &ctx->RP );
    mbedtls_mpi_free( &ctx->K  );
    mbedtls_mpi_free( &ctx->GY );
    mbedtls_mpi_free( &ctx->GX );
    mbedtls_mpi_free( &ctx->X  );
    mbedtls_mpi_free( &ctx->G  );
    mbedtls_mpi_free( &ctx->P  );

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_dhm_context ) );
}
#if defined(MBEDTLS_ASN1_PARSE_C)
#if defined(MBEDTLS_PEM_PARSE_C)
#endif /* MBEDTLS_PEM_PARSE_C */
#if defined(MBEDTLS_PEM_PARSE_C)
#else
#endif /* MBEDTLS_PEM_PARSE_C */
#if defined(MBEDTLS_PEM_PARSE_C)
#endif
#if defined(MBEDTLS_FS_IO)
#endif /* MBEDTLS_FS_IO */
#endif /* MBEDTLS_ASN1_PARSE_C */
#endif /* MBEDTLS_DHM_ALT */
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_PEM_PARSE_C)
#else /* MBEDTLS_PEM_PARSE_C */
#endif /* MBEDTLS_PEM_PARSE_C */
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_DHM_C */
