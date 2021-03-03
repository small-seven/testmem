#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <err.h>
#include <errno.h>
#include "test.h"
#include "../cpuset_lib/bitmask.h"
#include "../cpuset_lib/cpuset.h"
#include "../cpuset_lib/common.h"
#include "../cpuset_lib/cpuinfo.h"
#ifdef HAVE_LINUX_MEMPOLICY_H
#else
#endif
