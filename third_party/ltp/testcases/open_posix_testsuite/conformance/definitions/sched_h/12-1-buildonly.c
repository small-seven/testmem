#include <sched.h>
typedef int (*sched_get_priority_min_test) (int);

int dummyfcn(void)
{
	sched_get_priority_min_test dummyvar;
	dummyvar = sched_get_priority_min;
	return 0;
}
