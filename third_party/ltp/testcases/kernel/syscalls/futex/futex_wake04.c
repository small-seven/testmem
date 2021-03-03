#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <pthread.h>
#include <errno.h>
#include <sys/time.h>
#include <string.h>
#include "test.h"
#include "safe_macros.h"
#include "futextest.h"
#include "futex_utils.h"
#include "lapi/mmap.h"
#define PATH_MEMINFO "/proc/meminfo"
#define PATH_NR_HUGEPAGES "/proc/sys/vm/nr_hugepages"
#define PATH_HUGEPAGES	"/sys/kernel/mm/hugepages/"
