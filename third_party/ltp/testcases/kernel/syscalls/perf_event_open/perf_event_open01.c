#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <linux/unistd.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include "config.h"
#if HAVE_PERF_EVENT_ATTR
# include <linux/perf_event.h>
#endif
#include "test.h"
#include "lapi/syscalls.h"
#include "safe_macros.h"
#if HAVE_PERF_EVENT_ATTR
#define LOOPS	100000000
#else
#endif
