#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/kdf.h>
#include <openssl/evp.h>
#include "crypto/evp.h"
#define TLS1_PRF_MAXBUF 1024
typedef struct {
    /* Digest to use for PRF */
    const EVP_MD *md;
    /* Secret value to use for PRF */
    unsigned char *sec;
    size_t seclen;
    /* Buffer of concatenated seed data */
    unsigned char seed[TLS1_PRF_MAXBUF];
    size_t seedlen;
} TLS1_PRF_PKEY_CTX;
