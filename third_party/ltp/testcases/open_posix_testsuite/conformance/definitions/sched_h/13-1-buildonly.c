#include <sched.h>
#include <sys/types.h>
typedef int (*sched_getparam_test) (pid_t, struct sched_param *);

int dummyfcn(void)
{
	sched_getparam_test dummyvar;
	dummyvar = sched_getparam;
	return 0;
}
