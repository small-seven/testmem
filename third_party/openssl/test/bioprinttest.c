#define TESTUTIL_NO_size_t_COMPARISON
#include <stdio.h>
#include <string.h>
#include <openssl/bio.h>
#include "internal/numbers.h"
#include "testutil.h"
#include "testutil/output.h"
#define nelem(x) (int)(sizeof(x) / sizeof((x)[0]))
typedef struct z_data_st {
    size_t value;
    const char *format;
    const char *expected;
} z_data;
typedef struct j_data_st {
    uint64_t value;
    const char *format;
    const char *expected;
} j_data;
typedef struct pw_st {
    int p;
    const char *w;
} pw;
