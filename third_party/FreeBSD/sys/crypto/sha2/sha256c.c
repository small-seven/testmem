#include <sys/cdefs.h>
#include <endian.h>
#include <sys/types.h>
#ifdef _KERNEL
#include <sys/systm.h>
#else
#include <string.h>
#endif
#include "sha256.h"
#if BYTE_ORDER == BIG_ENDIAN
#define be32enc_vect(dst, src, len)	\
#define be32dec_vect(dst, src, len)	\
#else /* BYTE_ORDER != BIG_ENDIAN */
#endif /* BYTE_ORDER != BIG_ENDIAN */
#define Ch(x, y, z)	((x & (y ^ z)) ^ z)
#define Maj(x, y, z)	((x & (y | z)) | (y & z))
#define SHR(x, n)	(x >> n)
#define ROTR(x, n)	((x >> n) | (x << (32 - n)))
#define S0(x)		(ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define S1(x)		(ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define s0(x)		(ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
#define s1(x)		(ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))
#define RND(a, b, c, d, e, f, g, h, k)			\
#define RNDr(S, W, i, ii)			\
#define MSCH(W, ii, i)				\
#ifdef WEAK_REFS
#undef SHA256_Init
#undef SHA256_Update
#undef SHA256_Final
#undef SHA256_Transform
#endif
