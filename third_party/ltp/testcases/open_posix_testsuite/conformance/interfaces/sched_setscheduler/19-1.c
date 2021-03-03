#include <errno.h>
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include "posixtest.h"
#if defined(_POSIX_SPORADIC_SERVER)&&(_POSIX_SPORADIC_SERVER != -1) || defined(_POSIX_THREAD_SPORADIC_SERVER)&&(_POSIX_THREAD_SPORADIC_SERVER != -1)
#endif
