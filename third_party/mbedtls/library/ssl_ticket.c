#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_SSL_TICKET_C)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc    calloc
#define mbedtls_free      free
#endif
#include "mbedtls/ssl_ticket.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_THREADING_C)
#endif
#define MAX_KEY_BYTES 32    /* 256 bits */
#if defined(MBEDTLS_HAVE_TIME)
#endif
#if !defined(MBEDTLS_HAVE_TIME)
#else
#endif /* MBEDTLS_HAVE_TIME */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_HAVE_TIME)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
void mbedtls_ssl_ticket_free( mbedtls_ssl_ticket_context *ctx )
{
    mbedtls_cipher_free( &ctx->keys[0].ctx );
    mbedtls_cipher_free( &ctx->keys[1].ctx );

#if defined(MBEDTLS_THREADING_C)
    mbedtls_mutex_free( &ctx->mutex );
#endif

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_ssl_ticket_context ) );
}
#endif /* MBEDTLS_SSL_TICKET_C */
