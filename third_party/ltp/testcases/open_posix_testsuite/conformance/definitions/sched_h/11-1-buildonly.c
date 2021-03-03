#include <sched.h>
typedef int (*sched_get_priority_max_test) (int);

int dummyfcn(void)
{
	sched_get_priority_max_test dummyvar;
	dummyvar = sched_get_priority_max;
	return 0;
}
