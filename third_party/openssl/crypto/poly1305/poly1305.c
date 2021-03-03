#include <stdlib.h>
#include <string.h>
#include <openssl/crypto.h>
#include "crypto/poly1305.h"
#include "poly1305_local.h"
#ifndef POLY1305_ASM
typedef unsigned int u32;

/*
 * poly1305_blocks processes a multiple of POLY1305_BLOCK_SIZE blocks
 * of |inp| no longer than |len|. Behaviour for |len| not divisible by
 * block size is unspecified in general case, even though in reference
 * implementation the trailing chunk is simply ignored. Per algorithm
 * specification, every input block, complete or last partial, is to be
 * padded with a bit past most significant byte. The latter kind is then
 * padded with zeros till block size. This last partial block padding
 * is caller(*)'s responsibility, and because of this the last partial
 * block is always processed with separate call with |len| set to
 * POLY1305_BLOCK_SIZE and |padbit| to 0. In all other cases |padbit|
 * should be set to 1 to perform implicit padding with 128th bit.
 * poly1305_blocks does not actually check for this constraint though,
 * it's caller(*)'s responsibility to comply.
 *
 * (*)  In the context "caller" is not application code, but higher
 *      level Poly1305_* from this very module, so that quirks are
 *      handled locally.
 */
static void
poly1305_blocks(void *ctx, const unsigned char *inp, size_t len, u32 padbit);

/*
 * Type-agnostic "rip-off" from constant_time.h
 */
# define CONSTANT_TIME_CARRY(a,b) ( \
         (a ^ ((a ^ b) | ((a - b) ^ b))) >> (sizeof(a) * 8 - 1) \
         )

# if (defined(__SIZEOF_INT128__) && __SIZEOF_INT128__==16) && \
     (defined(__SIZEOF_LONG__) && __SIZEOF_LONG__==8)

typedef unsigned long u64;
typedef __uint128_t u128;

typedef struct {
    u64 h[3];
    u64 r[2];
} poly1305_internal;
# else
#  if defined(_WIN32) && !defined(__MINGW32__)
typedef unsigned __int64 u64;
#  elif defined(__arch64__)
typedef unsigned long u64;
#  else
typedef unsigned long long u64;
#  endif

typedef struct {
    u32 h[5];
    u32 r[4];
} poly1305_internal;
# endif
#else
#endif
#ifndef POLY1305_ASM
#else
#endif
#ifdef POLY1305_ASM
# define poly1305_blocks (*poly1305_blocks_p)
# define poly1305_emit   (*poly1305_emit_p)
#endif
#ifdef POLY1305_ASM
#endif
#ifdef POLY1305_ASM
#endif
