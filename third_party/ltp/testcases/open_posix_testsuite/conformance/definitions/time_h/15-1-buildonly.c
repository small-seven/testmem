#include <time.h>
typedef int (*clock_settime_test) (clockid_t, const struct timespec *);

int dummyfcn(void)
{
	clock_settime_test dummyvar;
	dummyvar = clock_settime;
	return 0;
}
