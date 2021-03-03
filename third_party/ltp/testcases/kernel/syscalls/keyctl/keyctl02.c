#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include "tst_safe_pthread.h"
#include "tst_test.h"
#include "lapi/keyctl.h"
#define LOOPS	20000
#define MAX_WAIT_FOR_GC_MS 5000
#define PATH_KEY_COUNT_QUOTA	"/proc/sys/kernel/keys/root_maxkeys"
