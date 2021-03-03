#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <err.h>
#include <errno.h>
#include "bitmask.h"
#include "cpuset.h"
#include "common.h"
#include "cpuinfo.h"
#if HAVE_LINUX_MEMPOLICY_H
#define CPUINFO_FILE		"/proc/cpuinfo"
#define SCHEDSTAT_FILE		"/proc/schedstat"
#define CGROUPINFO_FILE		"/proc/cgroups"
#define SYS_CPU_DIR		"/sys/devices/system/cpu"
#define LIST_PRESENT_CPU_FILE	"/sys/devices/system/cpu/present"
#define LIST_ONLINE_CPU_FILE	"/sys/devices/system/cpu/online"
#endif
