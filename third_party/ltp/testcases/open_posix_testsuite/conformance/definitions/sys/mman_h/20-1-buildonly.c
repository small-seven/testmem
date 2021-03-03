#include <sys/mman.h>
#include <unistd.h>
#if defined(_POSIX_TYPED_MEMORY_OBJECTS) && _POSIX_TYPED_MEMORY_OBJECTS != -1
typedef int (*posix_mem_offset_test) (const void *restrict, size_t,
				      off_t * restrict, size_t * restrict,
				      int *restrict);

int dummyfcn(void)
{
	posix_mem_offset_test dummyvar;
	dummyvar = posix_mem_offset;
	return 0;
}
#endif
