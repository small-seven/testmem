#if defined UCLINUX && !__THROW
#define __THROW
#endif
#include <errno.h>
#include <sched.h>
#include <sys/wait.h>
#include "test.h"
#include "clone_platform.h"
