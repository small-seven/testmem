#include "test.h"
#include <fcntl.h>
#include "testutil.h"
#include "warnless.h"
#include "memdebug.h"
#define TEST_HANG_TIMEOUT 60 * 1000
#define NUM_HANDLES 4
#ifdef LIB527
#endif
#ifdef LIB532
#else
#endif
#if defined(LIB526)
#elif defined(LIB527)
#elif defined(LIB532)
#endif
