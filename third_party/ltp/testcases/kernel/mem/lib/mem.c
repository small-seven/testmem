#define TST_NO_DEFAULT_MAIN
#include "config.h"
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <errno.h>
#include <fcntl.h>
#if HAVE_NUMA_H
#include <numa.h>
#endif
#if HAVE_NUMAIF_H
#include <numaif.h>
#endif
#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "mem.h"
#include "numa_helper.h"
#ifdef HAVE_DECL_MADV_MERGEABLE
#endif
#ifdef HAVE_NUMA_V2
#else
#endif
static void ksm_child_memset(int child_num, int size, int total_unit,
		 struct ksm_merge_data ksm_merge_data, char **memory)
{
	int i = 0, j;
	int unit = size / total_unit;

	tst_res(TINFO, "child %d continues...", child_num);

	if (ksm_merge_data.mergeable_size == size * MB) {
		tst_res(TINFO, "child %d allocates %d MB filled with '%c'",
			child_num, size, ksm_merge_data.data);

	} else {
		tst_res(TINFO, "child %d allocates %d MB filled with '%c'"
				" except one page with 'e'",
				child_num, size, ksm_merge_data.data);
	}

	for (j = 0; j < total_unit; j++) {
		for (i = 0; (unsigned int)i < unit * MB; i++)
			memory[j][i] = ksm_merge_data.data;
	}

	/* if it contains unshared page, then set 'e' char
	 * at the end of the last page
	 */
	if (ksm_merge_data.mergeable_size < size * MB)
		memory[j-1][i-1] = 'e';
}
#ifdef HAVE_DECL_MADV_MERGEABLE
#endif
#ifdef HAVE_NUMA_V2
#endif
#ifdef HAVE_DECL_MADV_MERGEABLE
#endif
#ifdef HAVE_NUMA_V2
#endif
