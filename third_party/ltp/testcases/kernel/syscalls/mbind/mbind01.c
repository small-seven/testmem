#include <errno.h>
#if HAVE_NUMA_H
#include <numa.h>
#endif
#include "config.h"
#include "numa_helper.h"
#include "tst_test.h"
#ifdef HAVE_NUMA_V2
#define MEM_LENGTH (4 * 1024 * 1024)
#define UNKNOWN_POLICY -1
#define POLICY_DESC(x) .policy = x, .desc = #x
#define POLICY_DESC_TEXT(x, y) .policy = x, .desc = #x" ("y")"
#else
#endif
