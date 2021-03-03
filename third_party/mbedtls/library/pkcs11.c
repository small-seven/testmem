#include "mbedtls/pkcs11.h"
#if defined(MBEDTLS_PKCS11_C)
#include "mbedtls/md.h"
#include "mbedtls/oid.h"
#include "mbedtls/x509_crt.h"
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#include <string.h>
void mbedtls_pkcs11_priv_key_free( mbedtls_pkcs11_context *priv_key )
{
    if( NULL != priv_key )
        pkcs11h_certificate_freeCertificate( priv_key->pkcs11h_cert );
}
#endif /* defined(MBEDTLS_PKCS11_C) */
