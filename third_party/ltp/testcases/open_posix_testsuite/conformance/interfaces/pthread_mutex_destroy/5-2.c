#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../testfrmw/testfrmw.h"
#include "../testfrmw/testfrmw.c"
#ifndef VERBOSE
#define VERBOSE 1
#endif
#ifndef WITHOUT_XOPEN
#define NSCENAR (sizeof(scenarii)/sizeof(scenarii[0]))
#if VERBOSE > 0
#endif
#if VERBOSE > 1
#endif
#if VERBOSE > 0
#endif
#else /* WITHOUT_XOPEN */
#endif
