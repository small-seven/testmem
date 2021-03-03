#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <semaphore.h>
#include "../testfrmw/testfrmw.h"
#include "../testfrmw/testfrmw.c"
#ifndef VERBOSE
#define VERBOSE 1
#endif
#ifndef WITHOUT_ALTCLK
#define USE_ALTCLK		/* make tests with MONOTONIC CLOCK if supported */
#endif
#ifdef USE_ALTCLK
#endif
#ifndef WITHOUT_XOPEN
#ifdef USE_ALTCLK
#endif
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
