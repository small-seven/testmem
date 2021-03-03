#include <stdio.h>
#include <errno.h>
#include "config.h"
#ifdef HAVE_NUMA_V2
# include <numa.h>
# include <numaif.h>
#endif
#include "tst_test.h"
#include "tst_numa.h"
#define MNTPOINT "mntpoint"
#define FILES 10
#ifdef HAVE_NUMA_V2
#include "set_mempolicy.h"
#else
#endif /* HAVE_NUMA_V2 */
