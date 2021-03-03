#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_X509_CRT_WRITE_C)
#include "mbedtls/x509_crt.h"
#include "mbedtls/oid.h"
#include "mbedtls/asn1write.h"
#include "mbedtls/sha1.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_PEM_WRITE_C)
#include "mbedtls/pem.h"
#endif /* MBEDTLS_PEM_WRITE_C */
#if MBEDTLS_ECDSA_MAX_LEN > MBEDTLS_MPI_MAX_SIZE
#define SIGNATURE_MAX_SIZE MBEDTLS_ECDSA_MAX_LEN
#else
#define SIGNATURE_MAX_SIZE MBEDTLS_MPI_MAX_SIZE
#endif
void mbedtls_x509write_crt_free( mbedtls_x509write_cert *ctx )
{
    mbedtls_mpi_free( &ctx->serial );

    mbedtls_asn1_free_named_data_list( &ctx->subject );
    mbedtls_asn1_free_named_data_list( &ctx->issuer );
    mbedtls_asn1_free_named_data_list( &ctx->extensions );

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_x509write_cert ) );
}
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#define PEM_BEGIN_CRT           "-----BEGIN CERTIFICATE-----\n"
#define PEM_END_CRT             "-----END CERTIFICATE-----\n"
#if defined(MBEDTLS_PEM_WRITE_C)
#endif /* MBEDTLS_PEM_WRITE_C */
#endif /* MBEDTLS_X509_CRT_WRITE_C */
