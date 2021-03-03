#include <unistd.h>
#include <sys/types.h>
typedef int (*ftruncate_test) (int fildes, off_t length);

int dummyfcn(void)
{
	ftruncate_test dummyvar;
	dummyvar = ftruncate;
	return 0;
}
