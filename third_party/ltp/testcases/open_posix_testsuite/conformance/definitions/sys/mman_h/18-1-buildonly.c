#include <sys/mman.h>
typedef int (*munmap_test) (void *, size_t);

int dummyfcn(void)
{
	munmap_test dummyvar;
	dummyvar = munmap;
	return 0;
}
