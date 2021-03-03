#undef SECONDS
#define SECONDS                 3
#define RSA_SECONDS             10
#define DSA_SECONDS             10
#define ECDSA_SECONDS   10
#define ECDH_SECONDS    10
#define EdDSA_SECONDS   10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "apps.h"
#include "progs.h"
#include <openssl/crypto.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/objects.h>
#include <openssl/async.h>
#if !defined(OPENSSL_SYS_MSDOS)
# include OPENSSL_UNISTD
#endif
#if defined(_WIN32)
# include <windows.h>
#endif
#include <openssl/bn.h>
#ifndef OPENSSL_NO_DES
# include <openssl/des.h>
#endif
#include <openssl/aes.h>
#ifndef OPENSSL_NO_CAMELLIA
# include <openssl/camellia.h>
#endif
#ifndef OPENSSL_NO_MD2
# include <openssl/md2.h>
#endif
#ifndef OPENSSL_NO_MDC2
# include <openssl/mdc2.h>
#endif
#ifndef OPENSSL_NO_MD4
# include <openssl/md4.h>
#endif
#ifndef OPENSSL_NO_MD5
# include <openssl/md5.h>
#endif
#include <openssl/hmac.h>
#include <openssl/sha.h>
#ifndef OPENSSL_NO_RMD160
# include <openssl/ripemd.h>
#endif
#ifndef OPENSSL_NO_WHIRLPOOL
# include <openssl/whrlpool.h>
#endif
#ifndef OPENSSL_NO_RC4
# include <openssl/rc4.h>
#endif
#ifndef OPENSSL_NO_RC5
# include <openssl/rc5.h>
#endif
#ifndef OPENSSL_NO_RC2
# include <openssl/rc2.h>
#endif
#ifndef OPENSSL_NO_IDEA
# include <openssl/idea.h>
#endif
#ifndef OPENSSL_NO_SEED
# include <openssl/seed.h>
#endif
#ifndef OPENSSL_NO_BF
# include <openssl/blowfish.h>
#endif
#ifndef OPENSSL_NO_CAST
# include <openssl/cast.h>
#endif
#ifndef OPENSSL_NO_RSA
# include <openssl/rsa.h>
# include "./testrsa.h"
#endif
#include <openssl/x509.h>
#ifndef OPENSSL_NO_DSA
# include <openssl/dsa.h>
# include "./testdsa.h"
#endif
#ifndef OPENSSL_NO_EC
# include <openssl/ec.h>
#endif
#include <openssl/modes.h>
#ifndef HAVE_FORK
# if defined(OPENSSL_SYS_VMS) || defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_VXWORKS)
#  define HAVE_FORK 0
# else
#  define HAVE_FORK 1
# endif
#endif
#if HAVE_FORK
# undef NO_FORK
#else
# define NO_FORK
#endif
#define MAX_MISALIGNMENT 63
#define MAX_ECDH_SIZE   256
#define MISALIGN        64
typedef struct openssl_speed_sec_st {
    int sym;
    int rsa;
    int dsa;
    int ecdsa;
    int ecdh;
    int eddsa;
} openssl_speed_sec_t;
#ifndef OPENSSL_NO_MD2
#endif
#ifndef OPENSSL_NO_MDC2
#endif
#ifndef OPENSSL_NO_MD4
#endif
#ifndef OPENSSL_NO_MD5
#endif
#ifndef OPENSSL_NO_WHIRLPOOL
#endif
#ifndef OPENSSL_NO_RMD160
#endif
#ifndef OPENSSL_NO_RC4
#endif
#ifndef OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef NO_FORK
#endif
#define START   0
#define STOP    1
#ifdef SIGALRM
#elif defined(_WIN32)
# define SIGALRM -1
# define alarm alarm_win32
#else
#endif
#define found(value, pairs, result)\
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_ELAPSED, OPT_EVP, OPT_DECRYPT, OPT_ENGINE, OPT_MULTI,
    OPT_MR, OPT_MB, OPT_MISALIGN, OPT_ASYNCJOBS, OPT_R_ENUM,
    OPT_PRIMES, OPT_SECONDS, OPT_BYTES, OPT_AEAD
} OPTION_CHOICE;
#ifndef NO_FORK
#endif
#ifndef OPENSSL_NO_ASYNC
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#define D_MD2           0
#define D_MDC2          1
#define D_MD4           2
#define D_MD5           3
#define D_HMAC          4
#define D_SHA1          5
#define D_RMD160        6
#define D_RC4           7
#define D_CBC_DES       8
#define D_EDE3_DES      9
#define D_CBC_IDEA      10
#define D_CBC_SEED      11
#define D_CBC_RC2       12
#define D_CBC_RC5       13
#define D_CBC_BF        14
#define D_CBC_CAST      15
#define D_CBC_128_AES   16
#define D_CBC_192_AES   17
#define D_CBC_256_AES   18
#define D_CBC_128_CML   19
#define D_CBC_192_CML   20
#define D_CBC_256_CML   21
#define D_EVP           22
#define D_SHA256        23
#define D_SHA512        24
#define D_WHIRLPOOL     25
#define D_IGE_128_AES   26
#define D_IGE_192_AES   27
#define D_IGE_256_AES   28
#define D_GHASH         29
#define D_RAND          30
#define ALGOR_NUM       OSSL_NELEM(names)
#ifndef OPENSSL_NO_MD2
#endif
#ifndef OPENSSL_NO_MDC2
#endif
#ifndef OPENSSL_NO_MD4
#endif
#ifndef OPENSSL_NO_MD5
#endif
#ifndef OPENSSL_NO_WHIRLPOOL
#endif
#ifndef OPENSSL_NO_RMD160
#endif
#ifndef OPENSSL_NO_RC4
#endif
#ifndef OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_RC2
#endif
#ifndef OPENSSL_NO_RC5
#endif
#ifndef OPENSSL_NO_IDEA
#endif
#ifndef OPENSSL_NO_SEED
#endif
#ifndef OPENSSL_NO_BF
#endif
#ifndef OPENSSL_NO_CAST
#endif
#ifndef OPENSSL_NO_DSA
# define R_DSA_512       0
# define R_DSA_1024      1
# define R_DSA_2048      2
# define DSA_NUM         OSSL_NELEM(dsa_choices)
#endif  /* OPENSSL_NO_DSA */
#define R_RSA_512       0
#define R_RSA_1024      1
#define R_RSA_2048      2
#define R_RSA_3072      3
#define R_RSA_4096      4
#define R_RSA_7680      5
#define R_RSA_15360     6
#ifndef OPENSSL_NO_RSA
# define RSA_NUM OSSL_NELEM(rsa_choices)
#endif /* OPENSSL_NO_RSA */
#ifndef OPENSSL_NO_EC2M
#endif
#ifndef OPENSSL_NO_EC
# ifndef OPENSSL_NO_EC2M
# endif
# define ECDSA_NUM       OSSL_NELEM(ecdsa_choices)
# ifndef OPENSSL_NO_EC2M
# endif
# define EC_NUM       OSSL_NELEM(ecdh_choices)
#define R_EC_Ed25519    0
#define R_EC_Ed448      1
# define EdDSA_NUM       OSSL_NELEM(eddsa_choices)
#endif /* OPENSSL_NO_EC */
#ifndef SIGALRM
# define COND(d) (count < (d))
# define COUNT(d) (d)
#else
# define COND(unused_cond) (run && count<0x7fffffff)
# define COUNT(d) (count)
#endif                          /* SIGALRM */
typedef struct loopargs_st {
    ASYNC_JOB *inprogress_job;
    ASYNC_WAIT_CTX *wait_ctx;
    unsigned char *buf;
    unsigned char *buf2;
    unsigned char *buf_malloc;
    unsigned char *buf2_malloc;
    unsigned char *key;
    unsigned int siglen;
    size_t sigsize;
#ifndef OPENSSL_NO_RSA
    RSA *rsa_key[RSA_NUM];
#endif
#ifndef OPENSSL_NO_DSA
    DSA *dsa_key[DSA_NUM];
#endif
#ifndef OPENSSL_NO_EC
    EC_KEY *ecdsa[ECDSA_NUM];
    EVP_PKEY_CTX *ecdh_ctx[EC_NUM];
    EVP_MD_CTX *eddsa_ctx[EdDSA_NUM];
    unsigned char *secret_a;
    unsigned char *secret_b;
    size_t outlen[EC_NUM];
#endif
    EVP_CIPHER_CTX *ctx;
    HMAC_CTX *hctx;
    GCM128_CONTEXT *gcm_ctx;
} loopargs_t;
#ifndef OPENSSL_NO_MD2
#endif
#ifndef OPENSSL_NO_MDC2
#endif
#ifndef OPENSSL_NO_MD4
#endif
#ifndef OPENSSL_NO_MD5
#endif
#ifndef OPENSSL_NO_WHIRLPOOL
#endif
#ifndef OPENSSL_NO_RMD160
#endif
#ifndef OPENSSL_NO_RC4
#endif
#ifndef OPENSSL_NO_DES
#endif
#define MAX_BLOCK_SIZE 128
#ifndef SIGALRM
#endif
#ifndef SIGALRM
#endif
#ifndef SIGALRM
#endif
#ifndef SIGALRM
#endif
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_EC
#endif                          /* OPENSSL_NO_EC */
#if defined(OPENSSL_SYS_WINDOWS)
#elif defined(OPENSSL_SYS_UNIX)
#endif
#if defined(OPENSSL_SYS_UNIX)
#elif defined(OPENSSL_SYS_WINDOWS)
#endif
#ifndef NO_FORK
#endif
#if !defined(OPENSSL_NO_RSA) || !defined(OPENSSL_NO_DSA) \
#endif
#ifndef OPENSSL_NO_RC5
#endif
#ifndef OPENSSL_NO_RC2
#endif
#ifndef OPENSSL_NO_IDEA
#endif
#ifndef OPENSSL_NO_SEED
#endif
#ifndef OPENSSL_NO_BF
#endif
#ifndef OPENSSL_NO_CAST
#endif
#ifndef OPENSSL_NO_CAMELLIA
#endif
#ifndef OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_EC
# ifndef OPENSSL_NO_EC2M
# endif
#endif                          /* ndef OPENSSL_NO_EC */
#ifndef NO_FORK
#endif
#ifndef OPENSSL_NO_ASYNC
#endif
#ifdef OPENSSL_NO_MULTIBLOCK
#endif
#ifndef OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_CAMELLIA
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef NO_FORK
#endif
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_CAMELLIA
#endif
#ifndef OPENSSL_NO_IDEA
#endif
#ifndef OPENSSL_NO_SEED
#endif
#ifndef OPENSSL_NO_RC4
#endif
#ifndef OPENSSL_NO_RC2
#endif
#ifndef OPENSSL_NO_RC5
#endif
#ifndef OPENSSL_NO_BF
#endif
#ifndef OPENSSL_NO_CAST
#endif
#ifndef SIGALRM
# ifndef OPENSSL_NO_DES
#  ifndef OPENSSL_NO_RSA
#  endif
#  ifndef OPENSSL_NO_DSA
#  endif
#  ifndef OPENSSL_NO_EC
#   ifndef OPENSSL_NO_EC2M
#   endif
#   ifndef OPENSSL_NO_EC2M
#   endif
#  endif
# else
#  error "You cannot disable DES on systems without SIGALRM."
# endif                         /* OPENSSL_NO_DES */
#elif SIGALRM > 0
#endif                          /* SIGALRM */
#ifndef OPENSSL_NO_MD2
#endif
#ifndef OPENSSL_NO_MDC2
#endif
#ifndef OPENSSL_NO_MD4
#endif
#ifndef OPENSSL_NO_MD5
#endif
#ifndef OPENSSL_NO_WHIRLPOOL
#endif
#ifndef OPENSSL_NO_RMD160
#endif
#ifndef OPENSSL_NO_RC4
#endif
#ifndef OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_CAMELLIA
#endif
#ifndef OPENSSL_NO_IDEA
#endif
#ifndef OPENSSL_NO_SEED
#endif
#ifndef OPENSSL_NO_RC2
#endif
#ifndef OPENSSL_NO_RC5
#endif
#ifndef OPENSSL_NO_BF
#endif
#ifndef OPENSSL_NO_CAST
#endif
#ifndef OPENSSL_NO_RSA
#endif                          /* OPENSSL_NO_RSA */
#ifndef OPENSSL_NO_DSA
#endif                          /* OPENSSL_NO_DSA */
#ifndef OPENSSL_NO_EC
#endif                          /* OPENSSL_NO_EC */
#ifndef NO_FORK
#endif
#ifndef OPENSSL_NO_MD2
#endif
#ifndef OPENSSL_NO_RC4
#endif
#ifndef OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_IDEA
#endif
#ifndef OPENSSL_NO_BF
#endif
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifdef SIGALRM
#else
#endif
#ifdef SIGALRM
#else
#endif
#ifndef NO_FORK
# ifndef OPENSSL_NO_DSA
# endif
# ifndef OPENSSL_NO_EC
# endif
#endif
