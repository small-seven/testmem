#include <stdio.h>
#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_IDEA
# include <openssl/evp.h>
# include <openssl/objects.h>
# include "crypto/evp.h"
# include <openssl/idea.h>
typedef struct {
    IDEA_KEY_SCHEDULE ks;
} EVP_IDEA_KEY;
#endif
