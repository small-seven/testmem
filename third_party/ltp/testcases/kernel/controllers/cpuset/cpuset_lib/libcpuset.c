#define _GNU_SOURCE	/* need to see pread() and syscall() */
#include <unistd.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fts.h>
#include <limits.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <time.h>
#include <utime.h>
#include <sys/utsname.h>	/* for cpuset_would_crash_kernel() */
#include "bitmask.h"
#include "cpuset.h"
#include "common.h"
#include "test.h"
#include "lapi/syscalls.h"
#include "config.h"
#if HAVE_LINUX_MEMPOLICY_H
#include <linux/mempolicy.h>
#define CPUSET_VERSION 3
#define SMALL_BUFSZ 16
#define DEFCPUBITS (512)
#define DEFNODEBITS (DEFCPUBITS/2)
#define ALTERNATE_SN_DISTMAP 1
#ifdef ALTERNATE_SN_DISTMAP
#endif
#define slash(c) (*(c) == '/')
#define eocomp(c) (slash(c) || !*(c))
#define dot1(c) (*(c) == '.' && eocomp(c+1))
#undef slash
#undef eocomp
#undef dot1
void cpuset_free(struct cpuset *cp)
{
	if (!cp)
		return;
	if (cp->cpus)
		bitmask_free(cp->cpus);
	if (cp->mems)
		bitmask_free(cp->mems);
	free(cp);
}
typedef unsigned char distmap_entry_t;	/* type of distmap[] entries */

static distmap_entry_t *distmap;	/* maps <cpu, mem> to distance */

#define DISTMAP_MAX UCHAR_MAX	/* maximum value in distmap[] */

#define I(i,j) ((i) * nmems + (j))	/* 2-D array index simulation */

/*
 * Parse arch neutral lines from 'distance' files of form:
 *
 *	46 66 10 20
 *
 * The lines contain a space separated list of distances, which is parsed
 * into array dists[] of each nodes distance from the specified node.
 *
 * Result is placed in distmap[ncpus][nmems]:
 *
 *	For each cpu c on node:
 *		For each node position n in list of distances:
 *			distmap[c][n] = dists[n]
 */

static int parse_distmap_line(unsigned int node, char *buf)
{
	char *p, *q;
	int ncpus = cpuset_cpus_nbits();
	int nmems = cpuset_mems_nbits();
	unsigned int c, n;
	distmap_entry_t *dists = NULL;
	struct bitmask *cpus = NULL, *mems = NULL;
	int ret = -1;

	p = buf;
	if ((dists = calloc(nmems, sizeof(*dists))) == NULL)
		goto err;
	for (n = 0; n < (unsigned int)nmems; n++)
		dists[n] = DISTMAP_MAX;

	for (n = 0; n < (unsigned int)nmems && *p; n++, p = q) {
		unsigned int d;

		if ((p = strpbrk(p, "0123456789")) == NULL)
			break;
		d = strtoul(p, &q, 10);
		if (p == q)
			break;
		if (d < DISTMAP_MAX)
			dists[n] = (distmap_entry_t) d;
	}
#ifdef ALTERNATE_SN_DISTMAP
#endif
#ifdef ALTERNATE_SN_DISTMAP
#endif
#define NUMBER_MOVE_TASK_ATTEMPTS 10
#endif /* HAVE_LINUX_MEMPOLICY_H */
