#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "lapi/abisize.h"
#include "mem.h"
#define DEFAULT_OVER_RATIO	50L
#define EXPECT_PASS		0
#define EXPECT_FAIL		1
#ifdef TST_ABI32
#endif
static int heavy_malloc(long size)
{
	char *p;

	p = malloc(size * KB);
	if (p != NULL) {
		tst_res(TINFO, "malloc %ld kB successfully", size);
		free(p);
		return 0;
	} else {
		tst_res(TINFO, "malloc %ld kB failed", size);
		return 1;
	}
}
