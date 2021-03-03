#include <sched.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "posixtest.h"
#if defined(_POSIX_SPORADIC_SERVER)&&(_POSIX_SPORADIC_SERVER != -1)
#elif _POSIX_SPORADIC_SERVER == -1
#else
#error "_POSIX_SPORADIC_SERVER not defined properly"
#endif
