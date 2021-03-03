#include <time.h>
typedef char *(*ctime_test) (const time_t *);

int dummyfcn(void)
{
	ctime_test dummyvar;
	dummyvar = ctime;
	return 0;
}
