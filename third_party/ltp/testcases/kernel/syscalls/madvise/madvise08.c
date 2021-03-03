#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "tst_test.h"
#include "lapi/mmap.h"
#define CORE_PATTERN "/proc/sys/kernel/core_pattern"
#define CORE_FILTER "/proc/self/coredump_filter"
#define YCOUNT 0x500L
#define FMEMSIZE (YCOUNT + 0x2L)
#define CORENAME_MAX_SIZE 512
