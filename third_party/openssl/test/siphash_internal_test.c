#include <stdio.h>
#include <string.h>
#include <openssl/bio.h>
#include "testutil.h"
#include "crypto/siphash.h"
#include "../crypto/siphash/siphash_local.h"
#include "internal/nelem.h"
typedef struct {
    size_t size;
    unsigned char data[64];
} SIZED_DATA;
typedef struct {
    int idx;
    SIZED_DATA expected;
} TESTDATA;
