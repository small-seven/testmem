#include <time.h>
typedef void (*tzset_test) (void);

int dummyfcn(void)
{
	tzset_test dummyvar;
	dummyvar = tzset;
	return 0;
}
