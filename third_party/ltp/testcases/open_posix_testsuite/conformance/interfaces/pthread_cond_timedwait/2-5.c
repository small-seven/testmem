#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../testfrmw/testfrmw.h"
#include "../testfrmw/testfrmw.c"
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define NTHREADS (100)
#ifndef WITHOUT_ALTCLK
#define USE_ALTCLK		/* make tests with MONOTONIC CLOCK if supported */
#endif
#ifndef WITHOUT_XOPEN
#ifdef USE_ALTCLK
#endif
#ifndef USE_ALTCLK
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 1
#endif
#ifdef USE_ALTCLK
#endif
#ifdef USE_ALTCLK
#else
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 1
#endif
#else /* WITHOUT_XOPEN */
#endif
