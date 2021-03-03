#include "includes.h"
#include "common.h"
#include "sha1.h"
#include "sha1_i.h"
#include "md5.h"
#include "crypto.h"
typedef struct SHA1Context SHA1_CTX;

void SHA1Transform(u32 state[5], const unsigned char buffer[64]);


#ifdef CONFIG_CRYPTO_INTERNAL
/**
 * sha1_vector - SHA-1 hash for data vector
 * @num_elem: Number of elements in the data vector
 * @addr: Pointers to the data areas
 * @len: Lengths of the data blocks
 * @mac: Buffer for the hash
 * Returns: 0 on success, -1 of failure
 */
int sha1_vector(size_t num_elem, const u8 *addr[], const size_t *len, u8 *mac)
{
	SHA1_CTX ctx;
	size_t i;

	if (TEST_FAIL())
		return -1;

	SHA1Init(&ctx);
	for (i = 0; i < num_elem; i++)
		SHA1Update(&ctx, addr[i], len[i]);
	SHA1Final(mac, &ctx);
	return 0;
}
#endif /* CONFIG_CRYPTO_INTERNAL */
#define SHA1HANDSOFF
#define rol(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))
#ifndef WORDS_BIGENDIAN
#define blk0(i) (block->l[i] = (rol(block->l[i], 24) & 0xFF00FF00) | \
#else
#define blk0(i) block->l[i]
#endif
#define blk(i) (block->l[i & 15] = rol(block->l[(i + 13) & 15] ^ \
#define R0(v,w,x,y,z,i) \
#define R1(v,w,x,y,z,i) \
#define R2(v,w,x,y,z,i) \
#define R3(v,w,x,y,z,i) \
#define R4(v,w,x,y,z,i) \
#ifdef VERBOSE  /* SAK */
#endif
	typedef union {
		unsigned char c[64];
		u32 l[16];
	} CHAR64LONG16;
#ifdef SHA1HANDSOFF
#else
#endif
#ifdef SHA1HANDSOFF
#endif
#ifdef VERBOSE
#endif
#ifdef VERBOSE
#endif
