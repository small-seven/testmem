#include <time.h>
typedef struct tm *(*getdate_test) (const char *);

int dummyfcn(void)
{
	getdate_test dummyvar;
	dummyvar = getdate;
	return 0;
}
