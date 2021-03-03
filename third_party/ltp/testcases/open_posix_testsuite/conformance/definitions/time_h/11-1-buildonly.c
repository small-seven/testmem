#include <time.h>
typedef int (*clock_getcpuclockid_test) (pid_t, clockid_t *);

int dummyfcn(void)
{
	clock_getcpuclockid_test dummyvar;
	dummyvar = clock_getcpuclockid;
	return 0;
}
