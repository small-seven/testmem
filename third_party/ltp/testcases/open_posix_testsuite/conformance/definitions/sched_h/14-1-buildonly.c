#include <sched.h>
#include <sys/types.h>
typedef int (*sched_getscheduler_test) (pid_t);

int dummyfcn(void)
{
	sched_getscheduler_test dummyvar;
	dummyvar = sched_getscheduler;
	return 0;
}
