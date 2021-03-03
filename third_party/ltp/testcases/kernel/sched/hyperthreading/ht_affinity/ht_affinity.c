#include "ht_utils.h"
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#define sched_setaffinity(pid, cpusetsize, mask) syscall(__NR_sched_setaffinity, pid, cpusetsize, mask)
#define sched_getaffinity(pid, cpusetsize, mask) syscall(__NR_sched_getaffinity, pid, cpusetsize, mask)
#define AFFINITY_NAME "affinity"
#define PROCFS_PATH "/proc/"
#if (!defined __i386__ && !defined __x86_64__)
#else
#endif
