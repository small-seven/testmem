#include <time.h>
typedef int (*clock_gettime_test) (clockid_t, struct timespec *);

int dummyfcn(void)
{
	clock_gettime_test dummyvar;
	dummyvar = clock_gettime;
	return 0;
}
