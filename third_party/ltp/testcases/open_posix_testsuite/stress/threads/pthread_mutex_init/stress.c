#include <pthread.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef SCALABILITY_FACTOR
#define SCALABILITY_FACTOR 1
#endif
#ifndef VERBOSE
#define VERBOSE 2
#endif
#define N 20
#ifndef WITHOUT_XOPEN
#endif
#ifndef WITHOUT_XOPEN
#else
#endif
#if VERBOSE > 0
#endif
