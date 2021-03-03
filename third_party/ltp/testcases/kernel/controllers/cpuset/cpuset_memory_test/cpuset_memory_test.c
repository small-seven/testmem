#include "config.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <err.h>
#include <limits.h>
#include <getopt.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/syscall.h>
#include <pthread.h>
#if HAVE_LINUX_MEMPOLICY_H
#include "../cpuset_lib/cpuset.h"
#define FILE_HUGEPAGE	"/hugetlb/hugepagefile"
#define MMAP_ANON	(SCHAR_MAX + 1)
#define MMAP_FILE	(SCHAR_MAX + 2)
#define MMAP_LOCK1	(SCHAR_MAX + 3)
#define MMAP_LOCK2	(SCHAR_MAX + 4)
#define SHM		(SCHAR_MAX + 5)
#define HUGEPAGE	(SCHAR_MAX + 6)
#define CHECK		(SCHAR_MAX + 7)
#define THREAD		(SCHAR_MAX + 8)
#else
#endif
