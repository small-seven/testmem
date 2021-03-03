#include <time.h>
#include <setjmp.h>
#include <limits.h>
#include "pthread_impl.h"
int timer_create(clockid_t clk, struct sigevent *restrict evp, timer_t *restrict res)
{
	static pthread_once_t once = PTHREAD_ONCE_INIT;
	pthread_t td;
	pthread_attr_t attr;
	int r;
	struct start_args args;
	struct ksigevent ksev, *ksevp=0;
	int timerid;
	sigset_t set;

	switch (evp ? evp->sigev_notify : SIGEV_SIGNAL) {
	case SIGEV_NONE:
	case SIGEV_SIGNAL:
		if (evp) {
			ksev.sigev_value = evp->sigev_value;
			ksev.sigev_signo = evp->sigev_signo;
			ksev.sigev_notify = evp->sigev_notify;
			ksev.sigev_tid = 0;
			ksevp = &ksev;
		}
		if (syscall(SYS_timer_create, clk, ksevp, &timerid) < 0)
			return -1;
		*res = (void *)(intptr_t)timerid;
		break;
	case SIGEV_THREAD:
		pthread_once(&once, install_handler);
		if (evp->sigev_notify_attributes)
			attr = *evp->sigev_notify_attributes;
		else
			pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
		pthread_barrier_init(&args.b, 0, 2);
		args.sev = evp;

		__block_app_sigs(&set);
		__syscall(SYS_rt_sigprocmask, SIG_BLOCK, SIGTIMER_SET, 0, _NSIG/8);
		r = pthread_create(&td, &attr, start, &args);
		__restore_sigs(&set);
		if (r) {
			errno = r;
			return -1;
		}

		ksev.sigev_value.sival_ptr = 0;
		ksev.sigev_signo = SIGTIMER;
		ksev.sigev_notify = 4; /* SIGEV_THREAD_ID */
		ksev.sigev_tid = td->tid;
		if (syscall(SYS_timer_create, clk, &ksev, &timerid) < 0)
			timerid = -1;
		td->timer_id = timerid;
		pthread_barrier_wait(&args.b);
		if (timerid < 0) return -1;
		*res = (void *)(INTPTR_MIN | (uintptr_t)td>>1);
		break;
	default:
		errno = EINVAL;
		return -1;
	}

	return 0;
}
