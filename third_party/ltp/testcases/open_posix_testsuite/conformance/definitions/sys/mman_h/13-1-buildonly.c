#include <sys/mman.h>
typedef void *(*mmap_test) (void *, size_t, int, int, int, off_t);

int dummyfcn(void)
{
	mmap_test dummyvar;
	dummyvar = mmap;
	return 0;
}
