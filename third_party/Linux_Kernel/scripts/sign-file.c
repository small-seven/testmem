#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <getopt.h>
#include <err.h>
#include <arpa/inet.h>
#include <openssl/opensslv.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/engine.h>
#if OPENSSL_VERSION_NUMBER < 0x10000000L
#define USE_PKCS7
#endif
#ifndef USE_PKCS7
#include <openssl/cms.h>
#else
#include <openssl/pkcs7.h>
#endif
#define PKEY_ID_PKCS7 2
#define ERR(cond, fmt, ...)				\
#ifndef USE_PKCS7
#else
#endif
#ifndef USE_PKCS7
#else
#endif
#ifndef USE_PKCS7
#endif
#ifdef USE_PKCS7
#endif
#ifndef USE_PKCS7
#else
#endif
#ifndef USE_PKCS7
#else
#endif
#ifndef USE_PKCS7
#else
#endif
