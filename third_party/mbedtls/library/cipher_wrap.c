#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_CIPHER_C)
#include "mbedtls/cipher_internal.h"
#if defined(MBEDTLS_CHACHAPOLY_C)
#include "mbedtls/chachapoly.h"
#endif
#if defined(MBEDTLS_AES_C)
#include "mbedtls/aes.h"
#endif
#if defined(MBEDTLS_ARC4_C)
#include "mbedtls/arc4.h"
#endif
#if defined(MBEDTLS_CAMELLIA_C)
#include "mbedtls/camellia.h"
#endif
#if defined(MBEDTLS_ARIA_C)
#include "mbedtls/aria.h"
#endif
#if defined(MBEDTLS_DES_C)
#include "mbedtls/des.h"
#endif
#if defined(MBEDTLS_BLOWFISH_C)
#include "mbedtls/blowfish.h"
#endif
#if defined(MBEDTLS_CHACHA20_C)
#include "mbedtls/chacha20.h"
#endif
#if defined(MBEDTLS_GCM_C)
#include "mbedtls/gcm.h"
#endif
#if defined(MBEDTLS_CCM_C)
#include "mbedtls/ccm.h"
#endif
#if defined(MBEDTLS_CIPHER_NULL_CIPHER)
#include <string.h>
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#if defined(MBEDTLS_GCM_C)
static void *gcm_ctx_alloc( void )
{
    void *ctx = mbedtls_calloc( 1, sizeof( mbedtls_gcm_context ) );

    if( ctx != NULL )
        mbedtls_gcm_init( (mbedtls_gcm_context *) ctx );

    return( ctx );
}
static void gcm_ctx_free( void *ctx )
{
    mbedtls_gcm_free( ctx );
    mbedtls_free( ctx );
}
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_CCM_C)
static void ccm_ctx_free( void *ctx )
{
    mbedtls_ccm_free( ctx );
    mbedtls_free( ctx );
}
#endif /* MBEDTLS_CCM_C */
#if defined(MBEDTLS_AES_C)
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
static void * aes_ctx_alloc( void )
{
    mbedtls_aes_context *aes = mbedtls_calloc( 1, sizeof( mbedtls_aes_context ) );

    if( aes == NULL )
        return( NULL );

    mbedtls_aes_init( aes );

    return( aes );
}
static void aes_ctx_free( void *ctx )
{
    mbedtls_aes_free( (mbedtls_aes_context *) ctx );
    mbedtls_free( ctx );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
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
static void *xts_aes_ctx_alloc( void )
{
    mbedtls_aes_xts_context *xts_ctx = mbedtls_calloc( 1, sizeof( *xts_ctx ) );

    if( xts_ctx != NULL )
        mbedtls_aes_xts_init( xts_ctx );

    return( xts_ctx );
}
static void xts_aes_ctx_free( void *ctx )
{
    mbedtls_aes_xts_context *xts_ctx = ctx;

    if( xts_ctx == NULL )
        return;

    mbedtls_aes_xts_free( xts_ctx );
    mbedtls_free( xts_ctx );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#endif /* MBEDTLS_CIPHER_MODE_XTS */
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_CCM_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#endif /* MBEDTLS_CCM_C */
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_CAMELLIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
static void camellia_ctx_free( void *ctx )
{
    mbedtls_camellia_free( (mbedtls_camellia_context *) ctx );
    mbedtls_free( ctx );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_CCM_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#endif /* MBEDTLS_CCM_C */
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_ARIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
static void aria_ctx_free( void *ctx )
{
    mbedtls_aria_free( (mbedtls_aria_context *) ctx );
    mbedtls_free( ctx );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_CCM_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#endif /* MBEDTLS_CCM_C */
#endif /* MBEDTLS_ARIA_C */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
static void des_ctx_free( void *ctx )
{
    mbedtls_des_free( (mbedtls_des_context *) ctx );
    mbedtls_free( ctx );
}
static void des3_ctx_free( void *ctx )
{
    mbedtls_des3_free( (mbedtls_des3_context *) ctx );
    mbedtls_free( ctx );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_BLOWFISH_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
static void blowfish_ctx_free( void *ctx )
{
    mbedtls_blowfish_free( (mbedtls_blowfish_context *) ctx );
    mbedtls_free( ctx );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#endif /* MBEDTLS_BLOWFISH_C */
#if defined(MBEDTLS_ARC4_C)
static void * arc4_ctx_alloc( void )
{
    mbedtls_arc4_context *ctx;
    ctx = mbedtls_calloc( 1, sizeof( mbedtls_arc4_context ) );

    if( ctx == NULL )
        return( NULL );

    mbedtls_arc4_init( ctx );

    return( ctx );
}
static void arc4_ctx_free( void *ctx )
{
    mbedtls_arc4_free( (mbedtls_arc4_context *) ctx );
    mbedtls_free( ctx );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#endif /* MBEDTLS_ARC4_C */
#if defined(MBEDTLS_CHACHA20_C)
static void * chacha20_ctx_alloc( void )
{
    mbedtls_chacha20_context *ctx;
    ctx = mbedtls_calloc( 1, sizeof( mbedtls_chacha20_context ) );

    if( ctx == NULL )
        return( NULL );

    mbedtls_chacha20_init( ctx );

    return( ctx );
}
static void chacha20_ctx_free( void *ctx )
{
    mbedtls_chacha20_free( (mbedtls_chacha20_context *) ctx );
    mbedtls_free( ctx );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#endif /* MBEDTLS_CHACHA20_C */
#if defined(MBEDTLS_CHACHAPOLY_C)
static void * chachapoly_ctx_alloc( void )
{
    mbedtls_chachapoly_context *ctx;
    ctx = mbedtls_calloc( 1, sizeof( mbedtls_chachapoly_context ) );

    if( ctx == NULL )
        return( NULL );

    mbedtls_chachapoly_init( ctx );

    return( ctx );
}
static void chachapoly_ctx_free( void *ctx )
{
    mbedtls_chachapoly_free( (mbedtls_chachapoly_context *) ctx );
    mbedtls_free( ctx );
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#endif /* MBEDTLS_CHACHAPOLY_C */
#if defined(MBEDTLS_CIPHER_NULL_CIPHER)
static void null_ctx_free( void *ctx )
{
    ((void) ctx);
}
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_STREAM)
#endif
#endif /* defined(MBEDTLS_CIPHER_NULL_CIPHER) */
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_GCM_C)
#endif
#if defined(MBEDTLS_CCM_C)
#endif
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_ARC4_C)
#endif
#if defined(MBEDTLS_BLOWFISH_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#endif /* MBEDTLS_BLOWFISH_C */
#if defined(MBEDTLS_CAMELLIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_GCM_C)
#endif
#if defined(MBEDTLS_CCM_C)
#endif
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_ARIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_GCM_C)
#endif
#if defined(MBEDTLS_CCM_C)
#endif
#endif /* MBEDTLS_ARIA_C */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_CHACHA20_C)
#endif
#if defined(MBEDTLS_CHACHAPOLY_C)
#endif
#if defined(MBEDTLS_CIPHER_NULL_CIPHER)
#endif /* MBEDTLS_CIPHER_NULL_CIPHER */
#define NUM_CIPHERS sizeof mbedtls_cipher_definitions / sizeof mbedtls_cipher_definitions[0]
#endif /* MBEDTLS_CIPHER_C */
