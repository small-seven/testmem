#include <sys/shm.h>
typedef key_t(*ftok_test) (const char *, int);

int dummyfcn(void)
{
	ftok_test dummyvar;
	dummyvar = ftok;
	return 0;
}
