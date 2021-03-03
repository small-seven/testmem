#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef WITHOUT_XOPEN
#ifndef SCALABILITY_FACTOR
#define SCALABILITY_FACTOR 1
#endif
#ifndef VERBOSE
#define VERBOSE 1
#endif
typedef struct _teststruct {
	pthread_cond_t cnd[10 * SCALABILITY_FACTOR];
	pthread_condattr_t ca[4];
	pthread_condattr_t *pca[10 * SCALABILITY_FACTOR];
	struct _teststruct *prev;
} teststruct_t;
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 0
#endif
#else /* WITHOUT_XOPEN */
#endif
