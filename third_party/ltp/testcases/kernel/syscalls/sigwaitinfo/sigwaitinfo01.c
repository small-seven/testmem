#include "test.h"
#include <errno.h>
#include <signal.h>
#include "../utils/include_j_h.h"
#include "../utils/common_j_h.c"
#include <limits.h>
#include "lapi/syscalls.h"
#define SUCCEED_OR_DIE(syscall, message, ...)				 \
#define REPORT_SUCCESS_COND(exp_return, exp_errno, condition, condition_errmsg)	\
#define REPORT_SUCCESS(exp_return, exp_errno)					\
typedef int (*swi_func) (const sigset_t * set, siginfo_t * info,
			 struct timespec * timeout);
typedef void (*test_func) (swi_func, int);

#ifdef TEST_SIGWAIT
static int my_sigwait(const sigset_t * set, siginfo_t * info,
		      struct timespec *timeout)
{
	int ret;
	int err = sigwait(set, &ret);

	if (err == 0)
		return ret;
	errno = err;
	return -1;
}
#endif
#ifdef TEST_SIGWAITINFO
#endif
#ifdef TEST_SIGTIMEDWAIT
#endif
#ifdef TEST_RT_SIGTIMEDWAIT
#endif
#ifdef TEST_RT_SIGTIMEDWAIT
#endif
#if defined TEST_SIGWAIT
#endif
#if defined TEST_SIGWAITINFO
#endif
#if defined TEST_SIGTIMEDWAIT
#endif
#if defined TEST_SIGWAITINFO
#elif defined TEST_RT_SIGTIMEDWAIT
#elif defined TEST_SIGTIMEDWAIT
#elif defined TEST_SIGWAIT
#endif
