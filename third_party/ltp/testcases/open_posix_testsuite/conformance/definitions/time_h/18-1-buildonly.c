#include <time.h>
typedef double (*difftime_test) (time_t, time_t);

int dummyfcn(void)
{
	difftime_test dummyvar;
	dummyvar = difftime;
	return 0;
}
