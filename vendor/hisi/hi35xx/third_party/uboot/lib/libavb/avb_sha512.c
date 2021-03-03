#include "avb_sha.h"
#define SHFR(x, n) (x >> n)
#define ROTR(x, n) ((x >> n) | (x << ((sizeof(x) << 3) - n)))
#define ROTL(x, n) ((x << n) | (x >> ((sizeof(x) << 3) - n)))
#define CH(x, y, z) ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SHA512_F1(x) (ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39))
#define SHA512_F2(x) (ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41))
#define SHA512_F3(x) (ROTR(x, 1) ^ ROTR(x, 8) ^ SHFR(x, 7))
#define SHA512_F4(x) (ROTR(x, 19) ^ ROTR(x, 61) ^ SHFR(x, 6))
#define UNPACK32(x, str)                 \
#define UNPACK64(x, str)                         \
#define PACK64(str, x)                                                        \
#define SHA512_SCR(i) \
#define SHA512_EXP(a, b, c, d, e, f, g, h, j)                               \
#ifdef UNROLL_LOOPS_SHA512
#else
#endif /* UNROLL_LOOPS_SHA512 */
#ifdef UNROLL_LOOPS_SHA512
#else
#endif /* UNROLL_LOOPS_SHA512 */
#ifndef UNROLL_LOOPS_SHA512
#endif
#ifdef UNROLL_LOOPS_SHA512
#else
#endif /* UNROLL_LOOPS_SHA512 */
