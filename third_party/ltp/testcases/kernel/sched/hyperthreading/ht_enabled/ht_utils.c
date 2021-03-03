#include "ht_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>
#include <string.h>
#include <linux/unistd.h>
#include "ltp_cpuid.h"
#define PROC_PATH	"/proc"
#define BUFF_SIZE	8192
#define PROCESSOR_STR	"processor"
#define PACKAGE_STR	"cpu_package"
#define HT_FLAG "ht"
#define FLAG_STR "flags"
#define MAX_CPU_NUM 128
#define PROCFS_PATH "/proc/"
#define CPUINFO_PATH "/proc/cpuinfo"
#define CPU_NAME "processor"
#define STAT_NAME "stat"
