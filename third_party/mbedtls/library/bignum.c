#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_BIGNUM_C)
#include "mbedtls/bignum.h"
#include "mbedtls/bn_mul.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#include <stdlib.h>
#define mbedtls_printf     printf
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#define MPI_VALIDATE_RET( cond )                                       \
#define MPI_VALIDATE( cond )                                           \
#define ciL    (sizeof(mbedtls_mpi_uint))         /* chars in limb  */
#define biL    (ciL << 3)               /* bits  in limb  */
#define biH    (ciL << 2)               /* half limb size */
#define MPI_SIZE_T_MAX  ( (size_t) -1 ) /* SIZE_T_MAX is not standard */
#define BITS_TO_LIMBS(i)  ( (i) / biL + ( (i) % biL != 0 ) )
#define CHARS_TO_LIMBS(i) ( (i) / ciL + ( (i) % ciL != 0 ) )
void mbedtls_mpi_free( mbedtls_mpi *X )
{
    if( X == NULL )
        return;

    if( X->p != NULL )
    {
        mbedtls_mpi_zeroize( X->p, X->n );
        mbedtls_free( X->p );
    }

    X->s = 1;
    X->n = 0;
    X->p = NULL;
}
#define GET_BYTE( X, i )                                \
#if defined(MBEDTLS_FS_IO)
#endif /* MBEDTLS_FS_IO */
#if defined(__BYTE_ORDER__)
#if ( __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ )
#endif /* __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ */
#if ( __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ )
#if defined(__GNUC__) && defined(__GNUC_PREREQ)
#if __GNUC_PREREQ(4,3)
#define have_bswap
#endif
#endif
#if defined(__clang__) && defined(__has_builtin)
#if __has_builtin(__builtin_bswap32)  &&                 \
#define have_bswap
#endif
#endif
#if defined(have_bswap)
#endif
#endif /* __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ */
#endif /* __BYTE_ORDER__ */
#if defined(__APPLE__) && defined(__arm__)
#endif
#if defined(MULADDC_HUIT)
#else /* MULADDC_HUIT */
#endif /* MULADDC_HUIT */
#if defined(MBEDTLS_HAVE_UDBL)
#else
#endif
#if defined(MBEDTLS_HAVE_UDBL)
#else
#endif
#if( MBEDTLS_MPI_WINDOW_SIZE < 6 )
#endif
#if defined(MBEDTLS_GENPRIME)
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#ifdef MBEDTLS_HAVE_INT64
#define CEIL_MAXUINT_DIV_SQRT2 0xb504f333f9de6485ULL
#else
#define CEIL_MAXUINT_DIV_SQRT2 0xb504f334U
#endif
#endif /* MBEDTLS_GENPRIME */
#if defined(MBEDTLS_SELF_TEST)
#define GCD_PAIR_COUNT  3
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_BIGNUM_C */
