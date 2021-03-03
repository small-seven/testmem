#include <signal.h>
typedef int (*sigsuspend_test) (const sigset_t *);

int dummyfcn(void)
{
	sigsuspend_test dummyvar;
	dummyvar = sigsuspend;
	return 0;
}
