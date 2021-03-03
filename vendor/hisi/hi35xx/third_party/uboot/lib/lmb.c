#include <common.h>
#include <lmb.h>
#define LMB_ALLOC_ANYWHERE	0
#ifdef DEBUG
#endif /* DEBUG */
#ifdef CONFIG_NR_DRAM_BANKS
#endif
#ifdef CONFIG_NR_DRAM_BANKS
#else
#endif
long lmb_free(struct lmb *lmb, phys_addr_t base, phys_size_t size)
{
	struct lmb_region *rgn = &(lmb->reserved);
	phys_addr_t rgnbegin, rgnend;
	phys_addr_t end = base + size - 1;
	int i;

	rgnbegin = rgnend = 0; /* supress gcc warnings */

	/* Find the region where (base, size) belongs to */
	for (i = 0; i < rgn->cnt; i++) {
		rgnbegin = rgn->region[i].base;
		rgnend = rgnbegin + rgn->region[i].size - 1;

		if ((rgnbegin <= base) && (end <= rgnend))
			break;
	}

	/* Didn't find the region */
	if (i == rgn->cnt)
		return -1;

	/* Check to see if we are removing entire region */
	if ((rgnbegin == base) && (rgnend == end)) {
		lmb_remove_region(rgn, i);
		return 0;
	}

	/* Check to see if region is matching at the front */
	if (rgnbegin == base) {
		rgn->region[i].base = end + 1;
		rgn->region[i].size -= size;
		return 0;
	}

	/* Check to see if the region is matching at the end */
	if (rgnend == end) {
		rgn->region[i].size -= size;
		return 0;
	}

	/*
	 * We need to split the entry -  adjust the current one to the
	 * beginging of the hole and add the region after hole.
	 */
	rgn->region[i].size = base - rgn->region[i].base;
	return lmb_add_region(rgn, end + 1, rgnend - end);
}
