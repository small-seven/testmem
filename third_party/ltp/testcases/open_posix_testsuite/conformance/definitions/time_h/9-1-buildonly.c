#include <time.h>
typedef char *(*asctime_r_test) (const struct tm *, char *);

int dummyfcn(void)
{
	asctime_r_test dummyvar;
	dummyvar = asctime_r;
	return 0;
}
