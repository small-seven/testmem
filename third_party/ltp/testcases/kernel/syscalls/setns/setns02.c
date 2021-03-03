#define _GNU_SOURCE
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <errno.h>
#include <sched.h>
#include <string.h>
#include "config.h"
#include "test.h"
#include "lapi/syscalls.h"
#include "safe_macros.h"
#define CHILD_STACK_SIZE (1024*1024)
#define CP "(child) "
#if defined(__NR_setns) && defined(CLONE_NEWIPC) && defined(CLONE_NEWUTS)
#include "setns.h"
#else
#endif
