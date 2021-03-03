#include <string.h>
#include "ec_local.h"
#include <openssl/sha.h>
#if defined(X25519_ASM) && (defined(__x86_64) || defined(__x86_64__) || \
# define BASE_2_64_IMPLEMENTED
typedef uint64_t fe64[4];

int x25519_fe64_eligible(void);

/*
 * Following subroutines perform corresponding operations modulo
 * 2^256-38, i.e. double the curve modulus. However, inputs and
 * outputs are permitted to be partially reduced, i.e. to remain
 * in [0..2^256) range. It's all tied up in final fe64_tobytes
 * that performs full reduction modulo 2^255-19.
 *
 * There are no reference C implementations for these.
 */
void x25519_fe64_mul(fe64 h, const fe64 f, const fe64 g);
void x25519_fe64_sqr(fe64 h, const fe64 f);
void x25519_fe64_mul121666(fe64 h, fe64 f);
void x25519_fe64_add(fe64 h, const fe64 f, const fe64 g);
void x25519_fe64_sub(fe64 h, const fe64 f, const fe64 g);
void x25519_fe64_tobytes(uint8_t *s, const fe64 f);
# define fe64_mul x25519_fe64_mul
# define fe64_sqr x25519_fe64_sqr
# define fe64_mul121666 x25519_fe64_mul121666
# define fe64_add x25519_fe64_add
# define fe64_sub x25519_fe64_sub
# define fe64_tobytes x25519_fe64_tobytes

static uint64_t load_8(const uint8_t *in)
{
    uint64_t result;

    result = in[0];
    result |= ((uint64_t)in[1]) << 8;
    result |= ((uint64_t)in[2]) << 16;
    result |= ((uint64_t)in[3]) << 24;
    result |= ((uint64_t)in[4]) << 32;
    result |= ((uint64_t)in[5]) << 40;
    result |= ((uint64_t)in[6]) << 48;
    result |= ((uint64_t)in[7]) << 56;

    return result;
}
#endif
#if defined(X25519_ASM) \
# define BASE_2_51_IMPLEMENTED
typedef uint64_t fe51[5];

static const uint64_t MASK51 = 0x7ffffffffffff;

static uint64_t load_7(const uint8_t *in)
{
    uint64_t result;

    result = in[0];
    result |= ((uint64_t)in[1]) << 8;
    result |= ((uint64_t)in[2]) << 16;
    result |= ((uint64_t)in[3]) << 24;
    result |= ((uint64_t)in[4]) << 32;
    result |= ((uint64_t)in[5]) << 40;
    result |= ((uint64_t)in[6]) << 48;

    return result;
}
# if defined(X25519_ASM)
#  define fe51_mul x25519_fe51_mul
#  define fe51_sq  x25519_fe51_sqr
#  define fe51_mul121666 x25519_fe51_mul121666
# else
typedef __uint128_t u128;

static void fe51_mul(fe51 h, const fe51 f, const fe51 g)
{
    u128 h0, h1, h2, h3, h4;
    uint64_t f_i, g0, g1, g2, g3, g4;

    f_i = f[0];
    h0 = (u128)f_i * (g0 = g[0]);
    h1 = (u128)f_i * (g1 = g[1]);
    h2 = (u128)f_i * (g2 = g[2]);
    h3 = (u128)f_i * (g3 = g[3]);
    h4 = (u128)f_i * (g4 = g[4]);

    f_i = f[1];
    h0 += (u128)f_i * (g4 *= 19);
    h1 += (u128)f_i * g0;
    h2 += (u128)f_i * g1;
    h3 += (u128)f_i * g2;
    h4 += (u128)f_i * g3;

    f_i = f[2];
    h0 += (u128)f_i * (g3 *= 19);
    h1 += (u128)f_i * g4;
    h2 += (u128)f_i * g0;
    h3 += (u128)f_i * g1;
    h4 += (u128)f_i * g2;

    f_i = f[3];
    h0 += (u128)f_i * (g2 *= 19);
    h1 += (u128)f_i * g3;
    h2 += (u128)f_i * g4;
    h3 += (u128)f_i * g0;
    h4 += (u128)f_i * g1;

    f_i = f[4];
    h0 += (u128)f_i * (g1 *= 19);
    h1 += (u128)f_i * g2;
    h2 += (u128)f_i * g3;
    h3 += (u128)f_i * g4;
    h4 += (u128)f_i * g0;

    /* partial [lazy] reduction */
    h3 += (uint64_t)(h2 >> 51); g2 = (uint64_t)h2 & MASK51;
    h1 += (uint64_t)(h0 >> 51); g0 = (uint64_t)h0 & MASK51;

    h4 += (uint64_t)(h3 >> 51); g3 = (uint64_t)h3 & MASK51;
    g2 += (uint64_t)(h1 >> 51); g1 = (uint64_t)h1 & MASK51;

    g0 += (uint64_t)(h4 >> 51) * 19; g4 = (uint64_t)h4 & MASK51;
    g3 += g2 >> 51; g2 &= MASK51;
    g1 += g0 >> 51; g0 &= MASK51;

    h[0] = g0;
    h[1] = g1;
    h[2] = g2;
    h[3] = g3;
    h[4] = g4;
}
#  if defined(OPENSSL_SMALL_FOOTPRINT)
#  else
#  endif
# endif
# ifdef BASE_2_64_IMPLEMENTED
# endif
#endif
typedef int32_t fe[10];

static const int64_t kBottom21Bits =  0x1fffffLL;
static const int64_t kBottom25Bits = 0x1ffffffLL;
static const int64_t kBottom26Bits = 0x3ffffffLL;
static const int64_t kTop39Bits = 0xfffffffffe000000LL;
static const int64_t kTop38Bits = 0xfffffffffc000000LL;

static uint64_t load_3(const uint8_t *in)
{
    uint64_t result;

    result  = ((uint64_t)in[0]);
    result |= ((uint64_t)in[1]) << 8;
    result |= ((uint64_t)in[2]) << 16;
    return result;
}
typedef struct {
    fe X;
    fe Y;
    fe Z;
} ge_p2;
typedef struct {
    fe X;
    fe Y;
    fe Z;
    fe T;
} ge_p3;
typedef struct {
    fe X;
    fe Y;
    fe Z;
    fe T;
} ge_p1p1;
typedef struct {
    fe yplusx;
    fe yminusx;
    fe xy2d;
} ge_precomp;
typedef struct {
    fe YplusX;
    fe YminusX;
    fe Z;
    fe T2d;
} ge_cached;
#if !defined(BASE_2_51_IMPLEMENTED)
#endif
