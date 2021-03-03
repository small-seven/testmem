#include <sys/mman.h>
typedef int (*posix_madvise_test) (void *, size_t, int);

int dummyfcn(void)
{
	posix_madvise_test dummyvar;
	dummyvar = posix_madvise;
	return 0;
}
