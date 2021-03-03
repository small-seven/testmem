#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_EC_NISTP_64_GCC_128
#else
# include <stdint.h>
# include <string.h>
# include <openssl/err.h>
# include "ec_local.h"
# if defined(__SIZEOF_INT128__) && __SIZEOF_INT128__==16
  /* even with gcc, the typedef won't work for 32-bit platforms */
typedef __uint128_t uint128_t;  /* nonstandard; implemented by gcc on 64-bit
                                 * platforms */
# else
#  error "Your compiler doesn't appear to support 128-bit integer types"
# endif

typedef uint8_t u8;
typedef uint64_t u64;

/******************************************************************************/
/*-
 * INTERNAL REPRESENTATION OF FIELD ELEMENTS
 *
 * Field elements are represented as a_0 + 2^56*a_1 + 2^112*a_2 + 2^168*a_3
 * using 64-bit coefficients called 'limbs',
 * and sometimes (for multiplication results) as
 * b_0 + 2^56*b_1 + 2^112*b_2 + 2^168*b_3 + 2^224*b_4 + 2^280*b_5 + 2^336*b_6
 * using 128-bit coefficients called 'widelimbs'.
 * A 4-limb representation is an 'felem';
 * a 7-widelimb representation is a 'widefelem'.
 * Even within felems, bits of adjacent limbs overlap, and we don't always
 * reduce the representations: we ensure that inputs to each felem
 * multiplication satisfy a_i < 2^60, so outputs satisfy b_i < 4*2^60*2^60,
 * and fit into a 128-bit word without overflow. The coefficients are then
 * again partially reduced to obtain an felem satisfying a_i < 2^57.
 * We only reduce to the unique minimal representation at the end of the
 * computation.
 */

typedef uint64_t limb;
typedef uint128_t widelimb;

typedef limb felem[4];
typedef widelimb widefelem[7];

/*
 * Field element represented as a byte array. 28*8 = 224 bits is also the
 * group order size for the elliptic curve, and we also use this type for
 * scalars for point multiplication.
 */
typedef u8 felem_bytearray[28];

static const felem_bytearray nistp224_curve_params[5] = {
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* p */
     0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
void EC_nistp224_pre_comp_free(NISTP224_PRE_COMP *p)
{
    int i;

    if (p == NULL)
        return;

    CRYPTO_DOWN_REF(&p->references, &i, p->lock);
    REF_PRINT_COUNT("EC_nistp224", x);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    CRYPTO_THREAD_lock_free(p->lock);
    OPENSSL_free(p);
}
#endif
