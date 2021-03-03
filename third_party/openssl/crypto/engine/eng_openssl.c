#include <stdio.h>
#include <openssl/crypto.h>
#include "internal/cryptlib.h"
#include "crypto/engine.h"
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/rsa.h>
#include <openssl/dsa.h>
#include <openssl/dh.h>
#include <openssl/hmac.h>
#include <openssl/x509v3.h>
#define TEST_ENG_OPENSSL_RC4
#ifndef OPENSSL_NO_STDIO
# define TEST_ENG_OPENSSL_PKEY
#endif
#ifndef OPENSSL_NO_STDIO
# define TEST_ENG_OPENSSL_RC4_P_INIT
#endif
#define TEST_ENG_OPENSSL_SHA
#ifdef OPENSSL_NO_RC4
# undef TEST_ENG_OPENSSL_RC4
# undef TEST_ENG_OPENSSL_RC4_OTHERS
# undef TEST_ENG_OPENSSL_RC4_P_INIT
# undef TEST_ENG_OPENSSL_RC4_P_CIPHER
#endif
#ifdef TEST_ENG_OPENSSL_RC4
#endif
#ifdef TEST_ENG_OPENSSL_SHA
#endif
#ifdef TEST_ENG_OPENSSL_PKEY
#endif
#ifdef TEST_ENG_OPENSSL_HMAC
#endif
#ifndef TEST_ENG_OPENSSL_NO_ALGORITHMS
# ifndef OPENSSL_NO_RSA
# endif
# ifndef OPENSSL_NO_DSA
# endif
# ifndef OPENSSL_NO_EC
# endif
# ifndef OPENSSL_NO_DH
# endif
# ifdef TEST_ENG_OPENSSL_RC4
# endif
# ifdef TEST_ENG_OPENSSL_SHA
# endif
#endif
#ifdef TEST_ENG_OPENSSL_PKEY
#endif
#ifdef TEST_ENG_OPENSSL_HMAC
#endif
#ifdef ENGINE_DYNAMIC_SUPPORT
#endif                          /* ENGINE_DYNAMIC_SUPPORT */
#ifdef TEST_ENG_OPENSSL_RC4
# include <openssl/rc4.h>
# define TEST_RC4_KEY_SIZE               16
typedef struct {
    unsigned char key[TEST_RC4_KEY_SIZE];
    RC4_KEY ks;
} TEST_RC4_KEY;
# define test(ctx) ((TEST_RC4_KEY *)EVP_CIPHER_CTX_get_cipher_data(ctx))
# ifdef TEST_ENG_OPENSSL_RC4_P_INIT
# endif
# ifdef TEST_ENG_OPENSSL_RC4_P_CIPHER
# endif
static void test_r4_cipher_destroy(void)
{
    EVP_CIPHER_meth_free(r4_cipher);
    r4_cipher = NULL;
}
static void test_r4_40_cipher_destroy(void)
{
    EVP_CIPHER_meth_free(r4_40_cipher);
    r4_40_cipher = NULL;
}
# ifdef TEST_ENG_OPENSSL_RC4_OTHERS
# endif
#endif
#ifdef TEST_ENG_OPENSSL_SHA
# include <openssl/sha.h>
# ifdef TEST_ENG_OPENSSL_SHA_P_INIT
# endif
# ifdef TEST_ENG_OPENSSL_SHA_P_UPDATE
# endif
# ifdef TEST_ENG_OPENSSL_SHA_P_FINAL
# endif
static void test_sha_md_destroy(void)
{
    EVP_MD_meth_free(sha1_md);
    sha1_md = NULL;
}
# ifdef TEST_ENG_OPENSSL_SHA_OTHERS
# endif
#endif
#ifdef TEST_ENG_OPENSSL_PKEY
#endif
#ifdef TEST_ENG_OPENSSL_HMAC
typedef struct {
    const EVP_MD *md;           /* MD for HMAC use */
    ASN1_OCTET_STRING ktmp;     /* Temp storage for key */
    HMAC_CTX *ctx;
} OSSL_HMAC_PKEY_CTX;
# ifdef TEST_ENG_OPENSSL_HMAC_INIT
# endif
#endif
int openssl_destroy(ENGINE *e)
{
    test_sha_md_destroy();
#ifdef TEST_ENG_OPENSSL_RC4
    test_r4_cipher_destroy();
    test_r4_40_cipher_destroy();
#endif
    return 1;
}
