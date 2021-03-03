#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/mman.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include "config.h"
#include "tst_test.h"
#include "tst_timer.h"
#include "lapi/syscalls.h"
#define DROP_CACHES_FNAME "/proc/sys/vm/drop_caches"
#define MEMINFO_FNAME "/proc/meminfo"
#define PROC_IO_FNAME "/proc/self/io"
