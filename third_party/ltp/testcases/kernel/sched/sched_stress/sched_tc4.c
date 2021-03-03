#include   <sys/times.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include   <stdlib.h>
#include   "sched.h"
#define DEFAULT_PRIORITY_TYPE	"variable"
#define DEFAULT_LOGFILE		"sched_tc4.log"
#define BLOCK_SIZE		512
#define TIMES			5000
#define USAGE "Usage:  %s  [-l log] [-t type] [-p priority] [-v] [-d]\n" \
#ifndef __linux__
#else
#endif
#ifndef __linux__
#else
#endif
