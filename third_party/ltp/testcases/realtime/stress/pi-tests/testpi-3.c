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

#define THREAD_STOP		1

pthread_mutex_t glob_mutex;

/*typedef struct thread {
	int priority;
	int policy;
	entrypoint_t func;
	pthread_attr_t attr;
	pthread_t handle;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	int flags;
	int count;
} Thread;*/
typedef struct thread Thread;

Thread arg1, arg2, arg3, arg4, arg5;

int strartThread(Thread * thr);
void stopThread(Thread * thr);
void joinThread(Thread * thr);

void *func_nonrt(void *arg)
{
	Thread *pthr = (Thread *) arg;
	int rc, i, j, policy, tid = gettid();
	struct sched_param schedp;
	cpu_set_t mask;
	CPU_ZERO(&mask);
	CPU_SET(0, &mask);

	rc = sched_setaffinity(0, sizeof(mask), &mask);
	if (rc < 0) {
		printf("Thread %d: Can't set affinity: %d %s\n", tid, rc,
		       strerror(rc));
		exit(-1);
	}
#if HAS_PRIORITY_INHERIT
#endif
