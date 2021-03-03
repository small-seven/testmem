#include <sys/prctl.h>
#include <stdlib.h>
#include "config.h"
#ifdef HAVE_SYS_CAPABILITY_H
# include <sys/capability.h>
#endif
#include "lapi/syscalls.h"
#include "lapi/prctl.h"
#include "lapi/securebits.h"
#include "tst_test.h"
#define PROC_STATUS "/proc/self/status"
#define ZERO_STRING "0000000000000000"
#define CAP_STRING  "0000000000000400"
#ifdef HAVE_LIBCAP
#else
#endif
