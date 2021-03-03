#include <sys/mman.h>
typedef int (*shm_unlink_test) (const char *);

int dummyfcn(void)
{
	shm_unlink_test dummyvar;
	dummyvar = shm_unlink;
	return 0;
}
