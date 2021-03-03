#include <time.h>
typedef int (*timer_settime_test) (timer_t, int, const struct itimerspec *,
				   struct itimerspec *);

int dummyfcn(void)
{
	timer_settime_test dummyvar;
	dummyvar = timer_settime;
	return 0;
}
