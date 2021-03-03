#include <stdio.h>
#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_BF
# include <openssl/evp.h>
# include "crypto/evp.h"
# include <openssl/objects.h>
# include <openssl/blowfish.h>
typedef struct {
    BF_KEY ks;
} EVP_BF_KEY;
# define data(ctx)       EVP_C_DATA(EVP_BF_KEY,ctx)
#endif
