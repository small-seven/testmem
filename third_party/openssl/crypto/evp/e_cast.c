#include <stdio.h>
#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_CAST
# include <openssl/evp.h>
# include <openssl/objects.h>
# include "crypto/evp.h"
# include <openssl/cast.h>
typedef struct {
    CAST_KEY ks;
} EVP_CAST_KEY;
# define data(ctx)       EVP_C_DATA(EVP_CAST_KEY,ctx)
#endif
