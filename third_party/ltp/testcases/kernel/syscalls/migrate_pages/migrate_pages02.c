#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/prctl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#include "numa_helper.h"
#include "migrate_pages_common.h"
#define NODE_MIN_FREEMEM (32*1024*1024)
#ifdef HAVE_NUMA_V2
#else
#endif
