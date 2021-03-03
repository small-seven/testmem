#include <sys/mman.h>
typedef int (*shm_open_test) (const char *, int, mode_t);

int dummyfcn(void)
{
	shm_open_test dummyvar;
	dummyvar = shm_open;
	return 0;
}
