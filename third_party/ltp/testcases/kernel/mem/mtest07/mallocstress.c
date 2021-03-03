#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <sys/types.h>
#include "tst_test.h"
#include "tst_safe_pthread.h"
#define NUM_LOOPS	100
#define NUM_THREADS     60
#define SPEW_SIGNALS
#ifdef SPEW_SIGNALS
#else
#endif
int allocate_free(int scheme)
{
	int loop;
	const int MAXPTRS = 50;	/* only 42 or so get used on 32 bit machine */

	for (loop = 0; loop < NUM_LOOPS; loop++) {
		size_t oldsize = 5;
		size_t size = sizeof(long);
		long *ptrs[MAXPTRS];
		int num_alloc;
		int i;

		/* loop terminates in one of three ways:
		 * 1. after MAXPTRS iterations
		 * 2. if malloc fails
		 * 3. if new size overflows
		 */
		for (num_alloc = 0; num_alloc < MAXPTRS; num_alloc++) {
			size_t newsize = 0;

			/* Malloc the next block */
			ptrs[num_alloc] = malloc(size);
			/* terminate loop if malloc fails */
			if (!ptrs[num_alloc])
				break;
			ptrs[num_alloc][0] = num_alloc;

			/* Increase size according to one of four schedules. */
			switch (scheme) {
			case 0:
				newsize = size + oldsize;
				oldsize = size;
				break;
			case 1:
				newsize = size * 2;
				break;
			case 2:
				newsize = size * 3;
				break;
			case 3:
				newsize = size * 5;
				break;
			default:
				assert(0);
			}
			/* terminate loop on overflow */
			if (newsize < size)
				break;
			size = newsize;

			my_yield();
		}

		for (i = 0; i < num_alloc; i++) {
			if (ptrs[i][0] != i) {
				tst_res(TFAIL,
					"pid[%d]: fail: bad sentinel value\n",
					getpid());
				return 1;
			}
			free(ptrs[i]);
			my_yield();
		}

		my_yield();
	}

	/* Success! */
	return 0;
}
static void stress_malloc(void)
{
	int thread_index;

	for (thread_index = 0; thread_index < NUM_THREADS; thread_index++) {
		SAFE_PTHREAD_CREATE(&thread_id[thread_index], NULL, alloc_mem,
				    (void *)(uintptr_t)thread_index);
	}

	/* Wake up all threads */
	TST_CHECKPOINT_WAKE2(0, NUM_THREADS);

	/* wait for all threads to finish */
	for (thread_index = 0; thread_index < NUM_THREADS; thread_index++) {
		void *status;

		SAFE_PTHREAD_JOIN(thread_id[thread_index], &status);
		if ((intptr_t)status != 0) {
			tst_res(TFAIL, "thread [%d] - exited with errors\n",
				thread_index);
		}
	}

	tst_res(TPASS, "malloc stress test finished successfully");
}
