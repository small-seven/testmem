#include <sys/shm.h>
typedef int (*shmctl_test) (int, int, struct shmid_ds *);

int dummyfcn(void)
{
	shmctl_test dummyvar;
	dummyvar = shmctl;
	return 0;
}
