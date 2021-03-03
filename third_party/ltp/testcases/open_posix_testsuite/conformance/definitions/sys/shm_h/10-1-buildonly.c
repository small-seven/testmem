#include <sys/shm.h>
typedef int (*shmdt_test) (const void *);

int dummyfcn(void)
{
	shmdt_test dummyvar;
	dummyvar = shmdt;
	return 0;
}
