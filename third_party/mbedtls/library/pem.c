#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PEM_PARSE_C) || defined(MBEDTLS_PEM_WRITE_C)
#include "mbedtls/pem.h"
#include "mbedtls/base64.h"
#include "mbedtls/des.h"
#include "mbedtls/aes.h"
#include "mbedtls/md5.h"
#include "mbedtls/cipher.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#if defined(MBEDTLS_PEM_PARSE_C)
#if defined(MBEDTLS_MD5_C) && defined(MBEDTLS_CIPHER_MODE_CBC) &&         \
#if defined(MBEDTLS_DES_C)
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_AES_C)
#endif /* MBEDTLS_AES_C */
#endif /* MBEDTLS_MD5_C && MBEDTLS_CIPHER_MODE_CBC &&
#if defined(MBEDTLS_MD5_C) && defined(MBEDTLS_CIPHER_MODE_CBC) &&         \
#else
#endif /* MBEDTLS_MD5_C && MBEDTLS_CIPHER_MODE_CBC &&
#if defined(MBEDTLS_MD5_C) && defined(MBEDTLS_CIPHER_MODE_CBC) &&         \
#if defined(MBEDTLS_DES_C)
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_AES_C)
#endif /* MBEDTLS_AES_C */
#else
#endif /* MBEDTLS_MD5_C && MBEDTLS_CIPHER_MODE_CBC &&
#if defined(MBEDTLS_MD5_C) && defined(MBEDTLS_CIPHER_MODE_CBC) &&         \
#if defined(MBEDTLS_DES_C)
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_AES_C)
#endif /* MBEDTLS_AES_C */
#else
#endif /* MBEDTLS_MD5_C && MBEDTLS_CIPHER_MODE_CBC &&
void mbedtls_pem_free( mbedtls_pem_context *ctx )
{
    if ( ctx->buf != NULL )
    {
        mbedtls_platform_zeroize( ctx->buf, ctx->buflen );
        mbedtls_free( ctx->buf );
    }
    mbedtls_free( ctx->info );

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_pem_context ) );
}
#endif /* MBEDTLS_PEM_PARSE_C */
#if defined(MBEDTLS_PEM_WRITE_C)
#endif /* MBEDTLS_PEM_WRITE_C */
#endif /* MBEDTLS_PEM_PARSE_C || MBEDTLS_PEM_WRITE_C */
