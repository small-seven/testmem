#include <stdio.h>
#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_RC2
# include <openssl/evp.h>
# include <openssl/objects.h>
# include "crypto/evp.h"
# include <openssl/rc2.h>
typedef struct {
    int key_bits;               /* effective key bits */
    RC2_KEY ks;                 /* key schedule */
} EVP_RC2_KEY;
# define data(ctx)       EVP_C_DATA(EVP_RC2_KEY,ctx)
# define RC2_40_MAGIC    0xa0
# define RC2_64_MAGIC    0x78
# define RC2_128_MAGIC   0x3a
# ifdef PBE_PRF_TEST
# endif
#endif
