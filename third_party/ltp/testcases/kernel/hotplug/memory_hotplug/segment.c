#include "config.h"
#ifdef HAVE_NUMA_V2
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <numa.h>
#include <numaif.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "memtoy.h"
#include "segment.h"
#define MAX_SEGMENTS 63		/* arbitrary max */
#define SEG_FD_NONE (-1)
#define SHM_ID_NONE (-1)
#define SEG_ERR (0)
#define SEG_OK  (1)
#define SEG_OFFSET(SEGP, ADDR) ((char *)(ADDR) - (char *)(SEGP->seg_start))
int segment_remove(char *name)
{
	glctx_t *gcp = &glctx;
	segment_t *segp;

	segp = segment_get(name);
	if (segp == NULL) {
		fprintf(stderr, "%s:  no such segment:  %s\n",
			gcp->program_name, name);
		return SEG_ERR;
	}

	unmap_segment(segp);

	free_seg_slot(segp);

	return SEG_OK;
}
#define PG_PER_LINE 8
#define PPL_MASK (PG_PER_LINE - 1)
#endif
