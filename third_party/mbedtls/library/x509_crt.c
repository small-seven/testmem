#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#include "mbedtls/x509_crt.h"
#include "mbedtls/oid.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_PEM_PARSE_C)
#include "mbedtls/pem.h"
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#include <stdlib.h>
#define mbedtls_free       free
#define mbedtls_calloc    calloc
#define mbedtls_snprintf   snprintf
#endif
#if defined(MBEDTLS_THREADING_C)
#include "mbedtls/threading.h"
#endif
#if defined(_WIN32) && !defined(EFIX64) && !defined(EFI32)
#include <windows.h>
#else
#include <time.h>
#endif
#if defined(MBEDTLS_FS_IO)
#include <stdio.h>
#if !defined(_WIN32) || defined(EFIX64) || defined(EFI32)
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#endif /* !_WIN32 || EFIX64 || EFI32 */
#endif
typedef struct {
    mbedtls_x509_crt *crt;
    uint32_t flags;
} x509_crt_verify_chain_item;
#define X509_MAX_VERIFY_CHAIN_SIZE    ( MBEDTLS_X509_MAX_INTERMEDIATE_CA + 2 )
#if defined(MBEDTLS_TLS_DEFAULT_ALLOW_SHA1_IN_CERTIFICATES)
#endif
#if defined(MBEDTLS_ECP_C)
#else
#endif
#if defined(MBEDTLS_ECP_C)
#else
#endif
#if defined(MBEDTLS_RSA_C)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
static int x509_memcasecmp( const void *s1, const void *s2, size_t len )
{
    size_t i;
    unsigned char diff;
    const unsigned char *n1 = s1, *n2 = s2;

    for( i = 0; i < len; i++ )
    {
        diff = n1[i] ^ n2[i];

        if( diff == 0 )
            continue;

        if( diff == 32 &&
            ( ( n1[i] >= 'a' && n1[i] <= 'z' ) ||
              ( n1[i] >= 'A' && n1[i] <= 'Z' ) ) )
        {
            continue;
        }

        return( -1 );
    }

    return( 0 );
}
#if !defined(MBEDTLS_X509_ALLOW_UNSUPPORTED_CRITICAL_EXTENSION)
#endif
#if !defined(MBEDTLS_X509_ALLOW_EXTENSIONS_NON_V3)
#endif
#if defined(MBEDTLS_PEM_PARSE_C)
#endif
#if defined(MBEDTLS_PEM_PARSE_C)
#else
#endif
#if defined(MBEDTLS_PEM_PARSE_C)
#endif /* MBEDTLS_PEM_PARSE_C */
#if defined(MBEDTLS_FS_IO)
#if defined(_WIN32) && !defined(EFIX64) && !defined(EFI32)
#else /* _WIN32 */
#if defined(MBEDTLS_THREADING_C)
#endif /* MBEDTLS_THREADING_C */
#if defined(MBEDTLS_THREADING_C)
#endif /* MBEDTLS_THREADING_C */
#endif /* _WIN32 */
#endif /* MBEDTLS_FS_IO */
#define PRINT_ITEM(i)                           \
#define CERT_TYPE(type,name)                    \
#define KEY_USAGE(code,name)    \
#define BEFORE_COLON    18
#define BC              "18"
#if defined(MBEDTLS_X509_CHECK_KEY_USAGE)
#endif
#if defined(MBEDTLS_X509_CHECK_EXTENDED_KEY_USAGE)
#endif /* MBEDTLS_X509_CHECK_EXTENDED_KEY_USAGE */
#if defined(MBEDTLS_X509_CRL_PARSE_C)
#if defined(MBEDTLS_X509_CHECK_KEY_USAGE)
#endif
#endif /* MBEDTLS_X509_CRL_PARSE_C */
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif
#if defined(MBEDTLS_X509_CHECK_KEY_USAGE)
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif /* MBEDTLS_ECDSA_C && MBEDTLS_ECP_RESTARTABLE */
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#else
#endif
#if defined(MBEDTLS_X509_CRL_PARSE_C)
#else
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
#endif
void mbedtls_x509_crt_free( mbedtls_x509_crt *crt )
{
    mbedtls_x509_crt *cert_cur = crt;
    mbedtls_x509_crt *cert_prv;
    mbedtls_x509_name *name_cur;
    mbedtls_x509_name *name_prv;
    mbedtls_x509_sequence *seq_cur;
    mbedtls_x509_sequence *seq_prv;

    if( crt == NULL )
        return;

    do
    {
        mbedtls_pk_free( &cert_cur->pk );

#if defined(MBEDTLS_X509_RSASSA_PSS_SUPPORT)
        mbedtls_free( cert_cur->sig_opts );
#endif

        name_cur = cert_cur->issuer.next;
        while( name_cur != NULL )
        {
            name_prv = name_cur;
            name_cur = name_cur->next;
            mbedtls_platform_zeroize( name_prv, sizeof( mbedtls_x509_name ) );
            mbedtls_free( name_prv );
        }

        name_cur = cert_cur->subject.next;
        while( name_cur != NULL )
        {
            name_prv = name_cur;
            name_cur = name_cur->next;
            mbedtls_platform_zeroize( name_prv, sizeof( mbedtls_x509_name ) );
            mbedtls_free( name_prv );
        }

        seq_cur = cert_cur->ext_key_usage.next;
        while( seq_cur != NULL )
        {
            seq_prv = seq_cur;
            seq_cur = seq_cur->next;
            mbedtls_platform_zeroize( seq_prv,
                                      sizeof( mbedtls_x509_sequence ) );
            mbedtls_free( seq_prv );
        }

        seq_cur = cert_cur->subject_alt_names.next;
        while( seq_cur != NULL )
        {
            seq_prv = seq_cur;
            seq_cur = seq_cur->next;
            mbedtls_platform_zeroize( seq_prv,
                                      sizeof( mbedtls_x509_sequence ) );
            mbedtls_free( seq_prv );
        }

        if( cert_cur->raw.p != NULL )
        {
            mbedtls_platform_zeroize( cert_cur->raw.p, cert_cur->raw.len );
            mbedtls_free( cert_cur->raw.p );
        }

        cert_cur = cert_cur->next;
    }
    while( cert_cur != NULL );

    cert_cur = crt;
    do
    {
        cert_prv = cert_cur;
        cert_cur = cert_cur->next;

        mbedtls_platform_zeroize( cert_prv, sizeof( mbedtls_x509_crt ) );
        if( cert_prv != crt )
            mbedtls_free( cert_prv );
    }
    while( cert_cur != NULL );
}
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_ECP_RESTARTABLE)
void mbedtls_x509_crt_restart_free( mbedtls_x509_crt_restart_ctx *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_pk_restart_free( &ctx->pk );
    mbedtls_x509_crt_restart_init( ctx );
}
#endif /* MBEDTLS_ECDSA_C && MBEDTLS_ECP_RESTARTABLE */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
