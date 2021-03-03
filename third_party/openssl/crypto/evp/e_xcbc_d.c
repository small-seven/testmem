#include <stdio.h>
#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_DES
# include <openssl/evp.h>
# include <openssl/objects.h>
# include "crypto/evp.h"
# include <openssl/des.h>
typedef struct {
    DES_key_schedule ks;        /* key schedule */
    DES_cblock inw;
    DES_cblock outw;
} DESX_CBC_KEY;
# define data(ctx) EVP_C_DATA(DESX_CBC_KEY,ctx)
#endif
