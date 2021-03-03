#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_ARIA
# include <openssl/evp.h>
# include <openssl/modes.h>
# include <openssl/rand.h>
# include <openssl/rand_drbg.h>
# include "crypto/aria.h"
# include "crypto/evp.h"
# include "modes_local.h"
# include "evp_local.h"
typedef struct {
    ARIA_KEY ks;
} EVP_ARIA_KEY;
typedef struct {
    union {
        double align;
        ARIA_KEY ks;
    } ks;                       /* ARIA subkey to use */
typedef struct {
    union {
        double align;
        ARIA_KEY ks;
    } ks;                       /* ARIA key schedule to use */
# define IMPLEMENT_ARIA_CFBR(ksize,cbits) \
# define BLOCK_CIPHER_generic(nid,keylen,blocksize,ivlen,nmode,mode,MODE,flags) \
#define aria_ccm_cleanup    NULL
#define ARIA_AUTH_FLAGS  (EVP_CIPH_FLAG_DEFAULT_ASN1 \
#define BLOCK_CIPHER_aead(nid,keylen,blocksize,ivlen,nmode,mode,MODE,flags) \
#endif
