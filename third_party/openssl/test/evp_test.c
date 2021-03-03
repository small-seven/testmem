#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/x509v3.h>
#include <openssl/pkcs12.h>
#include <openssl/kdf.h>
#include "internal/numbers.h"
#include "testutil.h"
#include "evp_test.h"
typedef struct evp_test_method_st EVP_TEST_METHOD;

/*
 * Structure holding test information
 */
typedef struct evp_test_st {
    STANZA s;                     /* Common test stanza */
    char *name;
    int skip;                     /* Current test should be skipped */
    const EVP_TEST_METHOD *meth;  /* method for this test */
    const char *err, *aux_err;    /* Error string for test */
    char *expected_err;           /* Expected error value of test */
    char *func;                   /* Expected error function string */
    char *reason;                 /* Expected error reason string */
    void *data;                   /* test specific data */
} EVP_TEST;
typedef struct key_list_st {
    char *name;
    EVP_PKEY *key;
    struct key_list_st *next;
} KEY_LIST;
static void evp_test_buffer_free(EVP_TEST_BUFFER *db)
{
    if (db != NULL) {
        OPENSSL_free(db->buf);
        OPENSSL_free(db);
    }
}
typedef struct digest_data_st {
    /* Digest this test is for */
    const EVP_MD *digest;
    /* Input to digest */
    STACK_OF(EVP_TEST_BUFFER) *input;
    /* Expected output */
    unsigned char *output;
    size_t output_len;
} DIGEST_DATA;
typedef struct cipher_data_st {
    const EVP_CIPHER *cipher;
    int enc;
    /* EVP_CIPH_GCM_MODE, EVP_CIPH_CCM_MODE or EVP_CIPH_OCB_MODE if AEAD */
    int aead;
    unsigned char *key;
    size_t key_len;
    unsigned char *iv;
    size_t iv_len;
    unsigned char *plaintext;
    size_t plaintext_len;
    unsigned char *ciphertext;
    size_t ciphertext_len;
    /* GCM, CCM and OCB only */
    unsigned char *aad;
    size_t aad_len;
    unsigned char *tag;
    size_t tag_len;
    int tag_late;
} CIPHER_DATA;
typedef struct mac_data_st {
    /* MAC type */
    int type;
    /* Algorithm string for this MAC */
    char *alg;
    /* MAC key */
    unsigned char *key;
    size_t key_len;
    /* Input to MAC */
    unsigned char *input;
    size_t input_len;
    /* Expected output */
    unsigned char *output;
    size_t output_len;
    /* Collection of controls */
    STACK_OF(OPENSSL_STRING) *controls;
} MAC_DATA;
#ifndef OPENSSL_NO_CMAC
#else
#endif
#ifndef OPENSSL_NO_POLY1305
#else
#endif
#ifndef OPENSSL_NO_SIPHASH
#else
#endif
static void openssl_free(char *m)
{
    OPENSSL_free(m);
}
#ifdef OPENSSL_NO_DES
#endif
typedef struct pkey_data_st {
    /* Context for this operation */
    EVP_PKEY_CTX *ctx;
    /* Key operation to perform */
    int (*keyop) (EVP_PKEY_CTX *ctx,
                  unsigned char *sig, size_t *siglen,
                  const unsigned char *tbs, size_t tbslen);
    /* Input to MAC */
    unsigned char *input;
    size_t input_len;
    /* Expected output */
    unsigned char *output;
    size_t output_len;
} PKEY_DATA;
typedef enum pbe_type_enum {
    PBE_TYPE_INVALID = 0,
    PBE_TYPE_SCRYPT, PBE_TYPE_PBKDF2, PBE_TYPE_PKCS12
} PBE_TYPE;
typedef struct pbe_data_st {
    PBE_TYPE pbe_type;
        /* scrypt parameters */
    uint64_t N, r, p, maxmem;
        /* PKCS#12 parameters */
    int id, iter;
    const EVP_MD *md;
        /* password */
    unsigned char *pass;
    size_t pass_len;
        /* salt */
    unsigned char *salt;
    size_t salt_len;
        /* Expected output */
    unsigned char *key;
    size_t key_len;
} PBE_DATA;
#ifndef OPENSSL_NO_SCRYPT
#endif
#ifndef OPENSSL_NO_SCRYPT
#else
#endif
#ifndef OPENSSL_NO_SCRYPT
#endif
#ifndef OPENSSL_NO_SCRYPT
#endif
typedef enum {
    BASE64_CANONICAL_ENCODING = 0,
    BASE64_VALID_ENCODING = 1,
    BASE64_INVALID_ENCODING = 2
} base64_encoding_type;
typedef struct encode_data_st {
    /* Input to encoding */
    unsigned char *input;
    size_t input_len;
    /* Expected output */
    unsigned char *output;
    size_t output_len;
    base64_encoding_type encoding;
} ENCODE_DATA;
typedef struct kdf_data_st {
    /* Context for this operation */
    EVP_PKEY_CTX *ctx;
    /* Expected output */
    unsigned char *output;
    size_t output_len;
} KDF_DATA;
#ifdef OPENSSL_NO_SCRYPT
#endif
typedef struct keypair_test_data_st {
    EVP_PKEY *privk;
    EVP_PKEY *pubk;
} KEYPAIR_TEST_DATA;
typedef struct keygen_test_data_st {
    EVP_PKEY_CTX *genctx; /* Keygen context to use */
    char *keyname; /* Key name to store key or NULL */
} KEYGEN_TEST_DATA;
typedef struct {
    int is_verify; /* Set to 1 if verifying */
    int is_oneshot; /* Set to 1 for one shot operation */
    const EVP_MD *md; /* Digest to use */
    EVP_MD_CTX *ctx; /* Digest context */
    EVP_PKEY_CTX *pctx;
    STACK_OF(EVP_TEST_BUFFER) *input; /* Input data: streaming */
    unsigned char *osin; /* Input data if one shot */
    size_t osin_len; /* Input length data if one shot */
    unsigned char *output; /* Expected output */
    size_t output_len; /* Expected output length */
} DIGESTSIGN_DATA;
#ifndef OPENSSL_NO_EC
#endif /* OPENSSL_NO_EC */
#ifdef OPENSSL_NO_SM2
#else
#endif
