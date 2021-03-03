#include "testutil.h"
#include <openssl/ssl.h>
typedef struct {
    int min_version;
    int max_version;
    int min_ok;
    int max_ok;
    int expected_min;
    int expected_max;
} version_test;
