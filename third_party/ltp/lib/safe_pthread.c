#include <pthread.h>
#include <stdio.h>
#define TST_NO_DEFAULT_MAIN
#include "tst_test.h"
int safe_pthread_create(const char *file, const int lineno,
			pthread_t *thread_id, const pthread_attr_t *attr,
			void *(*thread_fn)(void *), void *arg)
{
	int rval;

	rval = pthread_create(thread_id, attr, thread_fn, arg);

	if (rval) {
		tst_brk_(file, lineno, TBROK,
			 "pthread_create(%p,%p,%p,%p) failed: %s", thread_id,
			 attr, thread_fn, arg, tst_strerrno(rval));
	}

	return rval;
}
