#include <openssl/e_os2.h>
#ifdef OPENSSL_NO_EC_NISTP_64_GCC_128
#else
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

/*
 * The underlying field. P521 operates over GF(2^521-1). We can serialise an
 * element of this field into 66 bytes where the most significant byte
 * contains only a single bit. We call this an felem_bytearray.
 */

typedef u8 felem_bytearray[66];

/*
 * These are the parameters of P521, taken from FIPS 186-3, section D.1.2.5.
 * These values are big-endian.
 */
static const felem_bytearray nistp521_curve_params[5] = {
    {0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* p */
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
     0xff, 0xff},
# define NLIMBS 9
typedef uint64_t limb;
typedef limb felem[NLIMBS];
typedef uint128_t largefelem[NLIMBS];

static const limb bottom57bits = 0x1ffffffffffffff;
static const limb bottom58bits = 0x3ffffffffffffff;

/*
 * bin66_to_felem takes a little-endian byte array and converts it into felem
 * form. This assumes that the CPU is little-endian.
 */
static void bin66_to_felem(felem out, const u8 in[66])
{
    out[0] = (*((limb *) & in[0])) & bottom58bits;
    out[1] = (*((limb *) & in[7]) >> 2) & bottom58bits;
    out[2] = (*((limb *) & in[14]) >> 4) & bottom58bits;
    out[3] = (*((limb *) & in[21]) >> 6) & bottom58bits;
    out[4] = (*((limb *) & in[29])) & bottom58bits;
    out[5] = (*((limb *) & in[36]) >> 2) & bottom58bits;
    out[6] = (*((limb *) & in[43]) >> 4) & bottom58bits;
    out[7] = (*((limb *) & in[50]) >> 6) & bottom58bits;
    out[8] = (*((limb *) & in[58])) & bottom57bits;
}
void EC_nistp521_pre_comp_free(NISTP521_PRE_COMP *p)
{
    int i;

    if (p == NULL)
        return;

    CRYPTO_DOWN_REF(&p->references, &i, p->lock);
    REF_PRINT_COUNT("EC_nistp521", x);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    CRYPTO_THREAD_lock_free(p->lock);
    OPENSSL_free(p);
}
#endif
