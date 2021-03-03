#include <stdio.h>
#include <sys/param.h>
#include "bytes_by_prefix.h"
#ifdef DEV_BSIZE
#define B_MULT	DEV_BSIZE	/* block size */
#else
#warning DEV_BSIZE is not defined, defaulting to 512
#define B_MULT	512
#endif
#define K_MULT	1024		/* Kilo or 2^10 */
#define M_MULT	1048576		/* Mega or 2^20 */
#define G_MULT	1073741824	/* Giga or 2^30 */
#define T_MULT	1099511627776	/* tera or 2^40 */
