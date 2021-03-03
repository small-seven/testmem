#include <stdint.h>
#include <limits.h>
#include <errno.h>
#include <sys/syscall.h>
#include <linux/futex.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/futex.h"
#define DEFAULT_MSEC_TIMEOUT 10000
