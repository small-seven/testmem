#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_RIPEMD160_C)
#include "mbedtls/ripemd160.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf printf
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST */
#if !defined(MBEDTLS_RIPEMD160_ALT)
#ifndef GET_UINT32_LE
#define GET_UINT32_LE(n,b,i)                            \
#endif
#ifndef PUT_UINT32_LE
#define PUT_UINT32_LE(n,b,i)                                    \
#endif
void mbedtls_ripemd160_free( mbedtls_ripemd160_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_ripemd160_context ) );
}
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if !defined(MBEDTLS_RIPEMD160_PROCESS_ALT)
#define F1( x, y, z )   ( (x) ^ (y) ^ (z) )
#define F2( x, y, z )   ( ( (x) & (y) ) | ( ~(x) & (z) ) )
#define F3( x, y, z )   ( ( (x) | ~(y) ) ^ (z) )
#define F4( x, y, z )   ( ( (x) & (z) ) | ( (y) & ~(z) ) )
#define F5( x, y, z )   ( (x) ^ ( (y) | ~(z) ) )
#define S( x, n ) ( ( (x) << (n) ) | ( (x) >> (32 - (n)) ) )
#define P( a, b, c, d, e, r, s, f, k )                \
#define P2( a, b, c, d, e, r, s, rp, sp )                               \
#define F   F1
#define K   0x00000000
#define Fp  F5
#define Kp  0x50A28BE6
#undef F
#undef K
#undef Fp
#undef Kp
#define F   F2
#define K   0x5A827999
#define Fp  F4
#define Kp  0x5C4DD124
#undef F
#undef K
#undef Fp
#undef Kp
#define F   F3
#define K   0x6ED9EBA1
#define Fp  F3
#define Kp  0x6D703EF3
#undef F
#undef K
#undef Fp
#undef Kp
#define F   F4
#define K   0x8F1BBCDC
#define Fp  F2
#define Kp  0x7A6D76E9
#undef F
#undef K
#undef Fp
#undef Kp
#define F   F5
#define K   0xA953FD4E
#define Fp  F1
#define Kp  0x00000000
#undef F
#undef K
#undef Fp
#undef Kp
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#endif /* !MBEDTLS_RIPEMD160_PROCESS_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#endif /* ! MBEDTLS_RIPEMD160_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if defined(MBEDTLS_SELF_TEST)
#define TESTS   8
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_RIPEMD160_C */
