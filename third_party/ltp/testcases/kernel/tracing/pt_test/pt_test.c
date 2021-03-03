#include <sched.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#include "config.h"
#ifdef HAVE_STRUCT_PERF_EVENT_MMAP_PAGE_AUX_HEAD
# include <linux/perf_event.h>
#define PAGESIZE 4096
#define INTEL_PT_MEMSIZE (17*PAGESIZE)
#define BIT(nr)                 (1UL << (nr))
#define INTEL_PT_PATH "/sys/devices/intel_pt"
#define INTEL_PT_PMU_TYPE "/sys/devices/intel_pt/type"
#define INTEL_PT_FORMAT_TSC "/sys/devices/intel_pt/format/tsc"
#define INTEL_PT_FORMAT_NRT "/sys/devices/intel_pt/format/noretcomp"
#else
#endif /* HAVE_STRUCT_PERF_EVENT_MMAP_PAGE_AUX_HEAD */
