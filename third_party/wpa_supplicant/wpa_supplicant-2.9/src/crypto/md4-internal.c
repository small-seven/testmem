#include "includes.h"
#include "common.h"
#include "crypto.h"
#define	MD4_BLOCK_LENGTH		64
#define	MD4_DIGEST_LENGTH		16
typedef struct MD4Context {
	u32 state[4];			/* state */
	u64 count;			/* number of bits, mod 2^64 */
	u8 buffer[MD4_BLOCK_LENGTH];	/* input buffer */
} MD4_CTX;
#define	MD4_DIGEST_STRING_LENGTH	(MD4_DIGEST_LENGTH * 2 + 1)
#define PUT_64BIT_LE(cp, value) do {					\
#define PUT_32BIT_LE(cp, value) do {					\
#define F1(x, y, z) (z ^ (x & (y ^ z)))
#define F2(x, y, z) ((x & y) | (x & z) | (y & z))
#define F3(x, y, z) (x ^ y ^ z)
#define MD4STEP(f, w, x, y, z, data, s) \
#if BYTE_ORDER == LITTLE_ENDIAN
#else
#endif
