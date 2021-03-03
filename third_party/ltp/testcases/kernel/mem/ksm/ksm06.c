#include "config.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "mem.h"
#include "numa_helper.h"
#ifdef HAVE_NUMA_V2
#include <numaif.h>
#else
#endif
