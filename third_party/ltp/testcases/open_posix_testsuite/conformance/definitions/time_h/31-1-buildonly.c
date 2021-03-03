#include <time.h>
typedef int (*timer_gettime_test) (timer_t, struct itimerspec *);

int dummyfcn(void)
{
	timer_gettime_test dummyvar;
	dummyvar = timer_gettime;
	return 0;
}
