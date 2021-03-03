#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/x509.h>
#include <openssl/ec.h>
#include <openssl/rand.h>
#include "crypto/asn1.h"
#include "crypto/evp.h"
#include "ec_local.h"
#include "curve448/curve448_local.h"
#define X25519_BITS          253
#define X25519_SECURITY_BITS 128
#define ED25519_SIGSIZE      64
#define X448_BITS            448
#define ED448_BITS           456
#define X448_SECURITY_BITS   224
#define ED448_SIGSIZE        114
#define ISX448(id)      ((id) == EVP_PKEY_X448)
#define IS25519(id)     ((id) == EVP_PKEY_X25519 || (id) == EVP_PKEY_ED25519)
#define KEYLENID(id)    (IS25519(id) ? X25519_KEYLEN \
#define KEYLEN(p)       KEYLENID((p)->ameth->pkey_id)
typedef enum {
    KEY_OP_PUBLIC,
    KEY_OP_PRIVATE,
    KEY_OP_KEYGEN
} ecx_key_op_t;
static void ecx_free(EVP_PKEY *pkey)
{
    if (pkey->pkey.ecx != NULL)
        OPENSSL_secure_clear_free(pkey->pkey.ecx->privkey, KEYLEN(pkey));
    OPENSSL_free(pkey->pkey.ecx);
}
