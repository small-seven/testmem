#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_SM4
# include <openssl/evp.h>
# include <openssl/modes.h>
# include "crypto/sm4.h"
# include "crypto/evp.h"
typedef struct {
    SM4_KEY ks;
} EVP_SM4_KEY;
#endif
