#include <stdio.h>
#include <sys/mount.h>
#include <limits.h>
#include <sys/param.h>
#include "lapi/abisize.h"
#include "hugetlb.h"
#define LOW_ADDR       0x80000000
#define LOW_ADDR2      0x90000000
#ifdef TST_ABI64 /* 64-bit process */
#else /* 32-bit process */
#endif
