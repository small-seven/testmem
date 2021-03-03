#include "test.h"
#include "testutil.h"
#include "warnless.h"
#include "memdebug.h"
#ifdef HAVE_PTHREAD_H
#include <pthread.h>
#include <unistd.h>
#define TEST_HANG_TIMEOUT 60 * 1000
#define CONN_NUM 3
#define TIME_BETWEEN_START_SECS 2
#else /* without pthread, this test doesn't work */
#endif
