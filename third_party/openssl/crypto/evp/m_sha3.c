#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/objects.h>
#include "crypto/evp.h"
#include "evp_local.h"
#define KECCAK1600_WIDTH 1600
typedef struct {
    uint64_t A[5][5];
    size_t block_size;          /* cached ctx->digest->block_size */
    size_t md_size;             /* output length, variable in XOF */
    size_t num;                 /* used bytes in below buffer */
    unsigned char buf[KECCAK1600_WIDTH / 8 - 32];
    unsigned char pad;
} KECCAK1600_CTX;
#if defined(OPENSSL_CPUID_OBJ) && defined(__s390__) && defined(KECCAK1600_ASM)
# include "s390x_arch.h"
# define S390X_SHA3_FC(ctx)     ((ctx)->pad)
# define S390X_sha3_224_CAPABLE ((OPENSSL_s390xcap_P.kimd[0] &      \
# define S390X_sha3_256_CAPABLE ((OPENSSL_s390xcap_P.kimd[0] &      \
# define S390X_sha3_384_CAPABLE ((OPENSSL_s390xcap_P.kimd[0] &      \
# define S390X_sha3_512_CAPABLE ((OPENSSL_s390xcap_P.kimd[0] &      \
# define S390X_shake128_CAPABLE ((OPENSSL_s390xcap_P.kimd[0] &      \
# define S390X_shake256_CAPABLE ((OPENSSL_s390xcap_P.kimd[0] &      \
# define S390X_KECCAK1600_BSZ(n) ((KECCAK1600_WIDTH - ((n) << 1)) >> 3)
# define EVP_MD_SHA3(bitlen)                         \
# define EVP_MD_SHAKE(bitlen)                        \
#else
# define EVP_MD_SHA3(bitlen)                    \
# define EVP_MD_SHAKE(bitlen)                   \
#endif
