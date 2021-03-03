#define _GNU_SOURCE
#include <sys/wait.h>
#include <sys/resource.h>
#include <string.h>
#include <errno.h>
#include "syscall.h"
#ifdef SYS_wait4_time64
#endif
