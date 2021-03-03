#include <netinet/in.h>
#ifdef __sun__
#include <inttypes.h>
#else
#include <stdint.h>
#endif
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include "modpost.h"
#define MD4_DIGEST_SIZE		16
#define MD4_HMAC_BLOCK_SIZE	64
#define MD4_BLOCK_WORDS		16
#define MD4_HASH_WORDS		4
#define ROUND1(a,b,c,d,k,s) (a = lshift(a + F(b,c,d) + k, s))
#define ROUND2(a,b,c,d,k,s) (a = lshift(a + G(b,c,d) + k + (uint32_t)0x5A827999,s))
#define ROUND3(a,b,c,d,k,s) (a = lshift(a + H(b,c,d) + k + (uint32_t)0x6ED9EBA1,s))
