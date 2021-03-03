#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_ECP_C)
#include "mbedtls/ecp.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if !defined(MBEDTLS_ECP_ALT)
#define ECP_VALIDATE_RET( cond )    \
#define ECP_VALIDATE( cond )        \
#if ( defined(__ARMCC_VERSION) || defined(_MSC_VER) ) && \
#define inline __inline
#endif
#if defined(MBEDTLS_HAVE_INT32)
#define BYTES_TO_T_UINT_4( a, b, c, d )                       \
#define BYTES_TO_T_UINT_2( a, b )                   \
#define BYTES_TO_T_UINT_8( a, b, c, d, e, f, g, h ) \
#else /* 64-bits */
#define BYTES_TO_T_UINT_8( a, b, c, d, e, f, g, h ) \
#define BYTES_TO_T_UINT_4( a, b, c, d )             \
#define BYTES_TO_T_UINT_2( a, b )                   \
#endif /* bits in mbedtls_mpi_uint */
#if defined(MBEDTLS_ECP_DP_SECP192R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP192R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP224R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP224R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP256R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP521R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP192K1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP192K1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP224K1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP224K1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP256K1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP256K1_ENABLED */
#if defined(MBEDTLS_ECP_DP_BP256R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_BP256R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_BP384R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_BP384R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_BP512R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_BP512R1_ENABLED */
#if defined(MBEDTLS_ECP_NIST_OPTIM)
#if defined(MBEDTLS_ECP_DP_SECP192R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP224R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED)
#endif
#define NIST_MODP( P )      grp->modp = ecp_mod_ ## P;
#else
#define NIST_MODP( P )
#endif /* MBEDTLS_ECP_NIST_OPTIM */
#if defined(MBEDTLS_ECP_DP_CURVE25519_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_CURVE448_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP192K1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP224K1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP256K1_ENABLED)
#endif
#define LOAD_GROUP_A( G )   ecp_group_load( grp,            \
#define LOAD_GROUP( G )     ecp_group_load( grp,            \
#if defined(MBEDTLS_ECP_DP_CURVE25519_ENABLED)
#endif /* MBEDTLS_ECP_DP_CURVE25519_ENABLED */
#if defined(MBEDTLS_ECP_DP_CURVE448_ENABLED)
#endif /* MBEDTLS_ECP_DP_CURVE448_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP192R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP192R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP224R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP224R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP256R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP521R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP192K1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP192K1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP224K1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP224K1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP256K1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP256K1_ENABLED */
#if defined(MBEDTLS_ECP_DP_BP256R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_BP256R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_BP384R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_BP384R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_BP512R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_BP512R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_CURVE25519_ENABLED)
#endif /* MBEDTLS_ECP_DP_CURVE25519_ENABLED */
#if defined(MBEDTLS_ECP_DP_CURVE448_ENABLED)
#endif /* MBEDTLS_ECP_DP_CURVE448_ENABLED */
#if defined(MBEDTLS_ECP_NIST_OPTIM)
#if defined(MBEDTLS_ECP_DP_SECP192R1_ENABLED)
#define WIDTH       8 / sizeof( mbedtls_mpi_uint )
#define A( i )      N->p + (i) * WIDTH
#define ADD( i )    add64( p, A( i ), &c )
#define NEXT        p += WIDTH; carry64( p, &c )
#define LAST        p += WIDTH; *p = c; while( ++p < end ) *p = 0
#undef WIDTH
#undef A
#undef ADD
#undef NEXT
#undef LAST
#endif /* MBEDTLS_ECP_DP_SECP192R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP224R1_ENABLED) ||   \
#define LOAD32      cur = A( i );
#if defined(MBEDTLS_HAVE_INT32)  /* 32 bit */
#define MAX32       N->n
#define A( j )      N->p[j]
#define STORE32     N->p[i] = cur;
#else                               /* 64-bit */
#define MAX32       N->n * 2
#define A( j ) (j) % 2 ? (uint32_t)( N->p[(j)/2] >> 32 ) : \
#define STORE32                                   \
#endif /* sizeof( mbedtls_mpi_uint ) */
#define ADD( j )    add32( &cur, A( j ), &c );
#define SUB( j )    sub32( &cur, A( j ), &c );
#define INIT( b )                                                       \
#define NEXT                    \
#define LAST                                    \
#if !defined(MBEDTLS_HAVE_INT64)
#else
#endif
#if defined(MBEDTLS_ECP_DP_SECP224R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP224R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP256R1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#undef A
#undef LOAD32
#undef STORE32
#undef MAX32
#undef INIT
#undef NEXT
#undef LAST
#endif /* MBEDTLS_ECP_DP_SECP224R1_ENABLED ||
#if defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED)
#define P521_WIDTH      ( 521 / 8 / sizeof( mbedtls_mpi_uint ) + 1 )
#define P521_MASK       0x01FF
#undef P521_WIDTH
#undef P521_MASK
#endif /* MBEDTLS_ECP_DP_SECP521R1_ENABLED */
#endif /* MBEDTLS_ECP_NIST_OPTIM */
#if defined(MBEDTLS_ECP_DP_CURVE25519_ENABLED)
#define P255_WIDTH      ( 255 / 8 / sizeof( mbedtls_mpi_uint ) + 1 )
#endif /* MBEDTLS_ECP_DP_CURVE25519_ENABLED */
#if defined(MBEDTLS_ECP_DP_CURVE448_ENABLED)
#define P448_WIDTH      ( 448 / 8 / sizeof( mbedtls_mpi_uint ) )
#define DIV_ROUND_UP( X, Y ) ( ( ( X ) + ( Y ) - 1 ) / ( Y ) )
#define P224_WIDTH_MIN   ( 28 / sizeof( mbedtls_mpi_uint ) )
#define P224_WIDTH_MAX   DIV_ROUND_UP( 28, sizeof( mbedtls_mpi_uint ) )
#define P224_UNUSED_BITS ( ( P224_WIDTH_MAX * sizeof( mbedtls_mpi_uint ) * 8 ) - 224 )
#endif /* MBEDTLS_ECP_DP_CURVE448_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP192K1_ENABLED) ||   \
#define P_KOBLITZ_MAX   ( 256 / 8 / sizeof( mbedtls_mpi_uint ) )  // Max limbs in P
#define P_KOBLITZ_R     ( 8 / sizeof( mbedtls_mpi_uint ) )        // Limbs in R
#endif /* MBEDTLS_ECP_DP_SECP192K1_ENABLED) ||
#if defined(MBEDTLS_ECP_DP_SECP192K1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP192K1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP224K1_ENABLED)
#if defined(MBEDTLS_HAVE_INT64)
#else
#endif
#endif /* MBEDTLS_ECP_DP_SECP224K1_ENABLED */
#if defined(MBEDTLS_ECP_DP_SECP256K1_ENABLED)
#endif /* MBEDTLS_ECP_DP_SECP256K1_ENABLED */
#endif /* !MBEDTLS_ECP_ALT */
#endif /* MBEDTLS_ECP_C */
