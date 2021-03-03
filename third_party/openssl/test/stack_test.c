#include <stdio.h>
#include <string.h>
#include <openssl/opensslconf.h>
#include <openssl/safestack.h>
#include <openssl/err.h>
#include <openssl/crypto.h>
#include "internal/nelem.h"
#include "testutil.h"
#ifdef __clang__
#pragma clang diagnostic ignored "-Wunused-function"
#endif
typedef struct {
    int n;
    char c;
} SS;
typedef union {
    int n;
    char c;
} SU;
