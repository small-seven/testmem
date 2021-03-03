#include <sched.h>
#include <time.h>
#include <sys/types.h>
typedef int (*sched_rr_get_interval_test) (pid_t, struct timespec *);

int dummyfcn(void)
{
	sched_rr_get_interval_test dummyvar;
	dummyvar = sched_rr_get_interval;
	return 0;
}
