#include <pwd.h>
#include <limits.h>
#include "lapi/abisize.h"
#include "hugetlb.h"
#ifdef TST_ABI64
#define NADDR	0x10000000eef	/* a 64bit non alligned address value */
#else
#define NADDR	0x60000eef	/* a non alligned address value */
#endif
