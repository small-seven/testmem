#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <semaphore.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef SCALABILITY_FACTOR
#define SCALABILITY_FACTOR 1
#endif
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define FACTOR 5
#ifndef WITHOUT_XOPEN
#include "threads_scenarii.c"
#if VERBOSE > 1
#endif
#if VERBOSE > 5
#endif
#else /* WITHOUT_XOPEN */
#endif
