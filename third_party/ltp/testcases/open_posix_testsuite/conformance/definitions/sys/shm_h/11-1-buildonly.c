#include <sys/shm.h>
typedef int (*shmget_test) (key_t, size_t, int);

int dummyfcn(void)
{
	shmget_test dummyvar;
	dummyvar = shmget;
	return 0;
}
