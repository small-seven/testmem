#include <openssl/opensslconf.h>
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/objects.h>
#include <openssl/aes.h>
#include <openssl/sha.h>
#include <openssl/rand.h>
#include "modes_local.h"
#include "crypto/evp.h"
#include "internal/constant_time.h"
typedef struct {
    AES_KEY ks;
    SHA_CTX head, tail, md;
    size_t payload_length;      /* AAD length in decrypt case */
    union {
        unsigned int tls_ver;
        unsigned char tls_aad[16]; /* 13 used */
    } aux;
#define NO_PAYLOAD_LENGTH       ((size_t)-1)
#if     defined(AESNI_ASM) &&     ( \
# define AESNI_CAPABLE   (1<<(57-32))
# define data(ctx) ((EVP_AES_HMAC_SHA1 *)EVP_CIPHER_CTX_get_cipher_data(ctx))
# define STITCHED_CALL
# undef  STITCHED_DECRYPT_CALL
# if !defined(STITCHED_CALL)
#  define aes_off 0
# endif
# ifdef SHA1_Update
#  undef SHA1_Update
# endif
# define SHA1_Update sha1_update
# if !defined(OPENSSL_NO_MULTIBLOCK)
typedef struct {
    unsigned int A[8], B[8], C[8], D[8], E[8];
} SHA1_MB_CTX;
typedef struct {
    const unsigned char *ptr;
    int blocks;
} HASH_DESC;
typedef struct {
    const unsigned char *inp;
    unsigned char *out;
    int blocks;
    u64 iv[2];
} CIPH_DESC;
#  if defined(BSWAP8)
#  endif
#  if defined(BSWAP8)
#  endif
#  if !defined(BSWAP8)
#  endif
#  if defined(BSWAP8)
#  else
#  endif
#  define MAXCHUNKSIZE    2048
#  if     MAXCHUNKSIZE%64
#   error  "MAXCHUNKSIZE is not divisible by 64"
#  elif   MAXCHUNKSIZE
#  endif
#  undef  MAXCHUNKSIZE
#  ifdef BSWAP4
#  else
#  endif
#  ifdef BSWAP4
#  else
#  endif
#  ifdef BSWAP4
#  else
#  endif
# endif
# if defined(STITCHED_CALL)
# endif
# if defined(STITCHED_CALL)
# endif
# if defined(STITCHED_DECRYPT_CALL)
# endif
# if defined(STITCHED_DECRYPT_CALL)
# endif
# if defined(STITCHED_DECRYPT_CALL)
# endif
# if 1      /* see original reference version in #else */
#  ifdef BSWAP4
#  else
#  endif
#  ifdef BSWAP4
#  else
#  endif
# else      /* pre-lucky-13 reference version of above */
# endif
# if 1      /* see original reference version in #else */
# else      /* pre-lucky-13 reference version of above */
# endif
# if defined(STITCHED_DECRYPT_CALL)
# endif
# if !defined(OPENSSL_NO_MULTIBLOCK)
# endif
# ifdef NID_aes_128_cbc_hmac_sha1
# else
# endif
# ifdef NID_aes_256_cbc_hmac_sha1
# else
# endif
#else
#endif
