#include <time.h>
typedef size_t(*strftime_test) (char *, size_t, const char *,
				const struct tm *);

int dummyfcn(void)
{
	strftime_test dummyvar;
	dummyvar = strftime;
	return 0;
}
