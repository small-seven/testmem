#include <sched.h>
typedef int (*sched_yield_test) (void);

int dummyfcn(void)
{
	sched_yield_test dummyvar;
	dummyvar = sched_yield;
	return 0;
}
