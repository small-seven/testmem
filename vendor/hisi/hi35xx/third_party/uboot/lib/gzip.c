#include <common.h>
#include <watchdog.h>
#include <command.h>
#include <gzip.h>
#include <image.h>
#include <malloc.h>
#include <memalign.h>
#include <u-boot/zlib.h>
#include "zlib/zutil.h"
#ifndef CONFIG_GZIP_COMPRESS_DEF_SZ
#define CONFIG_GZIP_COMPRESS_DEF_SZ	0x200
#endif
#define ZALLOC_ALIGNMENT		16
static void *zalloc(void *x, unsigned items, unsigned size)
{
	void *p;

	size *= items;
	size = (size + ZALLOC_ALIGNMENT - 1) & ~(ZALLOC_ALIGNMENT - 1);

	p = malloc_cache_aligned(size);

	return (p);
}
static void zfree(void *x, void *addr, unsigned nb)
{
	free (addr);
}
#ifndef CONFIG_GZIP
#else
#endif
