#include "e_os.h"
#ifndef _BSD_SOURCE
# define _BSD_SOURCE 1
#endif
#ifndef _DEFAULT_SOURCE
# define _DEFAULT_SOURCE 1
#endif
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "internal/nelem.h"
#ifdef OPENSSL_SYS_VMS
# define _XOPEN_SOURCE 500
#endif
#include <ctype.h>
#include <openssl/bio.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#ifndef OPENSSL_NO_RSA
# include <openssl/rsa.h>
#endif
#ifndef OPENSSL_NO_DSA
# include <openssl/dsa.h>
#endif
#ifndef OPENSSL_NO_DH
# include <openssl/dh.h>
#endif
#include <openssl/bn.h>
#ifndef OPENSSL_NO_CT
# include <openssl/ct.h>
#endif
#define _XOPEN_SOURCE_EXTENDED  1
#ifdef OPENSSL_SYS_WINDOWS
# include <winsock.h>
#else
# include OPENSSL_UNISTD
#endif
#define COMP_ZLIB       1
#define APP_CALLBACK_STRING "Test Callback Argument"
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#define TACK_EXT_TYPE 62208
#define CUSTOM_EXT_TYPE_0 1000
#define CUSTOM_EXT_TYPE_1 1001
#define CUSTOM_EXT_TYPE_2 1002
#define CUSTOM_EXT_TYPE_3 1003
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SSL3
#endif
#ifndef OPENSSL_NO_TLS1
#endif
#ifndef OPENSSL_NO_DTLS
#ifndef OPENSSL_NO_DTLS1
#endif
#ifndef OPENSSL_NO_DTLS1_2
#endif
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_DH
#else
#endif
#ifndef OPENSSL_NO_DH
#else
#endif
#ifndef OPENSSL_NO_PSK
#else
#endif
#ifndef OPENSSL_NO_SOCK
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifdef OPENSSL_NO_SSL3
#endif
#ifdef OPENSSL_NO_TLS1
#endif
#ifdef OPENSSL_NO_TLS1_2
#endif
#if defined(OPENSSL_NO_DTLS) || defined(OPENSSL_NO_DTLS1)
#endif
#if defined(OPENSSL_NO_DTLS) || defined(OPENSSL_NO_DTLS1_2)
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifndef OPENSSL_NO_TLS
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_DH
#else
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_SOCK
#else
#endif
#ifdef CLOCKS_PER_SEC
#else
#endif
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
#endif
#ifndef OPENSSL_NO_SOCK
# ifndef OPENSSL_NO_NEXTPROTONEG
# endif
# ifndef OPENSSL_NO_NEXTPROTONEG
# endif
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#define W_READ  1
#define W_WRITE 2
#define C_DONE  1
#define S_DONE  2
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_PSK
#endif
