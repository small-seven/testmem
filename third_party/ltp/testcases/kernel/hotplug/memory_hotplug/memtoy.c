#include <stdio.h>
#include "config.h"
#include "tst_res_flags.h"
#ifdef HAVE_NUMA_V2
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <libgen.h>
#include <errno.h>
#include <numa.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "memtoy.h"
#define OPTIONS	"Vhvx"
#ifdef _DEBUG
#endif
#if 0
#endif
#ifdef _DEBUG
#endif
#else
#endif
