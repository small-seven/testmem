#include <errno.h>
#include "config.h"
#ifdef HAVE_NUMA_H
# include <numa.h>
# include <numaif.h>
#endif
#include "tst_test.h"
#include "tst_numa.h"
#ifdef HAVE_NUMA_V2
#else
#endif /* HAVE_NUMA_H */
