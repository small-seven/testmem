#if defined UCLINUX && !__THROW
#define __THROW
#endif
#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sched.h>
#include "test.h"
#include "safe_macros.h"
#define FLAG_ALL (CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|SIGCHLD)
#define FLAG_NONE SIGCHLD
#define PARENT_VALUE 1
#define CHILD_VALUE 2
#define TRUE 1
#define FALSE 0
#include "clone_platform.h"
