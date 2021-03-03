#include <sys/mman.h>
#include <unistd.h>
#if defined(_POSIX_TYPED_MEMORY_OBJECTS) && _POSIX_TYPED_MEMORY_OBJECTS != -1
typedef int (*posix_typed_mem_open_test) (const char *, int, int);

int dummyfcn(void)
{
	posix_typed_mem_open_test dummyvar;
	dummyvar = posix_typed_mem_open;
	return 0;
}
#endif
