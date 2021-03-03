#include   <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include   "sched.h"
#define DEFAULT_PRIORITY_TYPE	"variable"
#define DEFAULT_EXECUTION_TIME	1800
#define MATRIX_SIZE		100
#define USAGE "Usage:  %s  [-p priority] [-t sec] [-v] [-d]      \n" \
#ifndef __linux__
#else
#endif
