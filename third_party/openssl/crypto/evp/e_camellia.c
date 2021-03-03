#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_CAMELLIA
#else
# include <openssl/evp.h>
# include <openssl/err.h>
# include <string.h>
# include <assert.h>
# include <openssl/camellia.h>
# include "crypto/evp.h"
# include "modes_local.h"
typedef struct {
    CAMELLIA_KEY ks;
    block128_f block;
    union {
        cbc128_f cbc;
        ctr128_f ctr;
    } stream;
# define MAXBITCHUNK     ((size_t)1<<(sizeof(size_t)*8-4))
# define data(ctx)       EVP_C_DATA(EVP_CAMELLIA_KEY,ctx)
# if defined(AES_ASM) && (defined(__sparc) || defined(__sparc__))
#  include "sparc_arch.h"
#  define SPARC_CMLL_CAPABLE      (OPENSSL_sparcv9cap_P[1] & CFR_CAMELLIA)
#  define cmll_t4_cbc_cipher camellia_cbc_cipher
#  define cmll_t4_ecb_cipher camellia_ecb_cipher
#  define cmll_t4_ofb_cipher camellia_ofb_cipher
#  define cmll_t4_cfb_cipher camellia_cfb_cipher
#  define cmll_t4_cfb8_cipher camellia_cfb8_cipher
#  define cmll_t4_cfb1_cipher camellia_cfb1_cipher
#  define cmll_t4_ctr_cipher camellia_ctr_cipher
#  define BLOCK_CIPHER_generic(nid,keylen,blocksize,ivlen,nmode,mode,MODE,flags) \
# else
#  define BLOCK_CIPHER_generic(nid,keylen,blocksize,ivlen,nmode,mode,MODE,flags) \
# endif
# define BLOCK_CIPHER_generic_pack(nid,keylen,flags)             \
#endif
