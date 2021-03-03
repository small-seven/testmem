#include <time.h>
typedef struct tm *(*gmtime_test) (const time_t *);

int dummyfcn(void)
{
	gmtime_test dummyvar;
	dummyvar = gmtime;
	return 0;
}
