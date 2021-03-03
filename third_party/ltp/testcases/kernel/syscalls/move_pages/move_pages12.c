#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "tst_test.h"
#include "move_pages_support.h"
#include "lapi/mmap.h"
#ifdef HAVE_NUMA_V2
#define LOOPS	1000
#define PATH_MEMINFO	"/proc/meminfo"
#define PATH_NR_HUGEPAGES	"/proc/sys/vm/nr_hugepages"
#define PATH_HUGEPAGES	"/sys/kernel/mm/hugepages/"
#define TEST_NODES	2
#else
#endif
