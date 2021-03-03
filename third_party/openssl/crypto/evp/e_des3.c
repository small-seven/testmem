#include <stdio.h>
#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_DES
# include <openssl/evp.h>
# include <openssl/objects.h>
# include "crypto/evp.h"
# include <openssl/des.h>
# include <openssl/rand.h>
# include "evp_local.h"
typedef struct {
    union {
        double align;
        DES_key_schedule ks[3];
    } ks;
# define ks1 ks.ks[0]
# define ks2 ks.ks[1]
# define ks3 ks.ks[2]
# if defined(AES_ASM) && (defined(__sparc) || defined(__sparc__))
#  include "sparc_arch.h"
#  define SPARC_DES_CAPABLE       (OPENSSL_sparcv9cap_P[1] & CFR_DES)
# endif
# define data(ctx) EVP_C_DATA(DES_EDE_KEY,ctx)
# define des_ede3_cfb64_cipher des_ede_cfb64_cipher
# define des_ede3_ofb_cipher des_ede_ofb_cipher
# define des_ede3_cbc_cipher des_ede_cbc_cipher
# define des_ede3_ecb_cipher des_ede_ecb_cipher
# if defined(SPARC_DES_CAPABLE)
# endif
# if defined(SPARC_DES_CAPABLE)
# endif
# include <openssl/sha.h>
#endif
