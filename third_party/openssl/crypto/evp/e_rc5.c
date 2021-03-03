#include <stdio.h>
#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_RC5
# include <openssl/evp.h>
# include "crypto/evp.h"
# include <openssl/objects.h>
# include "evp_local.h"
# include <openssl/rc5.h>
typedef struct {
    int rounds;                 /* number of rounds */
    RC5_32_KEY ks;              /* key schedule */
} EVP_RC5_KEY;
# define data(ctx)       EVP_C_DATA(EVP_RC5_KEY,ctx)
#endif
