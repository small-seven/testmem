#include <errno.h>
#include "config.h"
#ifdef HAVE_NUMA_V2
# include <numa.h>
# include <numaif.h>
#endif
#include "tst_test.h"
#include "tst_numa.h"
#ifdef HAVE_NUMA_V2
#include "set_mempolicy.h"
#define ALLOC_ON_NODE 8
#else
#endif /* HAVE_NUMA_V2 */
