#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_X509_CRL_PARSE_C)
#include "mbedtls/x509_crl.h"
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
#if defined(_WIN32) && !defined(EFIX64) && !defined(EFI32)
#include <windows.h>
#else
#include <time.h>
#endif
#if defined(MBEDTLS_FS_IO) || defined(EFIX64) || defined(EFI32)
#include <stdio.h>
#endif
#if defined(MBEDTLS_PEM_PARSE_C)
#endif /* MBEDTLS_PEM_PARSE_C */
#if defined(MBEDTLS_FS_IO)
#endif /* MBEDTLS_FS_IO */
#define BEFORE_COLON    14
#define BC              "14"
void mbedtls_x509_crl_free( mbedtls_x509_crl *crl )
{
    mbedtls_x509_crl *crl_cur = crl;
    mbedtls_x509_crl *crl_prv;
    mbedtls_x509_name *name_cur;
    mbedtls_x509_name *name_prv;
    mbedtls_x509_crl_entry *entry_cur;
    mbedtls_x509_crl_entry *entry_prv;

    if( crl == NULL )
        return;

    do
    {
#if defined(MBEDTLS_X509_RSASSA_PSS_SUPPORT)
        mbedtls_free( crl_cur->sig_opts );
#endif

        name_cur = crl_cur->issuer.next;
        while( name_cur != NULL )
        {
            name_prv = name_cur;
            name_cur = name_cur->next;
            mbedtls_platform_zeroize( name_prv, sizeof( mbedtls_x509_name ) );
            mbedtls_free( name_prv );
        }

        entry_cur = crl_cur->entry.next;
        while( entry_cur != NULL )
        {
            entry_prv = entry_cur;
            entry_cur = entry_cur->next;
            mbedtls_platform_zeroize( entry_prv,
                                      sizeof( mbedtls_x509_crl_entry ) );
            mbedtls_free( entry_prv );
        }

        if( crl_cur->raw.p != NULL )
        {
            mbedtls_platform_zeroize( crl_cur->raw.p, crl_cur->raw.len );
            mbedtls_free( crl_cur->raw.p );
        }

        crl_cur = crl_cur->next;
    }
    while( crl_cur != NULL );

    crl_cur = crl;
    do
    {
        crl_prv = crl_cur;
        crl_cur = crl_cur->next;

        mbedtls_platform_zeroize( crl_prv, sizeof( mbedtls_x509_crl ) );
        if( crl_prv != crl )
            mbedtls_free( crl_prv );
    }
    while( crl_cur != NULL );
}
#endif /* MBEDTLS_X509_CRL_PARSE_C */
