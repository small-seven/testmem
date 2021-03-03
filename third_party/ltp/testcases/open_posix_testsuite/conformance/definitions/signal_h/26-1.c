#include <pthread.h>
#include <signal.h>
typedef int (*pthread_kill_test) (pthread_t, int);

int main(void)
{
	pthread_kill_test dummyvar;
	dummyvar = pthread_kill;
	return 0;
}
