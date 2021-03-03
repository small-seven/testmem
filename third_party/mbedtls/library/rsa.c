#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_RSA_C)
#include "mbedtls/rsa.h"
#include "mbedtls/rsa_internal.h"
#include "mbedtls/oid.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_PKCS1_V21)
#include "mbedtls/md.h"
#endif
#if defined(MBEDTLS_PKCS1_V15) && !defined(__OpenBSD__)
#include <stdlib.h>
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf printf
#define mbedtls_calloc calloc
#define mbedtls_free   free
#endif
#if !defined(MBEDTLS_RSA_ALT)
#define RSA_VALIDATE_RET( cond )                                       \
#define RSA_VALIDATE( cond )                                           \
#if defined(MBEDTLS_PKCS1_V15)
static inline int mbedtls_safer_memcmp( const void *a, const void *b, size_t n )
{
    size_t i;
    const unsigned char *A = (const unsigned char *) a;
    const unsigned char *B = (const unsigned char *) b;
    unsigned char diff = 0;

    for( i = 0; i < n; i++ )
        diff |= A[i] ^ B[i];

    return( diff );
}
#endif /* MBEDTLS_PKCS1_V15 */
#if !defined(MBEDTLS_RSA_NO_CRT)
#endif
#if !defined(MBEDTLS_RSA_NO_CRT)
#endif /* !MBEDTLS_RSA_NO_CRT */
#if defined(MBEDTLS_RSA_NO_CRT)
#else
#endif /* MBEDTLS_RSA_NO_CRT */
#if defined(MBEDTLS_RSA_NO_CRT)
#endif
#if !defined(MBEDTLS_RSA_NO_CRT)
#endif
#if !defined(MBEDTLS_RSA_NO_CRT)
#endif
#if !defined(MBEDTLS_RSA_NO_CRT)
#endif
#if !defined(MBEDTLS_RSA_NO_CRT)
#endif /* MBEDTLS_RSA_NO_CRT */
#if !defined(MBEDTLS_RSA_NO_CRT)
#else
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_GENPRIME)
#if !defined(MBEDTLS_RSA_NO_CRT)
#endif /* MBEDTLS_RSA_NO_CRT */
#endif /* MBEDTLS_GENPRIME */
#if !defined(MBEDTLS_RSA_NO_CRT)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#define RSA_EXPONENT_BLINDING 28
#if !defined(MBEDTLS_RSA_NO_CRT)
#else
#endif /* MBEDTLS_RSA_NO_CRT */
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_RSA_NO_CRT)
#else
#endif
#if !defined(MBEDTLS_RSA_NO_CRT)
#endif
#if defined(MBEDTLS_RSA_NO_CRT)
#else
#endif /* MBEDTLS_RSA_NO_CRT */
#if defined(MBEDTLS_RSA_NO_CRT)
#else
#endif /* MBEDTLS_RSA_NO_CRT */
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_RSA_NO_CRT)
#else
#endif
#if !defined(MBEDTLS_RSA_NO_CRT)
#endif
#if defined(MBEDTLS_PKCS1_V21)
#endif /* MBEDTLS_PKCS1_V21 */
#if defined(MBEDTLS_PKCS1_V21)
#endif /* MBEDTLS_PKCS1_V21 */
#if defined(MBEDTLS_PKCS1_V15)
#endif /* MBEDTLS_PKCS1_V15 */
#if defined(MBEDTLS_PKCS1_V15)
#endif
#if defined(MBEDTLS_PKCS1_V21)
#endif
#if defined(MBEDTLS_PKCS1_V21)
#endif /* MBEDTLS_PKCS1_V21 */
#if defined(MBEDTLS_PKCS1_V15)
#if defined(_MSC_VER)
#pragma warning( push )
#pragma warning( disable : 4146 )
#endif
#if defined(_MSC_VER)
#pragma warning( pop )
#endif
static void mem_move_to_left( void *start,
                              size_t total,
                              size_t offset )
{
    volatile unsigned char *buf = start;
    size_t i, n;
    if( total == 0 )
        return;
    for( i = 0; i < total; i++ )
    {
        unsigned no_op = size_greater_than( total - offset, i );
        /* The first `total - offset` passes are a no-op. The last
         * `offset` passes shift the data one byte to the left and
         * zero out the last byte. */
        for( n = 0; n < total - 1; n++ )
        {
            unsigned char current = buf[n];
            unsigned char next = buf[n+1];
            buf[n] = if_int( no_op, current, next );
        }
        buf[total-1] = if_int( no_op, buf[total-1], 0 );
    }
}
#endif /* MBEDTLS_PKCS1_V15 */
#if defined(MBEDTLS_PKCS1_V15)
#endif
#if defined(MBEDTLS_PKCS1_V21)
#endif
#if defined(MBEDTLS_PKCS1_V21)
#endif /* MBEDTLS_PKCS1_V21 */
#if defined(MBEDTLS_PKCS1_V15)
#endif /* MBEDTLS_PKCS1_V15 */
#if defined(MBEDTLS_PKCS1_V15)
#endif
#if defined(MBEDTLS_PKCS1_V21)
#endif
#if defined(MBEDTLS_PKCS1_V21)
#endif /* MBEDTLS_PKCS1_V21 */
#if defined(MBEDTLS_PKCS1_V15)
#endif /* MBEDTLS_PKCS1_V15 */
#if defined(MBEDTLS_PKCS1_V15)
#endif
#if defined(MBEDTLS_PKCS1_V21)
#endif
#if !defined(MBEDTLS_RSA_NO_CRT)
#endif
void mbedtls_rsa_free( mbedtls_rsa_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_mpi_free( &ctx->Vi );
    mbedtls_mpi_free( &ctx->Vf );
    mbedtls_mpi_free( &ctx->RN );
    mbedtls_mpi_free( &ctx->D  );
    mbedtls_mpi_free( &ctx->Q  );
    mbedtls_mpi_free( &ctx->P  );
    mbedtls_mpi_free( &ctx->E  );
    mbedtls_mpi_free( &ctx->N  );

#if !defined(MBEDTLS_RSA_NO_CRT)
    mbedtls_mpi_free( &ctx->RQ );
    mbedtls_mpi_free( &ctx->RP );
    mbedtls_mpi_free( &ctx->QP );
    mbedtls_mpi_free( &ctx->DQ );
    mbedtls_mpi_free( &ctx->DP );
#endif /* MBEDTLS_RSA_NO_CRT */

#if defined(MBEDTLS_THREADING_C)
    mbedtls_mutex_free( &ctx->mutex );
#endif
}
#endif /* !MBEDTLS_RSA_ALT */
#if defined(MBEDTLS_SELF_TEST)
#include "mbedtls/sha1.h"
#define KEY_LEN 128
#define RSA_N   "9292758453063D803DD603D5E777D788" \
#define RSA_E   "10001"
#define RSA_D   "24BF6185468786FDD303083D25E64EFC" \
#define RSA_P   "C36D0EB7FCD285223CFB5AABA5BDA3D8" \
#define RSA_Q   "C000DF51A7C77AE8D7C7370C1FF55B69" \
#define PT_LEN  24
#define RSA_PT  "\xAA\xBB\xCC\x03\x02\x01\x00\xFF\xFF\xFF\xFF\xFF" \
#if defined(MBEDTLS_PKCS1_V15)
#if !defined(__OpenBSD__)
#else
#endif /* !OpenBSD */
#endif /* MBEDTLS_PKCS1_V15 */
#if defined(MBEDTLS_PKCS1_V15)
#if defined(MBEDTLS_SHA1_C)
#endif
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#else /* MBEDTLS_PKCS1_V15 */
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_RSA_C */
