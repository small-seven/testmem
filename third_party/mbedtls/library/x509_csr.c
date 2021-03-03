#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_X509_CSR_PARSE_C)
#include "mbedtls/x509_csr.h"
#include "mbedtls/oid.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_PEM_PARSE_C)
#include "mbedtls/pem.h"
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#include <stdio.h>
#define mbedtls_free       free
#define mbedtls_calloc    calloc
#define mbedtls_snprintf   snprintf
#endif
#if defined(MBEDTLS_FS_IO) || defined(EFIX64) || defined(EFI32)
#include <stdio.h>
#endif
#if defined(MBEDTLS_PEM_PARSE_C)
#endif
#if defined(MBEDTLS_PEM_PARSE_C)
#endif /* MBEDTLS_PEM_PARSE_C */
#if defined(MBEDTLS_FS_IO)
#endif /* MBEDTLS_FS_IO */
#define BEFORE_COLON    14
#define BC              "14"
void mbedtls_x509_csr_free( mbedtls_x509_csr *csr )
{
    mbedtls_x509_name *name_cur;
    mbedtls_x509_name *name_prv;

    if( csr == NULL )
        return;

    mbedtls_pk_free( &csr->pk );

#if defined(MBEDTLS_X509_RSASSA_PSS_SUPPORT)
    mbedtls_free( csr->sig_opts );
#endif

    name_cur = csr->subject.next;
    while( name_cur != NULL )
    {
        name_prv = name_cur;
        name_cur = name_cur->next;
        mbedtls_platform_zeroize( name_prv, sizeof( mbedtls_x509_name ) );
        mbedtls_free( name_prv );
    }

    if( csr->raw.p != NULL )
    {
        mbedtls_platform_zeroize( csr->raw.p, csr->raw.len );
        mbedtls_free( csr->raw.p );
    }

    mbedtls_platform_zeroize( csr, sizeof( mbedtls_x509_csr ) );
}
#endif /* MBEDTLS_X509_CSR_PARSE_C */
