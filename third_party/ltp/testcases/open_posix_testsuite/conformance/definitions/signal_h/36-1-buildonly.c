#include <signal.h>
typedef int (*sigignore_test) (int);

int dummyfcn(void)
{
	sigignore_test dummyvar;
	dummyvar = sigignore;
	return 0;
}
