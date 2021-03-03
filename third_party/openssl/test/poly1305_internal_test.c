#include <stdio.h>
#include <string.h>
#include "testutil.h"
#include "crypto/poly1305.h"
#include "../crypto/poly1305/poly1305_local.h"
#include "internal/nelem.h"
typedef struct {
    size_t size;
    const unsigned char data[1024];
} SIZED_DATA;
typedef struct {
    SIZED_DATA input;
    SIZED_DATA key;
    SIZED_DATA expected;
} TESTDATA;
