#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_ASN1_PARSE_C)
#include "mbedtls/asn1.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_BIGNUM_C)
#include "mbedtls/bignum.h"
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#if defined(MBEDTLS_BIGNUM_C)
#endif /* MBEDTLS_BIGNUM_C */
void mbedtls_asn1_free_named_data( mbedtls_asn1_named_data *cur )
{
    if( cur == NULL )
        return;

    mbedtls_free( cur->oid.p );
    mbedtls_free( cur->val.p );

    mbedtls_platform_zeroize( cur, sizeof( mbedtls_asn1_named_data ) );
}
void mbedtls_asn1_free_named_data_list( mbedtls_asn1_named_data **head )
{
    mbedtls_asn1_named_data *cur;

    while( ( cur = *head ) != NULL )
    {
        *head = cur->next;
        mbedtls_asn1_free_named_data( cur );
        mbedtls_free( cur );
    }
}
#endif /* MBEDTLS_ASN1_PARSE_C */
