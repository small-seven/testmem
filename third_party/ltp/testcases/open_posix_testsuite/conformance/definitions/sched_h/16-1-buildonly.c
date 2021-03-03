#include <sched.h>
#include <sys/types.h>
typedef int (*sched_setparam_test) (pid_t, const struct sched_param *);

int dummyfcn(void)
{
	sched_setparam_test dummyvar;
	dummyvar = sched_setparam;
	return 0;
}
