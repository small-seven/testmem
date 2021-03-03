#include <time.h>
typedef clock_t(*clock_test) (void);

int dummyfcn(void)
{
	clock_test dummyvar;
	dummyvar = clock;
	return 0;
}
