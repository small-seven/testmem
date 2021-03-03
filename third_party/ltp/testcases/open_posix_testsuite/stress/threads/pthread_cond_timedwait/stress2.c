#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef SCALABILITY_FACTOR
#define SCALABILITY_FACTOR 1
#endif
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define NCHILDREN (20)
#define TIMEOUT  (60)
#ifndef WITHOUT_ALTCLK
#define USE_ALTCLK		/* make tests with MONOTONIC CLOCK if supported */
#endif
#ifdef USE_ALTCLK
#endif
#define NSCENAR (sizeof(scenarii)/sizeof(scenarii[0]))
#if VERBOSE > 2
#endif
#if VERBOSE > 0
#endif
#ifndef USE_ALTCLK
#endif
#if VERBOSE > 1
#ifdef WITHOUT_XOPEN
#endif
#endif
#ifndef WITHOUT_XOPEN
#if VERBOSE > 1
#endif
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#ifdef USE_ALTCLK
#if VERBOSE > 1
#endif
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
#if VERBOSE > 1
#endif
