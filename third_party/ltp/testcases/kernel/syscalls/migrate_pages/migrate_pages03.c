#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#include "lapi/mmap.h"
#include "ksm_helper.h"
#include "numa_helper.h"
#include "migrate_pages_common.h"
#ifdef HAVE_NUMA_V2
#define N_PAGES 20
#define N_LOOPS 600
#define TEST_NODES 2
#else
#endif
