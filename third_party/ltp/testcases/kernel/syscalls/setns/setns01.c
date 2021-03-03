#define _GNU_SOURCE
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <errno.h>
#include <sched.h>
#include <pwd.h>
#include <string.h>
#include "config.h"
#include "test.h"
#include "lapi/syscalls.h"
#include "safe_macros.h"
#if defined(__NR_setns)
#include "setns.h"
#else
#endif
