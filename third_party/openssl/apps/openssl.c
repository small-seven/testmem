#include <internal/cryptlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/bio.h>
#include <openssl/crypto.h>
#include <openssl/lhash.h>
#include <openssl/conf.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#ifndef OPENSSL_NO_ENGINE
# include <openssl/engine.h>
#endif
#include <openssl/err.h>
#ifdef OPENSSL_SYS_VMS
# include <unixio.h>
#endif
#include "apps.h"
#define INCLUDE_FUNCTION_TABLE
#include "progs.h"
typedef struct {
    int columns;
    int width;
} DISPLAY_COLUMNS;
#define EXIT_THE_PROGRAM (-1)
#ifdef SIGPIPE
#endif
#ifndef OPENSSL_SYS_VMS
#endif
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
#elif defined(_WIN32)
#endif
#ifndef READLINE
#else
#endif
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
#endif
typedef enum HELPLIST_CHOICE {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP, OPT_ONE,
    OPT_COMMANDS, OPT_DIGEST_COMMANDS, OPT_OPTIONS,
    OPT_DIGEST_ALGORITHMS, OPT_CIPHER_COMMANDS, OPT_CIPHER_ALGORITHMS,
    OPT_PK_ALGORITHMS, OPT_PK_METHOD, OPT_DISABLED, OPT_MISSING_HELP
} HELPLIST_CHOICE;
typedef enum HELP_CHOICE {
    OPT_hERR = -1, OPT_hEOF = 0, OPT_hHELP
} HELP_CHOICE;
#ifdef OPENSSL_NO_ARIA
#endif
#ifdef OPENSSL_NO_BF
#endif
#ifdef OPENSSL_NO_BLAKE2
#endif
#ifdef OPENSSL_NO_CAMELLIA
#endif
#ifdef OPENSSL_NO_CAST
#endif
#ifdef OPENSSL_NO_CMAC
#endif
#ifdef OPENSSL_NO_CMS
#endif
#ifdef OPENSSL_NO_COMP
#endif
#ifdef OPENSSL_NO_DES
#endif
#ifdef OPENSSL_NO_DGRAM
#endif
#ifdef OPENSSL_NO_DH
#endif
#ifdef OPENSSL_NO_DSA
#endif
#if defined(OPENSSL_NO_DTLS)
#endif
#if defined(OPENSSL_NO_DTLS1)
#endif
#if defined(OPENSSL_NO_DTLS1_2)
#endif
#ifdef OPENSSL_NO_EC
#endif
#ifdef OPENSSL_NO_EC2M
#endif
#ifdef OPENSSL_NO_ENGINE
#endif
#ifdef OPENSSL_NO_GOST
#endif
#ifdef OPENSSL_NO_HEARTBEATS
#endif
#ifdef OPENSSL_NO_IDEA
#endif
#ifdef OPENSSL_NO_MD2
#endif
#ifdef OPENSSL_NO_MD4
#endif
#ifdef OPENSSL_NO_MD5
#endif
#ifdef OPENSSL_NO_MDC2
#endif
#ifdef OPENSSL_NO_OCB
#endif
#ifdef OPENSSL_NO_OCSP
#endif
#ifdef OPENSSL_NO_PSK
#endif
#ifdef OPENSSL_NO_RC2
#endif
#ifdef OPENSSL_NO_RC4
#endif
#ifdef OPENSSL_NO_RC5
#endif
#ifdef OPENSSL_NO_RMD160
#endif
#ifdef OPENSSL_NO_RSA
#endif
#ifdef OPENSSL_NO_SCRYPT
#endif
#ifdef OPENSSL_NO_SCTP
#endif
#ifdef OPENSSL_NO_SEED
#endif
#ifdef OPENSSL_NO_SM2
#endif
#ifdef OPENSSL_NO_SM3
#endif
#ifdef OPENSSL_NO_SM4
#endif
#ifdef OPENSSL_NO_SOCK
#endif
#ifdef OPENSSL_NO_SRP
#endif
#ifdef OPENSSL_NO_SRTP
#endif
#ifdef OPENSSL_NO_SSL3
#endif
#ifdef OPENSSL_NO_TLS1
#endif
#ifdef OPENSSL_NO_TLS1_1
#endif
#ifdef OPENSSL_NO_TLS1_2
#endif
#ifdef OPENSSL_NO_WHIRLPOOL
#endif
#ifndef ZLIB
#endif
