#include <time.h>
typedef char *(*strptime_test) (const char *, const char *, struct tm *);

int dummyfcn(void)
{
	strptime_test dummyvar;
	dummyvar = strptime;
	return 0;
}
