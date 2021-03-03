#include <sys/mman.h>
typedef int (*mprotect_test) (void *, size_t, int);

int dummyfcn(void)
{
	mprotect_test dummyvar;
	dummyvar = mprotect;
	return 0;
}
