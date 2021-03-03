#include <string.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include "testutil.h"
#include "internal/nelem.h"
typedef struct {
    const char *raw;
    const char *encoded;
} TESTDATA;
