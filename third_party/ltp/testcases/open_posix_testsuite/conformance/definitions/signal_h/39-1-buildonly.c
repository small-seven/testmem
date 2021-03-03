#include <signal.h>
typedef void (*(*signal_test) (int, void (*)(int))) (int);

int dummyfcn(void)
{
	signal_test dummyvar;
	dummyvar = signal;
	return 0;
}
