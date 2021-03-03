#include "test.h"
#include "testutil.h"
#include "warnless.h"
#include "memdebug.h"
#define TEST_HANG_TIMEOUT 60 * 1000
#define DNS_TIMEOUT 1
#if defined(WIN32) || defined(_WIN32)
#define sleep(sec) Sleep ((sec)*1000)
#endif
