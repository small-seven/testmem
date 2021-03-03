#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>
#ifdef	__linux__
#include <sys/sysinfo.h>
#endif
#include "../testfrmw/testfrmw.h"
#include "../testfrmw/testfrmw.c"
#define UNRESOLVED_KILLALL(error, text) {		\
#define FAILED_KILLALL(text) {				\
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define TIMEOUT  (180)
#ifndef WITHOUT_ALTCLK
#define USE_ALTCLK		/* make tests with MONOTONIC CLOCK if supported */
#endif
#ifdef WITHOUT_XOPEN
#define PTHREAD_MUTEX_DEFAULT 0
#define PTHREAD_MUTEX_NORMAL 0
#define PTHREAD_MUTEX_ERRORCHECK 0
#define PTHREAD_MUTEX_RECURSIVE 0
#endif
#ifdef USE_ALTCLK
#endif
#define NSCENAR (sizeof(scenarii)/sizeof(scenarii[0]))
#if VERBOSE > 5
#endif
typedef struct _children {
	union {
		pid_t p;
		pthread_t t;
	} data;
#ifdef __linux__
#else
#endif
#if VERBOSE > 0
#endif
#ifndef USE_ALTCLK
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#ifndef WITHOUT_XOPEN
#endif
#ifdef USE_ALTCLK
#else
#endif
#if VERBOSE > 2
#endif
#if VERBOSE > 2
#endif
#if VERBOSE > 2
#endif
#if VERBOSE > 4
#endif
#if VERBOSE > 4
#endif
#if VERBOSE > 4
#endif
#if VERBOSE > 4
#endif
