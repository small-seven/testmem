#include "cipher_osal.h"
#define HASH_MAX_BLOCK_SIZE     256
#define SHA1_RESULT_SIZE        20
#define SHA224_RESULT_SIZE      28
#define SHA256_RESULT_SIZE      32
#define SHA384_RESULT_SIZE      48
#define SHA512_RESULT_SIZE      64
#define SPACC_HASH_CHN          1
#define HASH_CHANNAL_MAX_NUM    8
#define SHA1_H0                 0x67452301
#define SHA1_H1                 0xefcdab89
#define SHA1_H2                 0x98badcfe
#define SHA1_H3                 0x10325476
#define SHA1_H4                 0xc3d2e1f0
#define SHA224_H0               0xc1059ed8
#define SHA224_H1               0x367cd507
#define SHA224_H2               0x3070dd17
#define SHA224_H3               0xf70e5939
#define SHA224_H4               0xffc00b31
#define SHA224_H5               0x68581511
#define SHA224_H6               0x64f98fa7
#define SHA224_H7               0xbefa4fa4
#define SHA256_H0               0x6a09e667
#define SHA256_H1               0xbb67ae85
#define SHA256_H2               0x3c6ef372
#define SHA256_H3               0xa54ff53a
#define SHA256_H4               0x510e527f
#define SHA256_H5               0x9b05688c
#define SHA256_H6               0x1f83d9ab
#define SHA256_H7               0x5be0cd19
#define SHA384_H0               0xcbbb9d5dc1059ed8ULL
#define SHA384_H1               0x629a292a367cd507ULL
#define SHA384_H2               0x9159015a3070dd17ULL
#define SHA384_H3               0x152fecd8f70e5939ULL
#define SHA384_H4               0x67332667ffc00b31ULL
#define SHA384_H5               0x8eb44a8768581511ULL
#define SHA384_H6               0xdb0c2e0d64f98fa7ULL
#define SHA384_H7               0x47b5481dbefa4fa4ULL
#define SHA512_H0               0x6a09e667f3bcc908ULL
#define SHA512_H1               0xbb67ae8584caa73bULL
#define SHA512_H2               0x3c6ef372fe94f82bULL
#define SHA512_H3               0xa54ff53a5f1d36f1ULL
#define SHA512_H4               0x510e527fade682d1ULL
#define SHA512_H5               0x9b05688c2b3e6c1fULL
#define SHA512_H6               0x1f83d9abfb41bd6bULL
#define SHA512_H7               0x5be0cd19137e2179ULL
#define SM3_H0                  0x7380166F
#define SM3_H1                  0x4914B2B9
#define SM3_H2                  0x172442D7
#define SM3_H3                  0xDA8A0600
#define SM3_H4                  0xA96F30BC
#define SM3_H5                  0x163138AA
#define SM3_H6                  0xE38DEE4D
#define SM3_H7                  0xB0FB0E4E
typedef struct {
    hi_handle handle;
    hi_cipher_hash_type sha_type;

    hi_u8 is_used;
    hi_u8 block_size;
    hi_u8 sha_len;
    hi_u8 last_block_size;

    hi_u32 total_data_len;
    hi_u32 sha_val[HASH_RESULT_MAX_LEN_IN_WORD];
    hi_u8 last_block[HASH_MAX_BLOCK_SIZE];
    hi_u8 mac[HASH_MAX_BLOCK_SIZE];
} hash_info_s;
#define HI_ID_HASH              101
