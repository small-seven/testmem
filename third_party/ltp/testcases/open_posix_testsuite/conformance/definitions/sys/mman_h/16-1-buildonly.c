#include <sys/mman.h>
typedef int (*munlock_test) (const void *, size_t);

int dummyfcn(void)
{
	munlock_test dummyvar;
	dummyvar = munlock;
	return 0;
}
