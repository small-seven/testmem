#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sched.h>
#include <semaphore.h>
#include <errno.h>
#include <assert.h>
#include <sys/wait.h>
#include "../testfrmw/testfrmw.h"
#include "../testfrmw/testfrmw.c"
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define STD_MAIN		/* This allows main() to be defined in the included file */
#include "../testfrmw/threads_scenarii.c"
#if VERBOSE > 4
#endif
#ifdef WITHOUT_XOPEN
#else
#if VERBOSE > 2
#endif
#endif // WITHOUT_XOPEN
#if VERBOSE > 4
#endif
