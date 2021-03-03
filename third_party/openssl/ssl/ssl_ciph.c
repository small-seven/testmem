#include <stdio.h>
#include <ctype.h>
#include <openssl/objects.h>
#include <openssl/comp.h>
#include <openssl/engine.h>
#include <openssl/crypto.h>
#include <openssl/conf.h>
#include "internal/nelem.h"
#include "ssl_local.h"
#include "internal/thread_once.h"
#include "internal/cryptlib.h"
#define SSL_ENC_DES_IDX         0
#define SSL_ENC_3DES_IDX        1
#define SSL_ENC_RC4_IDX         2
#define SSL_ENC_RC2_IDX         3
#define SSL_ENC_IDEA_IDX        4
#define SSL_ENC_NULL_IDX        5
#define SSL_ENC_AES128_IDX      6
#define SSL_ENC_AES256_IDX      7
#define SSL_ENC_CAMELLIA128_IDX 8
#define SSL_ENC_CAMELLIA256_IDX 9
#define SSL_ENC_GOST89_IDX      10
#define SSL_ENC_SEED_IDX        11
#define SSL_ENC_AES128GCM_IDX   12
#define SSL_ENC_AES256GCM_IDX   13
#define SSL_ENC_AES128CCM_IDX   14
#define SSL_ENC_AES256CCM_IDX   15
#define SSL_ENC_AES128CCM8_IDX  16
#define SSL_ENC_AES256CCM8_IDX  17
#define SSL_ENC_GOST8912_IDX    18
#define SSL_ENC_CHACHA_IDX      19
#define SSL_ENC_ARIA128GCM_IDX  20
#define SSL_ENC_ARIA256GCM_IDX  21
#define SSL_ENC_NUM_IDX         22
typedef struct {
    uint32_t mask;
    int nid;
} ssl_cipher_table;
#define SSL_COMP_NULL_IDX       0
#define SSL_COMP_ZLIB_IDX       1
#define SSL_COMP_NUM_IDX        2
#ifndef OPENSSL_NO_COMP
#endif
#define SSL_MD_NUM_IDX  SSL_MAX_DIGEST
#define ssl_cipher_info_lookup(table, x) \
#define CIPHER_ADD      1
#define CIPHER_KILL     2
#define CIPHER_DEL      3
#define CIPHER_ORD      4
#define CIPHER_SPECIAL  5
#define CIPHER_BUMP     6
typedef struct cipher_order_st {
    const SSL_CIPHER *cipher;
    int active;
    int dead;
    struct cipher_order_st *next, *prev;
} CIPHER_ORDER;
#ifdef OPENSSL_NO_ENGINE
#else
#endif
#ifdef OPENSSL_NO_RSA
#endif
#ifdef OPENSSL_NO_DSA
#endif
#ifdef OPENSSL_NO_DH
#endif
#ifdef OPENSSL_NO_EC
#endif
#ifdef OPENSSL_NO_PSK
#endif
#ifdef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifndef OPENSSL_NO_COMP
#endif
#define ITEM_SEP(a) \
#ifdef CIPHER_DEBUG
#endif
#ifdef CIPHER_DEBUG
#endif
#ifdef CIPHER_DEBUG
#endif
#ifndef CHARSET_EBCDIC
#else
#endif
#ifndef OPENSSL_NO_EC
# ifndef OPENSSL_NO_EC
# else
# endif
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifdef CIPHER_DEBUG
#endif
#ifdef OPENSSL_NO_COMP
#else
static void cmeth_free(SSL_COMP *cm)
{
    OPENSSL_free(cm);
}
#endif
#ifndef OPENSSL_NO_COMP
#else
#endif
#ifndef OPENSSL_NO_COMP
#else
#endif
#ifndef OPENSSL_NO_COMP
#else
#endif
