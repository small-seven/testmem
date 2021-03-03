#include <stdio.h>
#include <string.h>
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include <openssl/dh.h>
#include <openssl/ec.h>
#include <openssl/ocsp.h>
#include <openssl/pkcs12.h>
#include <openssl/rsa.h>
#include <openssl/ts.h>
#include <openssl/x509v3.h>
#include <openssl/cms.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>
#include "fuzzer.h"
#include "rand.inc"
#ifndef OPENSSL_NO_RFC3779
#endif
#ifndef OPENSSL_NO_RFC3779
#endif
#ifndef OPENSSL_NO_CMS
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_RFC3779
#endif
#if OPENSSL_API_COMPAT < 0x10200000L
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#if OPENSSL_API_COMPAT < 0x10200000L
#endif
#define DO_TEST(TYPE, D2I, I2D, PRINT) { \
#define DO_TEST_PRINT_OFFSET(TYPE, D2I, I2D, PRINT) { \
#define DO_TEST_PRINT_PCTX(TYPE, D2I, I2D, PRINT) { \
#define DO_TEST_NO_PRINT(TYPE, D2I, I2D) { \
#ifndef OPENSSL_NO_TS
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_EC
#endif
