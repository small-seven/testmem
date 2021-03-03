#include <sys/shm.h>
typedef void *(*shmat_test) (int, const void *, int);

int dummyfcn(void)
{
	shmat_test dummyvar;
	dummyvar = shmat;
	return 0;
}
