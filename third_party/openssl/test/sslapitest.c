#include <string.h>
#include <openssl/opensslconf.h>
#include <openssl/bio.h>
#include <openssl/crypto.h>
#include <openssl/ssl.h>
#include <openssl/ocsp.h>
#include <openssl/srp.h>
#include <openssl/txt_db.h>
#include <openssl/aes.h>
#include "ssltestlib.h"
#include "testutil.h"
#include "testutil/output.h"
#include "internal/nelem.h"
#include "../ssl/ssl_local.h"
#ifndef OPENSSL_NO_TLS1_3
#endif
#define LOG_BUFFER_SIZE 2048
#ifndef OPENSSL_NO_OCSP
#endif
#define NUM_EXTRA_CERTS 40
#define CLIENT_VERSION_LEN      2
#if !defined(OPENSSL_NO_TLS1_2) || defined(OPENSSL_NO_TLS1_3)
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_TLS1_2
#ifdef OPENSSL_NO_EC
#else
#endif
#ifndef OPENSSL_NO_EC
#endif
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#if !defined(OPENSSL_NO_TLS1_3) || !defined(OPENSSL_NO_TLS1_2)
# ifndef OPENSSL_NO_TLS1_1
# endif
# if !defined(OPENSSL_NO_TLS1_1)
# endif
# ifndef OPENSSL_NO_TLS1_1
# endif
#endif /* !defined(OPENSSL_NO_TLS1_3) || !defined(OPENSSL_NO_TLS1_2) */
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_TLS1_2
#else
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_TLS1_2
#else
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_TLS1_2
#else
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#define USE_NULL            0
#define USE_BIO_1           1
#define USE_BIO_2           2
#define USE_DEFAULT         3
#define CONNTYPE_CONNECTION_SUCCESS  0
#define CONNTYPE_CONNECTION_FAIL     1
#define CONNTYPE_NO_CONNECTION       2
#define TOTAL_NO_CONN_SSL_SET_BIO_TESTS         (3 * 3 * 3 * 3)
#define TOTAL_CONN_SUCCESS_SSL_SET_BIO_TESTS    (2 * 2)
#if !defined(OPENSSL_NO_TLS1_3) && !defined(OPENSSL_NO_TLS1_2)
# define TOTAL_CONN_FAIL_SSL_SET_BIO_TESTS       (2 * 2)
#else
# define TOTAL_CONN_FAIL_SSL_SET_BIO_TESTS       0
#endif
#define TOTAL_SSL_SET_BIO_TESTS TOTAL_NO_CONN_SSL_SET_BIO_TESTS \
typedef enum { NO_BIO_CHANGE, CHANGE_RBIO, CHANGE_WBIO } bio_change_t;

static int execute_test_ssl_bio(int pop_ssl, bio_change_t change_bio)
{
    BIO *sslbio = NULL, *membio1 = NULL, *membio2 = NULL;
    SSL_CTX *ctx;
    SSL *ssl = NULL;
    int testresult = 0;

    if (!TEST_ptr(ctx = SSL_CTX_new(TLS_method()))
            || !TEST_ptr(ssl = SSL_new(ctx))
            || !TEST_ptr(sslbio = BIO_new(BIO_f_ssl()))
            || !TEST_ptr(membio1 = BIO_new(BIO_s_mem())))
        goto end;

    BIO_set_ssl(sslbio, ssl, BIO_CLOSE);

    /*
     * If anything goes wrong here then we could leak memory, so this will
     * be caught in a crypto-mdebug build
     */
    BIO_push(sslbio, membio1);

    /* Verify changing the rbio/wbio directly does not cause leaks */
    if (change_bio != NO_BIO_CHANGE) {
        if (!TEST_ptr(membio2 = BIO_new(BIO_s_mem())))
            goto end;
        if (change_bio == CHANGE_RBIO)
            SSL_set0_rbio(ssl, membio2);
        else
            SSL_set0_wbio(ssl, membio2);
    }
#if !defined(OPENSSL_NO_TLS1_2) || defined(OPENSSL_NO_TLS1_3)
typedef struct {
    /* The list of sig algs */
    const int *list;
    /* The length of the list */
    size_t listlen;
    /* A sigalgs list in string format */
    const char *liststr;
    /* Whether setting the list should succeed */
    int valid;
    /* Whether creating a connection with the list should succeed */
    int connsuccess;
} sigalgs_list;
# ifndef OPENSSL_NO_EC
# endif
# ifndef OPENSSL_NO_EC
# endif
# ifndef OPENSSL_NO_EC
# endif
#endif
#ifndef OPENSSL_NO_TLS1_3
#ifndef OPENSSL_NO_PSK
#endif /* OPENSSL_NO_PSK */
#ifndef OPENSSL_NO_PSK
#endif /* OPENSSL_NO_PSK */
#define MSG1    "Hello"
#define MSG2    "World."
#define MSG3    "This"
#define MSG4    "is"
#define MSG5    "a"
#define MSG6    "test"
#define MSG7    "message."
#define TLS13_AES_256_GCM_SHA384_BYTES  ((const unsigned char *)"\x13\x02")
#define TLS13_AES_128_GCM_SHA256_BYTES  ((const unsigned char *)"\x13\x01")
#define GOODALPNLEN     9
#define BADALPNLEN      8
#define GOODALPN        (alpnlist)
#define BADALPN         (alpnlist + GOODALPNLEN)
# ifndef OPENSSL_NO_TLS1_2
# endif /* OPENSSL_NO_TLS1_2 */
# if !defined(OPENSSL_NO_CHACHA) && !defined(OPENSSL_NO_POLY1305)
# endif
# if !defined(OPENSSL_NO_CHACHA) && !defined(OPENSSL_NO_POLY1305)
# endif
# ifdef OPENSSL_NO_TLS1_2
# endif
# ifndef OPENSSL_NO_TLS1_2
# endif
#ifndef OPENSSL_NO_PSK
#endif
#endif /* OPENSSL_NO_TLS1_3 */
#define TEST_EXT_TYPE1  0xff00
#if defined(OPENSSL_NO_TLS1_2) && !defined(OPENSSL_NO_TLS1_3)
#endif
#define SMALL_LABEL_LEN 10
#define LONG_LABEL_LEN  249
#ifdef OPENSSL_NO_TLS1
#endif
#ifdef OPENSSL_NO_TLS1_1
#endif
#ifdef OPENSSL_NO_TLS1_2
#endif
#ifdef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_TLS1_3
#define NUM_KEY_UPDATE_MESSAGES 40
#endif /* OPENSSL_NO_TLS1_3 */
#ifdef OPENSSL_NO_TLS1_2
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#if !defined(OPENSSL_NO_SRP) && !defined(OPENSSL_NO_TLS1_2)
#endif
#if !defined(OPENSSL_NO_TLS1_2) && (!defined(OPENSSL_NO_EC) \
#else
#endif
#ifndef OPENSSL_NO_TLS1_3
#else
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_DTLS
#else
#endif
#if defined(OPENSSL_NO_TLS1_3) || !defined(OPENSSL_NO_TLS1_2)
#endif
#if !defined(OPENSSL_NO_TLS1_3) && !defined(OPENSSL_NO_TLS1_2) \
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifdef OPENSSL_NO_TLS1_2
#endif
#ifdef OPENSSL_NO_TLS1_3
#endif
#ifdef OPENSSL_NO_TLS1_2
#endif
#ifdef OPENSSL_NO_TLS1_3
#endif
#if !defined(OPENSSL_NO_TLS1_2) || !defined(OPENSSL_NO_TLS1_3)
#ifdef OPENSSL_NO_EC
#endif
#endif
#ifndef OPENSSL_NO_TLS1_2
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifdef OPENSSL_NO_TLS1_2
#endif
#ifdef OPENSSL_NO_TLS1_3
#endif
#if !defined(OPENSSL_NO_TLS1_2) || !defined(OPENSSL_NO_TLS1_3)
#endif
#ifndef OPENSSL_NO_TLS1_2
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifdef OPENSSL_NO_TLS1_2
#endif
#ifdef OPENSSL_NO_TLS1_3
#endif
#ifdef OPENSSL_NO_CRYPTO_MDEBUG
#else
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#if !defined(OPENSSL_NO_TLS1_2) || defined(OPENSSL_NO_TLS1_3)
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_TLS1_2
#endif
#ifndef OPENSSL_NO_TLS1_3
# ifndef OPENSSL_NO_TLS1_2
# endif
#endif
#ifndef OPENSSL_NO_TLS1_3
#ifdef OPENSSL_NO_PSK
#else
#endif  /* OPENSSL_NO_PSK */
#else
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#if !defined(OPENSSL_NO_SRP) && !defined(OPENSSL_NO_TLS1_2)
#endif
