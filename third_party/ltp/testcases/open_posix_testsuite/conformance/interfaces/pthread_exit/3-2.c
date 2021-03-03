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
#include "../testfrmw/testfrmw.h"
#include "../testfrmw/testfrmw.c"
#ifndef VERBOSE
#define VERBOSE 1
#endif
#include "../testfrmw/threads_scenarii.c"
#define CLEANUP(n) void clnp##n(void * arg)\
#if VERBOSE > 0
#endif
#if VERBOSE > 0
#endif
#if VERBOSE > 0
#endif
