#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_X509_CSR_WRITE_C)
#include "mbedtls/x509_csr.h"
#include "mbedtls/oid.h"
#include "mbedtls/asn1write.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#include <stdlib.h>
#if defined(MBEDTLS_PEM_WRITE_C)
#include "mbedtls/pem.h"
#endif
#if MBEDTLS_ECDSA_MAX_LEN > MBEDTLS_MPI_MAX_SIZE
#define SIGNATURE_MAX_SIZE MBEDTLS_ECDSA_MAX_LEN
#else
#define SIGNATURE_MAX_SIZE MBEDTLS_MPI_MAX_SIZE
#endif
void mbedtls_x509write_csr_free( mbedtls_x509write_csr *ctx )
{
    mbedtls_asn1_free_named_data_list( &ctx->subject );
    mbedtls_asn1_free_named_data_list( &ctx->extensions );

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_x509write_csr ) );
}
#define PEM_BEGIN_CSR           "-----BEGIN CERTIFICATE REQUEST-----\n"
#define PEM_END_CSR             "-----END CERTIFICATE REQUEST-----\n"
#if defined(MBEDTLS_PEM_WRITE_C)
#endif /* MBEDTLS_PEM_WRITE_C */
#endif /* MBEDTLS_X509_CSR_WRITE_C */
