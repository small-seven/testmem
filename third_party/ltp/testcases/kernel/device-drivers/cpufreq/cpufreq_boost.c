#define _GNU_SOURCE
#include <errno.h>
#include <sched.h>
#include <time.h>
#include "test.h"
#include "lapi/posix_clocks.h"
#include "safe_macros.h"
#define SYSFS_CPU_DIR "/sys/devices/system/cpu/"
