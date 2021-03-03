     Removed restrict keyword from typedef.
   */

#include <signal.h>

typedef int (*sigprocmask_test) (int, const sigset_t *, sigset_t *);

int dummyfcn(void)
{
	sigprocmask_test dummyvar;
	dummyvar = sigprocmask;
	return 0;
}
