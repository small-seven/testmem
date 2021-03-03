#include <time.h>
typedef struct tm *(*localtime_test) (const time_t *);

int dummyfcn(void)
{
	localtime_test dummyvar;
	dummyvar = localtime;
	return 0;
}
