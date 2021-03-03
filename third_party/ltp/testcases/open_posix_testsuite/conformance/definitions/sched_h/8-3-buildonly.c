#include <sched.h>
#include <unistd.h>
#if (defined(_POSIX_SPORADIC_SERVER) && _POSIX_SPORADIC_SERVER != -1) \
#ifndef SCHED_SPORADIC
#error SCHED_SPORADIC not defined
#endif
#endif
