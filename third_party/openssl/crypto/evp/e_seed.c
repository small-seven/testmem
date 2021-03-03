#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_SEED
#else
# include <openssl/evp.h>
# include <openssl/err.h>
# include <string.h>
# include <assert.h>
# include <openssl/seed.h>
# include "crypto/evp.h"
typedef struct {
    SEED_KEY_SCHEDULE ks;
} EVP_SEED_KEY;
#endif
