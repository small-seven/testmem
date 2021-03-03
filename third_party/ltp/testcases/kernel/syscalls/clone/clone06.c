#if defined UCLINUX && !__THROW
#define __THROW
#endif
#include <errno.h>
#include <sched.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "test.h"
#include "clone_platform.h"
#define MAX_LINE_LENGTH 256
