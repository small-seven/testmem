#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_HAVEGE_C)
#include "mbedtls/havege.h"
#include "mbedtls/timing.h"
#include "mbedtls/platform_util.h"
#include <limits.h>
#include <string.h>
#if INT_MIN + 1 != -0x7fffffff
#error "The HAVEGE module requires int to be exactly 32 bits, with INT_MIN = -2^31."
#endif
#if UINT_MAX != 0xffffffff
#error "The HAVEGE module requires unsigned to be exactly 32 bits."
#endif
#define SWAP(X,Y) { unsigned *T = (X); (X) = (Y); (Y) = T; }
#define TST1_ENTER if( PTEST & 1 ) { PTEST ^= 3; PTEST >>= 1;
#define TST2_ENTER if( PTEST & 1 ) { PTEST ^= 3; PTEST >>= 1;
#define TST1_LEAVE U1++; }
#define TST2_LEAVE U2++; }
#define ONE_ITERATION                                   \
void mbedtls_havege_free( mbedtls_havege_state *hs )
{
    if( hs == NULL )
        return;

    mbedtls_platform_zeroize( hs, sizeof( mbedtls_havege_state ) );
}
#endif /* MBEDTLS_HAVEGE_C */
