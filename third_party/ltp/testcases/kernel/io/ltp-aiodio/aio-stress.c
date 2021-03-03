#define _FILE_OFFSET_BITS 64
#define PROG_VERSION "0.21"
#define NEW_GETEVENTS
#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <string.h>
#include <pthread.h>
#include "config.h"
#include "tst_res_flags.h"
#ifdef HAVE_LIBAIO
#include <libaio.h>
#define IO_FREE 0
#define IO_PENDING 1
#define RUN_FOREVER -1
#define USE_MALLOC 0
#define USE_SHM 1
#define USE_SHMFS 2
#define DEVIATIONS 6
#ifdef NEW_GETEVENTS
#else
#endif
#ifdef NEW_GETEVENTS
#else
#endif
typedef void *(*start_routine) (void *);
int run_workers(struct thread_info *t, int num_threads)
{
	int ret;
	int i;

	for (i = 0; i < num_threads; i++) {
		ret =
		    pthread_create(&t[i].tid, NULL, (start_routine) worker,
				   t + i);
		if (ret) {
			perror("pthread_create");
			exit(1);
		}
#else
#endif
