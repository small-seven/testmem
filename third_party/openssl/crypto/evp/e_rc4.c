#include <stdio.h>
#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_RC4
# include <openssl/evp.h>
# include <openssl/objects.h>
# include <openssl/rc4.h>
# include "crypto/evp.h"
typedef struct {
    RC4_KEY ks;                 /* working key */
} EVP_RC4_KEY;
# define data(ctx) ((EVP_RC4_KEY *)EVP_CIPHER_CTX_get_cipher_data(ctx))
#endif
