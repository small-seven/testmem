#include <signal.h>
typedef int (*sigwaitinfo_test) (const sigset_t * restrict,
				 siginfo_t * restrict);

int dummyfcn(void)
{
	sigwaitinfo_test dummyvar;
	dummyvar = sigwaitinfo;
	return 0;
}
