#include <sys/mman.h>
typedef int (*mlockall_test) (int);

int dummyfcn(void)
{
	mlockall_test dummyvar;
	dummyvar = mlockall;
	return 0;
}
