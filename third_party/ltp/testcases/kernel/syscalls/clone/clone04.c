#if defined UCLINUX && !__THROW
#define __THROW
#endif
#include <sched.h>
#include <errno.h>
#include <sys/wait.h>
#include "test.h"
#include "clone_platform.h"
