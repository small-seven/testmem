#include "test.h"
#include <limits.h>
#include "testutil.h"
#include "warnless.h"
#include "memdebug.h"
#define TEST_HANG_TIMEOUT 60 * 1000
#define PROXY libtest_arg2
#define PROXYUSERPWD libtest_arg3
#define HOST test_argv[4]
#define NUM_HANDLES 2
