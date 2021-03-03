#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "config.h"
#ifdef HAVE_NUMA_V2
# include <numa.h>
# include <numaif.h>
#endif
#define TST_NO_DEFAULT_MAIN
#include "tst_test.h"
#include "tst_numa.h"
void tst_nodemap_free(struct tst_nodemap *nodes)
{
	free(nodes->counters);
	free(nodes);
}
#ifdef HAVE_NUMA_V2
#endif
