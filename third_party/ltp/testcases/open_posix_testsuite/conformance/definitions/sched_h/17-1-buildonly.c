#include <sched.h>
#include <sys/types.h>
typedef int (*sched_setscheduler_test) (pid_t, int, const struct sched_param *);

int dummyfcn(void)
{
	sched_setscheduler_test dummyvar;
	dummyvar = sched_setscheduler;
	return 0;
}
