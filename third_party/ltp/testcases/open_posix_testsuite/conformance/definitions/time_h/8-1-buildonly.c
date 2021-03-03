#include <time.h>
typedef char *(*asctime_test) (const struct tm *);

int dummyfcn(void)
{
	asctime_test dummyvar;
	dummyvar = asctime;
	return 0;
}
