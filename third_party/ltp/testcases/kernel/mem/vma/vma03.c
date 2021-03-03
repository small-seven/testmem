#define _GNU_SOURCE
#include "config.h"
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#include "tst_kernel.h"
#include "lapi/abisize.h"
#ifdef __NR_mmap2
#define TESTFILE "testfile"
#else /* __NR_mmap2 */
#endif
