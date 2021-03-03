#include "config.h"
#include <sys/types.h>
#include <sys/mman.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <libgen.h>
#if HAVE_NUMA_H
#include <numa.h>
#endif
#if HAVE_NUMAIF_H
#include <numaif.h>
#endif
#include "test.h"
#include "lapi/syscalls.h"
#include "include_j_h.h"
#include "common_j_h.c"
#include "numa_helper.h"
#ifdef HAVE_NUMA_V2
#define MEM_LENGTH	(4 * 1024 * 1024)
#ifdef __ia64__
#else
#endif
#else
#endif
