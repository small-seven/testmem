#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <librttest.h>
typedef void *(*entrypoint_t) (void *);
pthread_mutex_t glob_mutex;
static pthread_mutex_t cond_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

void *func_lowrt(void *arg)
{
	struct thread *pthr = (struct thread *)arg;
	int i, tid = gettid();

	printf("Thread %d started running with priority %d\n", tid,
	       pthr->priority);
	pthread_mutex_lock(&glob_mutex);
	printf("Thread %d at start pthread pol %d pri %d - Got global lock\n",
	       tid, pthr->policy, pthr->priority);
	/* Wait for other RT threads to start up */
	pthread_barrier_wait(&barrier);

	/* Wait for the high priority noise thread to start and signal us */
	pthread_mutex_lock(&cond_mutex);
	pthread_cond_wait(&cond_var, &cond_mutex);
	pthread_mutex_unlock(&cond_mutex);

	for (i = 0; i < 10000; i++) {
		if (i % 100 == 0) {
			printf("Thread %d loop %d pthread pol %d pri %d\n",
			       tid, i, pthr->policy, pthr->priority);
			fflush(NULL);
		}
