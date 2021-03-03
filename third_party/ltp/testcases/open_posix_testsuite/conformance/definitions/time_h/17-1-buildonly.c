#include <time.h>
typedef char *(*ctime_r_test) (const time_t *, char *);

int dummyfcn(void)
{
	ctime_r_test dummyvar;
	dummyvar = ctime_r;
	return 0;
}
