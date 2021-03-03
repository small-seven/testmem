#include <limits.h>
#include <string.h>
#include <stdio.h>
#include "../ssl_local.h"
#include "statem_local.h"
#include "internal/cryptlib.h"
#include <openssl/buffer.h>
#include <openssl/objects.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
typedef struct x509err2alert_st {
    int x509err;
    int alert;
} X509ERR2ALERT;
#define TLS13_TBS_START_SIZE            64
#define TLS13_TBS_PREAMBLE_SIZE         (TLS13_TBS_START_SIZE + 33 + 1)
#ifdef CHARSET_EBCDIC
#else
#endif
#ifndef OPENSSL_NO_GOST
#endif
#ifndef OPENSSL_NO_GOST
#endif
#ifdef SSL_DEBUG
#endif
#ifndef OPENSSL_NO_GOST
#endif
#ifdef SSL_DEBUG
#endif
#ifndef OPENSSL_NO_GOST
#endif
#ifndef OPENSSL_NO_GOST
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#if 0
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#define SERVER_HELLO_RANDOM_OFFSET  (SSL3_HM_HEADER_LENGTH + 2)
typedef struct {
    int version;
    const SSL_METHOD *(*cmeth) (void);
    const SSL_METHOD *(*smeth) (void);
} version_info;
#if TLS_MAX_VERSION != TLS1_3_VERSION
# error Code needs update for TLS_method() support beyond TLS1_3_VERSION.
#endif
#ifndef OPENSSL_NO_TLS1_3
#else
#endif
#ifndef OPENSSL_NO_TLS1_2
#else
#endif
#ifndef OPENSSL_NO_TLS1_1
#else
#endif
#ifndef OPENSSL_NO_TLS1
#else
#endif
#ifndef OPENSSL_NO_SSL3
#else
#endif
#if DTLS_MAX_VERSION != DTLS1_2_VERSION
# error Code needs update for DTLS_method() support beyond DTLS1_2_VERSION.
#endif
#ifndef OPENSSL_NO_DTLS1_2
#else
#endif
#ifndef OPENSSL_NO_DTLS1
#else
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_EC
#else
#endif
#ifndef OPENSSL_NO_EC
#endif
