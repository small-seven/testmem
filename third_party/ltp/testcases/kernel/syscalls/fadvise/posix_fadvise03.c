#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#include "lapi/abisize.h"
#if defined(__s390__) && defined(TST_ABI32)
#else
#endif
#define ADVISE_LIMIT 32
