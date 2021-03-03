#include <sys/mman.h>
typedef int (*msync_test) (void *, size_t, int);

int dummyfcn(void)
{
	msync_test dummyvar;
	dummyvar = msync;
	return 0;
}
