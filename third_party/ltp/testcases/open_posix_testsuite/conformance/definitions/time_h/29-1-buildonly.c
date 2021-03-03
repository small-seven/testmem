#include <time.h>
typedef int (*timer_create_test) (clockid_t, struct sigevent *, timer_t *);

int dummyfcn(void)
{
	timer_create_test dummyvar;
	dummyvar = timer_create;
	return 0;
}
