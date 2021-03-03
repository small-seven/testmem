#include <time.h>
typedef int (*nanosleep_test) (const struct timespec *, struct timespec *);

int dummyfcn(void)
{
	nanosleep_test dummyvar;
	dummyvar = nanosleep;
	return 0;
}
