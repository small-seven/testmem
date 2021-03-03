#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include "testfrmw.h"
#include "testfrmw.c"
#ifndef VERBOSE
#define VERBOSE 1
#endif
#define SEM_NAME "/set_getval_stress"
#define INIT_VAL 0
#if VERBOSE > 1
#endif
