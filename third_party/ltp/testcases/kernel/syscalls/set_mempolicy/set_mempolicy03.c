#include <errno.h>
#include "config.h"
#ifdef HAVE_NUMA_V2
# include <numaif.h>
# include <numa.h>
#endif
#include "tst_test.h"
#include "tst_numa.h"
#define MNTPOINT "mntpoint"
#define PAGES_ALLOCATED 16u
#ifdef HAVE_NUMA_V2
#include "set_mempolicy.h"
#else
#endif /* HAVE_NUMA_V2 */
