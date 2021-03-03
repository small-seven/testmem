#include <unistd.h>
typedef int (*fsync_test) (int fildes);

int dummyfcn(void)
{
	fsync_test dummyvar;
	dummyvar = fsync;
	return 0;
}
