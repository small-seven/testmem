#include <time.h>
typedef time_t(*time_test) (time_t *);

int dummyfcn(void)
{
	time_test dummyvar;
	dummyvar = time;
	return 0;
}
