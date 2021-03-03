#include <stdio.h>
#include <sched.h>
#include <errno.h>
#include <unistd.h>
#include "posixtest.h"
#if defined(_POSIX_SPORADIC_SERVER)&&(_POSIX_SPORADIC_SERVER != -1)||defined(_POSIX_THREAD_SPORADIC_SERVER)&&(_POSIX_THREAD_SPORADIC_SERVER != -1)
#else
#endif
