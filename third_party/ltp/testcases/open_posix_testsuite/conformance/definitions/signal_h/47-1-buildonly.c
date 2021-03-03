#include <signal.h>
typedef int (*sigtimedwait_test) (const sigset_t * restrict,
				  siginfo_t * restrict,
				  const struct timespec * restrict);

int dummyfcn(void)
{
	sigtimedwait_test dummyvar;
	dummyvar = sigtimedwait;
	return 0;
}
