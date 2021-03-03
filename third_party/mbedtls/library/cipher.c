#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_CIPHER_C)
#include "mbedtls/cipher.h"
#include "mbedtls/cipher_internal.h"
#include "mbedtls/platform_util.h"
#include <stdlib.h>
#include <string.h>
#if defined(MBEDTLS_CHACHAPOLY_C)
#include "mbedtls/chachapoly.h"
#endif
#if defined(MBEDTLS_GCM_C)
#include "mbedtls/gcm.h"
#endif
#if defined(MBEDTLS_CCM_C)
#include "mbedtls/ccm.h"
#endif
#if defined(MBEDTLS_CHACHA20_C)
#include "mbedtls/chacha20.h"
#endif
#if defined(MBEDTLS_CMAC_C)
#include "mbedtls/cmac.h"
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#define mbedtls_calloc calloc
#define mbedtls_free   free
#endif
#define CIPHER_VALIDATE_RET( cond )    \
#define CIPHER_VALIDATE( cond )        \
#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
static int mbedtls_constant_time_memcmp( const void *v1, const void *v2, size_t len )
{
    const unsigned char *p1 = (const unsigned char*) v1;
    const unsigned char *p2 = (const unsigned char*) v2;
    size_t i;
    unsigned char diff;

    for( diff = 0, i = 0; i < len; i++ )
        diff |= p1[i] ^ p2[i];

    return( (int)diff );
}
#endif /* MBEDTLS_GCM_C || MBEDTLS_CHACHAPOLY_C */
void mbedtls_cipher_free( mbedtls_cipher_context_t *ctx )
{
    if( ctx == NULL )
        return;

#if defined(MBEDTLS_CMAC_C)
    if( ctx->cmac_ctx )
    {
       mbedtls_platform_zeroize( ctx->cmac_ctx,
                                 sizeof( mbedtls_cmac_context_t ) );
       mbedtls_free( ctx->cmac_ctx );
    }
#endif

    if( ctx->cipher_ctx )
        ctx->cipher_info->base->ctx_free_func( ctx->cipher_ctx );

    mbedtls_platform_zeroize( ctx, sizeof(mbedtls_cipher_context_t) );
}
#if defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
#if defined(MBEDTLS_CIPHER_PADDING_PKCS7)
#else
#endif
#endif /* MBEDTLS_CIPHER_MODE_WITH_PADDING */
#if defined(MBEDTLS_CHACHA20_C)
#endif
#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
#if defined(MBEDTLS_GCM_C)
#endif
#if defined(MBEDTLS_CHACHAPOLY_C)
#endif
#endif /* MBEDTLS_GCM_C || MBEDTLS_CHACHAPOLY_C */
#if defined(MBEDTLS_GCM_C)
#endif
#if defined(MBEDTLS_CHACHAPOLY_C)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif /* MBEDTLS_CIPHER_MODE_OFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif /* MBEDTLS_CIPHER_MODE_XTS */
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif /* MBEDTLS_CIPHER_MODE_STREAM */
#if defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
#if defined(MBEDTLS_CIPHER_PADDING_PKCS7)
#endif /* MBEDTLS_CIPHER_PADDING_PKCS7 */
#if defined(MBEDTLS_CIPHER_PADDING_ONE_AND_ZEROS)
#endif /* MBEDTLS_CIPHER_PADDING_ONE_AND_ZEROS */
#if defined(MBEDTLS_CIPHER_PADDING_ZEROS_AND_LEN)
#endif /* MBEDTLS_CIPHER_PADDING_ZEROS_AND_LEN */
#if defined(MBEDTLS_CIPHER_PADDING_ZEROS)
#endif /* MBEDTLS_CIPHER_PADDING_ZEROS */
#endif /* MBEDTLS_CIPHER_MODE_WITH_PADDING */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#else
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
#if defined(MBEDTLS_CIPHER_PADDING_PKCS7)
#endif
#if defined(MBEDTLS_CIPHER_PADDING_ONE_AND_ZEROS)
#endif
#if defined(MBEDTLS_CIPHER_PADDING_ZEROS_AND_LEN)
#endif
#if defined(MBEDTLS_CIPHER_PADDING_ZEROS)
#endif
#endif /* MBEDTLS_CIPHER_MODE_WITH_PADDING */
#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
#if defined(MBEDTLS_GCM_C)
#endif
#if defined(MBEDTLS_CHACHAPOLY_C)
#endif
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_CHACHAPOLY_C)
#endif /* MBEDTLS_CHACHAPOLY_C */
#endif /* MBEDTLS_GCM_C || MBEDTLS_CHACHAPOLY_C */
#if defined(MBEDTLS_CIPHER_MODE_AEAD)
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_CCM_C)
#endif /* MBEDTLS_CCM_C */
#if defined(MBEDTLS_CHACHAPOLY_C)
#endif /* MBEDTLS_CHACHAPOLY_C */
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_CCM_C)
#endif /* MBEDTLS_CCM_C */
#if defined(MBEDTLS_CHACHAPOLY_C)
#endif /* MBEDTLS_CHACHAPOLY_C */
#endif /* MBEDTLS_CIPHER_MODE_AEAD */
#endif /* MBEDTLS_CIPHER_C */
