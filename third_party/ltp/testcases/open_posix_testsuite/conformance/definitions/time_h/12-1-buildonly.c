#include <time.h>
typedef int (*clock_getres_test) (clockid_t, struct timespec *);

int dummyfcn(void)
{
	clock_getres_test dummyvar;
	dummyvar = clock_getres;
	return 0;
}
