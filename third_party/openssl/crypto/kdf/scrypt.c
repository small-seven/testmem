#include <stdlib.h>
#include <string.h>
#include <openssl/hmac.h>
#include <openssl/kdf.h>
#include <openssl/evp.h>
#include "internal/cryptlib.h"
#include "crypto/evp.h"
#ifndef OPENSSL_NO_SCRYPT
typedef struct {
    unsigned char *pass;
    size_t pass_len;
    unsigned char *salt;
    size_t salt_len;
    uint64_t N, r, p;
    uint64_t maxmem_bytes;
} SCRYPT_PKEY_CTX;
#endif
