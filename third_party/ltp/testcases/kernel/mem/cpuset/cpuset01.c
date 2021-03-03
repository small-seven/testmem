#include "config.h"
#include <stdio.h>
#include <sys/wait.h>
#if HAVE_NUMA_H
#include <numa.h>
#endif
#if HAVE_NUMAIF_H
#include <numaif.h>
#endif
#include "mem.h"
#include "numa_helper.h"
#ifdef HAVE_NUMA_V2
#else
#endif
