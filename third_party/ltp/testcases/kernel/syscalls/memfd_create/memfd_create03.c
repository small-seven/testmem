#define _GNU_SOURCE
#include "tst_test.h"
#include "memfd_create_common.h"
#include <stdio.h>
#include <errno.h>
#define TOTAL_HP_PATH "/proc/sys/vm/nr_hugepages"
#define MEMINFO_PATH "/proc/meminfo"
#define FREE_HP "HugePages_Free:\t%ld"
#define DEFAULT_HPS "Hugepagesize:\t%ld kB"
