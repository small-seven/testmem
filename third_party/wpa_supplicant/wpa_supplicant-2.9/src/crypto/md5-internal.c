#include "includes.h"
#include "common.h"
#include "md5.h"
#include "md5_i.h"
#include "crypto.h"
typedef struct MD5Context MD5_CTX;


/**
 * md5_vector - MD5 hash for data vector
 * @num_elem: Number of elements in the data vector
 * @addr: Pointers to the data areas
 * @len: Lengths of the data blocks
 * @mac: Buffer for the hash
 * Returns: 0 on success, -1 of failure
 */
int md5_vector(size_t num_elem, const u8 *addr[], const size_t *len, u8 *mac)
{
	MD5_CTX ctx;
	size_t i;

	if (TEST_FAIL())
		return -1;

	MD5Init(&ctx);
	for (i = 0; i < num_elem; i++)
		MD5Update(&ctx, addr[i], len[i]);
	MD5Final(mac, &ctx);
	return 0;
}
#ifndef WORDS_BIGENDIAN
#define byteReverse(buf, len)	/* Nothing */
#else
#endif
#define F1(x, y, z) (z ^ (x & (y ^ z)))
#define F2(x, y, z) F1(z, x, y)
#define F3(x, y, z) (x ^ y ^ z)
#define F4(x, y, z) (y ^ (x | ~z))
#define MD5STEP(f, w, x, y, z, data, s) \
