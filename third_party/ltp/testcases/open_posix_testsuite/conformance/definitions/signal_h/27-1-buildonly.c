#include <signal.h>
typedef int (*pthread_sigmask_test) (int, const sigset_t *, sigset_t *);

int dummyfcn(void)
{
	pthread_sigmask_test dummyvar;
	dummyvar = pthread_sigmask;
	return 0;
}
