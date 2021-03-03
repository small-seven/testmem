#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "test.h"
#define ITER    3
#define FAILED 0
#define PASSED 1
#ifdef BCS
#else
#endif
#ifdef WCOREDUMP
#endif
