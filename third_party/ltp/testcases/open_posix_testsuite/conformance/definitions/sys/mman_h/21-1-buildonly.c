#include <sys/mman.h>
#include <unistd.h>
#if defined(_POSIX_TYPED_MEMORY_OBJECTS) && _POSIX_TYPED_MEMORY_OBJECTS != -1
typedef int (*posix_typed_mem_get_info_test) (int,
					      struct posix_typed_mem_info *);

int dummyfcn(void)
{
	posix_typed_mem_get_info_test dummyvar;
	dummyvar = posix_typed_mem_get_info;
	return 0;
}
#endif
