#include <time.h>
typedef time_t(*mktime_test) (struct tm *);

int dummyfcn(void)
{
	mktime_test dummyvar;
	dummyvar = mktime;
	return 0;
}
