#include <errno.h>
#include <sched.h>
#include <sys/resource.h>
#include "test.h"
#ifndef RUSAGE_BOTH		/* Removed from user space on RHEL4 */
#define RUSAGE_BOTH (-2)	/* still works on SuSE      */
#endif /* so this is a work around */
#ifndef UCLINUX
#endif
