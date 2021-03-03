#include <fcntl.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <sys/resource.h>
#include "sched.h"
#define DEFAULT_PRIORITY_TYPE	"variable"
#define DEFAULT_LOGFILE		"sched_tc6.log"
#define BLOCK_SIZE		512
#define TIMES			10
#define MAX_TRIES		20
#define NAPTIME			1
#define REAL_TIME		"1"
#define NO_FORK			"0"
#define USAGE "Usage:  %s  [-l log] [-t type] [-p priority] [-f] [-v] [-d]\n" \
#ifdef __linux__
#else
#endif
#ifndef __linux__
#else
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#else
#endif
#ifndef __linux__
#else
#endif
#ifndef __linux__
#endif
