#include <string.h>
#include "internal/nelem.h"
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/obj_mac.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include "../crypto/rand/rand_local.h"
#include "testutil.h"
#include "drbg_cavs_data.h"
typedef struct test_ctx_st {
    const unsigned char *entropy;
    size_t entropylen;
    int entropycnt;
    const unsigned char *nonce;
    size_t noncelen;
    int noncecnt;
} TEST_CTX;
