#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <err.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#if HAVE_LINUX_MEMPOLICY_H
#include "../cpuset_lib/common.h"
#include "../cpuset_lib/bitmask.h"
#include "../cpuset_lib/cpuset.h"
#define MAX_NPROCS	1000
#define USAGE	("Usage: %s [-p nprocs] [-h]\n"		\
#else /* ! HAVE_LINUX_MEMPOLICY_H */
#endif
