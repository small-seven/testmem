#include   <stdio.h>
#include   <stdlib.h>
#include   <sys/times.h>
#include <sys/resource.h>
#include   "sched.h"
#define DEFAULT_PRIORITY_TYPE	"variable"
#define DEFAULT_LOGFILE		"sched_tc5.log"
#define TIMES			20
#define MATRIX_SIZE    		50
#define USAGE "Usage:  %s  [-l log] [-t type] [-p priority] [-v] [-d]\n" \
#ifndef __linux__
#else
#endif
