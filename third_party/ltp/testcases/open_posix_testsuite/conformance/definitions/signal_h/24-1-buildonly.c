#include <signal.h>
#include <sys/types.h>
typedef int (*kill_test) (pid_t, int);

int dummyfcn(void)
{
	kill_test dummyvar;
	dummyvar = kill;
	return 0;
}
