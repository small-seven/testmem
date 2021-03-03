#include <sys/mman.h>
typedef int (*mlock_test) (const void *, size_t);

int dummyfcn(void)
{
	mlock_test dummyvar;
	dummyvar = mlock;
	return 0;
}
