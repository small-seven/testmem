#include <signal.h>
typedef int (*sigpending_test) (sigset_t *);

int dummyfcn(void)
{
	sigpending_test dummyvar;
	dummyvar = sigpending;
	return 0;
}
