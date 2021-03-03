#include <string.h>
#include <stdint.h>
typedef uint32_t BF_word;
typedef int32_t BF_word_signed;

/* Number of Blowfish rounds, this is also hardcoded into a few places */
#define BF_N				16

typedef BF_word BF_key[BF_N + 2];

typedef union {
	struct {
		BF_key P;
		BF_word S[4][0x100];
	} s;
#define BF_safe_atoi64(dst, src) \
#define BF_ROUND(L, R, N) \
#if 0
#else
#endif
