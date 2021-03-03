#include "config.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#if HAVE_NUMA_H
#include <numa.h>
#endif
#include "lapi/abisize.h"
#include "numa_helper.h"
#include "mem.h"
#ifdef HAVE_NUMA_V2
#ifdef TST_ABI32
#endif
#else
#endif
