#include "config.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "mem.h"
#include "ksm_common.h"
#ifdef HAVE_NUMA_V2
#include <numaif.h>
#else
#endif
