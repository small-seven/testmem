#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_MD_C)
#include "mbedtls/md_internal.h"
#if defined(MBEDTLS_MD2_C)
#include "mbedtls/md2.h"
#endif
#if defined(MBEDTLS_MD4_C)
#include "mbedtls/md4.h"
#endif
#if defined(MBEDTLS_MD5_C)
#include "mbedtls/md5.h"
#endif
#if defined(MBEDTLS_RIPEMD160_C)
#include "mbedtls/ripemd160.h"
#endif
#if defined(MBEDTLS_SHA1_C)
#include "mbedtls/sha1.h"
#endif
#if defined(MBEDTLS_SHA256_C)
#include "mbedtls/sha256.h"
#endif
#if defined(MBEDTLS_SHA512_C)
#include "mbedtls/sha512.h"
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#if defined(MBEDTLS_MD2_C)
static void md2_ctx_free( void *ctx )
{
    mbedtls_md2_free( (mbedtls_md2_context *) ctx );
    mbedtls_free( ctx );
}
#endif /* MBEDTLS_MD2_C */
#if defined(MBEDTLS_MD4_C)
static void md4_ctx_free( void *ctx )
{
    mbedtls_md4_free( (mbedtls_md4_context *) ctx );
    mbedtls_free( ctx );
}
#endif /* MBEDTLS_MD4_C */
#if defined(MBEDTLS_MD5_C)
static void *md5_ctx_alloc( void )
{
    void *ctx = mbedtls_calloc( 1, sizeof( mbedtls_md5_context ) );

    if( ctx != NULL )
        mbedtls_md5_init( (mbedtls_md5_context *) ctx );

    return( ctx );
}
static void md5_ctx_free( void *ctx )
{
    mbedtls_md5_free( (mbedtls_md5_context *) ctx );
    mbedtls_free( ctx );
}
#endif /* MBEDTLS_MD5_C */
#if defined(MBEDTLS_RIPEMD160_C)
static void ripemd160_ctx_free( void *ctx )
{
    mbedtls_ripemd160_free( (mbedtls_ripemd160_context *) ctx );
    mbedtls_free( ctx );
}
#endif /* MBEDTLS_RIPEMD160_C */
#if defined(MBEDTLS_SHA1_C)
static void *sha1_ctx_alloc( void )
{
    void *ctx = mbedtls_calloc( 1, sizeof( mbedtls_sha1_context ) );

    if( ctx != NULL )
        mbedtls_sha1_init( (mbedtls_sha1_context *) ctx );

    return( ctx );
}
static void sha1_ctx_free( void *ctx )
{
    mbedtls_sha1_free( (mbedtls_sha1_context *) ctx );
    mbedtls_free( ctx );
}
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
static void *sha224_ctx_alloc( void )
{
    void *ctx = mbedtls_calloc( 1, sizeof( mbedtls_sha256_context ) );

    if( ctx != NULL )
        mbedtls_sha256_init( (mbedtls_sha256_context *) ctx );

    return( ctx );
}
static void sha224_ctx_free( void *ctx )
{
    mbedtls_sha256_free( (mbedtls_sha256_context *) ctx );
    mbedtls_free( ctx );
}
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
static void *sha384_ctx_alloc( void )
{
    void *ctx = mbedtls_calloc( 1, sizeof( mbedtls_sha512_context ) );

    if( ctx != NULL )
        mbedtls_sha512_init( (mbedtls_sha512_context *) ctx );

    return( ctx );
}
static void sha384_ctx_free( void *ctx )
{
    mbedtls_sha512_free( (mbedtls_sha512_context *) ctx );
    mbedtls_free( ctx );
}
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_MD_C */
