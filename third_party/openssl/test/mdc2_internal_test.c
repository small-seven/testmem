#include <stdio.h>
#include <string.h>
#include <openssl/mdc2.h>
#include "testutil.h"
#include "internal/nelem.h"
typedef struct {
    const char *input;
    const unsigned char expected[MDC2_DIGEST_LENGTH];
} TESTDATA;
