#include "config.h"
#include <sys/types.h>
#include <sys/mman.h>
#include <errno.h>
#if HAVE_NUMA_H
#include <numa.h>
#endif
#if HAVE_NUMAIF_H
#include <numaif.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "test.h"
#include "safe_macros.h"
#include "numa_helper.h"
#ifdef HAVE_NUMA_V2
#else
#endif
