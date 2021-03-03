#include <common.h>
#include <memalign.h>
#include <linux/compat.h>
void *kmalloc(size_t size, int flags)
{
	void *p;

	p = malloc_cache_aligned(size);
	if (p && flags & __GFP_ZERO)
		memset(p, 0, size);

	return p;
}
