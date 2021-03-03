#include <openssl/opensslconf.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/crypto.h>
#include <openssl/sha.h>
#include <openssl/opensslv.h>
#define DATA_ORDER_IS_BIG_ENDIAN
#define HASH_LONG               SHA_LONG
#define HASH_CTX                SHA256_CTX
#define HASH_CBLOCK             SHA_CBLOCK
#define HASH_MAKE_STRING(c,s)   do {    \
#define HASH_UPDATE             SHA256_Update
#define HASH_TRANSFORM          SHA256_Transform
#define HASH_FINAL              SHA256_Final
#define HASH_BLOCK_DATA_ORDER   sha256_block_data_order
#ifndef SHA256_ASM
#endif
#include "crypto/md32_common.h"
#ifndef SHA256_ASM
# define Sigma0(x)       (ROTATE((x),30) ^ ROTATE((x),19) ^ ROTATE((x),10))
# define Sigma1(x)       (ROTATE((x),26) ^ ROTATE((x),21) ^ ROTATE((x),7))
# define sigma0(x)       (ROTATE((x),25) ^ ROTATE((x),14) ^ ((x)>>3))
# define sigma1(x)       (ROTATE((x),15) ^ ROTATE((x),13) ^ ((x)>>10))
# define Ch(x,y,z)       (((x) & (y)) ^ ((~(x)) & (z)))
# define Maj(x,y,z)      (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# ifdef OPENSSL_SMALL_FOOTPRINT
# else
#  define ROUND_00_15(i,a,b,c,d,e,f,g,h)          do {    \
#  define ROUND_16_63(i,a,b,c,d,e,f,g,h,X)        do {    \
# endif
#endif                         /* SHA256_ASM */
