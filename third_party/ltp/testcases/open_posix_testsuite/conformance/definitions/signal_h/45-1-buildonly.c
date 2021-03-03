#include <signal.h>
typedef void (*(*sigset_test) (int, void (*)(int))) (int);

int dummyfcn(void)
{
	sigset_test dummyvar;
	dummyvar = sigset;
	return 0;
}
