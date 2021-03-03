#include <sys/mman.h>
typedef int (*munlockall_test) (void);

int dummyfcn(void)
{
	munlockall_test dummyvar;
	dummyvar = munlockall;
	return 0;
}
