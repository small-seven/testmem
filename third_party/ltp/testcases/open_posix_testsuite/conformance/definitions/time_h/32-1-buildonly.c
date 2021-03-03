#include <time.h>
typedef int (*timer_getoverrun_test) (timer_t);

int dummyfcn(void)
{
	timer_getoverrun_test dummyvar;
	dummyvar = timer_getoverrun;
	return 0;
}
