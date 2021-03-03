#include <time.h>
#include <openssl/rand.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/dsa.h>
#include <openssl/ec.h>
#include <openssl/dh.h>
#include <openssl/err.h>
#include "fuzzer.h"
#include "rand.inc"
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DSA
#endif
#define FUZZTIME 1485898104
#define TIME_IMPL(t) { if (t != NULL) *t = FUZZTIME; return FUZZTIME; }
#if !defined(_WIN32)
#endif
#if !defined(OPENSSL_NO_EC) || !defined(OPENSSL_NO_DSA)
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DSA
#endif
