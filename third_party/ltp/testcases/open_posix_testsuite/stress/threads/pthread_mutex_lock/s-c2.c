#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef SCALABILITY_FACTOR
#define SCALABILITY_FACTOR 1	/* This is not used in this testcase */
#endif
#ifndef VERBOSE
#define VERBOSE 2
#endif
#ifndef WITHOUT_XOPEN
#endif
#ifdef WITHOUT_XOPEN
#else
#endif
typedef struct _td {
	pthread_t child;
	int id;
	pthread_mutex_t mtx;
	int error;
	struct _td *next;	/* It is a chained list */
} testdata_t;
#if VERBOSE > 1
#endif
#ifdef WITHOUT_XOPEN
#if VERBOSE > 1
#endif
#else
#if VERBOSE > 1
#endif
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 0
#endif
