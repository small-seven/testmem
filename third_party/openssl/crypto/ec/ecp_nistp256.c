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
typedef __int128_t int128_t;
# else
#  error "Your compiler doesn't appear to support 128-bit integer types"
# endif

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;

/*
 * The underlying field. P256 operates over GF(2^256-2^224+2^192+2^96-1). We
 * can serialise an element of this field into 32 bytes. We call this an
 * felem_bytearray.
 */

typedef u8 felem_bytearray[32];

/*
 * These are the parameters of P256, taken from FIPS 186-3, page 86. These
 * values are big-endian.
 */
static const felem_bytearray nistp256_curve_params[5] = {
    {0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01, /* p */
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
# define NLIMBS 4
typedef uint128_t limb;
typedef limb felem[NLIMBS];
typedef limb longfelem[NLIMBS * 2];
typedef u64 smallfelem[NLIMBS];

/* This is the value of the prime as four 64-bit words, little-endian. */
static const u64 kPrime[4] =
    { 0xfffffffffffffffful, 0xffffffff, 0, 0xffffffff00000001ul };
# define two105m41m9 (((limb)1) << 105) - (((limb)1) << 41) - (((limb)1) << 9)
# define two105 (((limb)1) << 105)
# define two105m41p9 (((limb)1) << 105) - (((limb)1) << 41) + (((limb)1) << 9)
# define two107m43m11 (((limb)1) << 107) - (((limb)1) << 43) - (((limb)1) << 11)
# define two107 (((limb)1) << 107)
# define two107m43p11 (((limb)1) << 107) - (((limb)1) << 43) + (((limb)1) << 11)
# define two64m0 (((limb)1) << 64) - 1
# define two110p32m0 (((limb)1) << 110) + (((limb)1) << 32) - 1
# define two64m46 (((limb)1) << 64) - (((limb)1) << 46)
# define two64m32 (((limb)1) << 64) - (((limb)1) << 32)
# define two100m36m4 (((limb)1) << 100) - (((limb)1) << 36) - (((limb)1) << 4)
# define two100 (((limb)1) << 100)
# define two100m36p4 (((limb)1) << 100) - (((limb)1) << 36) + (((limb)1) << 4)
void EC_nistp256_pre_comp_free(NISTP256_PRE_COMP *pre)
{
    int i;

    if (pre == NULL)
        return;

    CRYPTO_DOWN_REF(&pre->references, &i, pre->lock);
    REF_PRINT_COUNT("EC_nistp256", x);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    CRYPTO_THREAD_lock_free(pre->lock);
    OPENSSL_free(pre);
}
#endif
