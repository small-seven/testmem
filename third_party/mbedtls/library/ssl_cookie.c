#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_SSL_COOKIE_C)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#define mbedtls_calloc    calloc
#define mbedtls_free      free
#endif
#include "mbedtls/ssl_cookie.h"
#include "mbedtls/ssl_internal.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_SHA256_C)
#define COOKIE_MD           MBEDTLS_MD_SHA224
#define COOKIE_MD_OUTLEN    32
#define COOKIE_HMAC_LEN     28
#elif defined(MBEDTLS_SHA512_C)
#define COOKIE_MD           MBEDTLS_MD_SHA384
#define COOKIE_MD_OUTLEN    48
#define COOKIE_HMAC_LEN     28
#elif defined(MBEDTLS_SHA1_C)
#define COOKIE_MD           MBEDTLS_MD_SHA1
#define COOKIE_MD_OUTLEN    20
#define COOKIE_HMAC_LEN     20
#else
#error "DTLS hello verify needs SHA-1 or SHA-2"
#endif
#define COOKIE_LEN      ( 4 + COOKIE_HMAC_LEN )
#if !defined(MBEDTLS_HAVE_TIME)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
void mbedtls_ssl_cookie_free( mbedtls_ssl_cookie_ctx *ctx )
{
    mbedtls_md_free( &ctx->hmac_ctx );

#if defined(MBEDTLS_THREADING_C)
    mbedtls_mutex_free( &ctx->mutex );
#endif

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_ssl_cookie_ctx ) );
}
#if defined(MBEDTLS_HAVE_TIME)
#else
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_HAVE_TIME)
#else
#endif
#endif /* MBEDTLS_SSL_COOKIE_C */
