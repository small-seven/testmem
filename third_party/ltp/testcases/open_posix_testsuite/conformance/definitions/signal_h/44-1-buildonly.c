#include <signal.h>
typedef int (*sigrelse_test) (int);

int dummyfcn(void)
{
	sigrelse_test dummyvar;
	dummyvar = sigrelse;
	return 0;
}
