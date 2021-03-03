#include <errno.h>
#include <signal.h>
#include <sys/prctl.h>
#include <linux/filter.h>
#include <linux/capability.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include "config.h"
#include "lapi/prctl.h"
#include "lapi/seccomp.h"
#include "lapi/syscalls.h"
#include "tst_test.h"
#include "tst_capability.h"
#define OPTION_INVALID 999
#define unsup_string "prctl() doesn't support this option, skip it"
