#include <time.h>
typedef int (*clock_nanosleep_test) (clockid_t, int, const struct timespec *,
				     struct timespec *);

int dummyfcn(void)
{
	clock_nanosleep_test dummyvar;
	dummyvar = clock_nanosleep;
	return 0;
}
