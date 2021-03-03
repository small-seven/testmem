#include <time.h>
typedef struct tm *(*gmtime_r_test) (const time_t *, struct tm *);

int dummyfcn(void)
{
	gmtime_r_test dummyvar;
	dummyvar = gmtime_r;
	return 0;
}
