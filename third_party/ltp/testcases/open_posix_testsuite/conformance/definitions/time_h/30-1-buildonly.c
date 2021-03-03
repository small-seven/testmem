#include <time.h>
typedef int (*timer_delete_test) (timer_t);

int dummyfcn(void)
{
	timer_delete_test dummyvar;
	dummyvar = timer_delete;
	return 0;
}
