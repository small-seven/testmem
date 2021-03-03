#include <time.h>
typedef struct tm *(*localtime_r_test) (const time_t *, struct tm *);

int dummyfcn(void)
{
	localtime_r_test dummyvar;
	dummyvar = localtime_r;
	return 0;
}
