#define _GNU_SOURCE
#include <errno.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/wait.h>
#include "tst_test.h"
#include "kcmp.h"
#include "lapi/sched.h"
#define STACK_SIZE	(1024*1024)
