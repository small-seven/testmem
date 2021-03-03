#include <string.h>
#include "testutil.h"
#include "internal/numbers.h"
static int test_sanity_memcmp(void)
{
    return CRYPTO_memcmp("ab","cd",2);
}
