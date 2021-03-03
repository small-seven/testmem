#include "affinity.h"
#include <sched.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "posixtest.h"
#include "ncpu.h"
#define NB_LOOP         20000000
#define NB_LOOP_CHILD  200000000	/* shall be much greater than NB_LOOP */
#define ACCEPTABLE_RATIO 2.0
#define STDIN 0
#define STDOUT 1
#define STDERR 2
