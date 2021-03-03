#include "avb_sha.h"
#define SHFR(x, n) (x >> n)
#define ROTR(x, n) ((x >> n) | (x << ((sizeof(x) << 3) - n)))
#define ROTL(x, n) ((x << n) | (x >> ((sizeof(x) << 3) - n)))
#define CH(x, y, z) ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SHA256_F1(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define SHA256_F2(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define SHA256_F3(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHFR(x, 3))
#define SHA256_F4(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHFR(x, 10))
#define UNPACK32(x, str)                 \
#define UNPACK64(x, str)                         \
#define PACK32(str, x)                                                    \
#define SHA256_SCR(i) \
#define SHA256_EXP(a, b, c, d, e, f, g, h, j)                               \
#ifndef UNROLL_LOOPS
#else
#endif /* !UNROLL_LOOPS */
#ifndef UNROLL_LOOPS
#endif
#ifndef UNROLL_LOOPS
#else
#endif /* !UNROLL_LOOPS */
#ifndef UNROLL_LOOPS
#endif
#ifndef UNROLL_LOOPS
#else
#endif /* !UNROLL_LOOPS */
