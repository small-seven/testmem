#ifdef __UBOOT__
#include <linux/err.h>
#endif
#include "ubifs.h"
const struct ubifs_lprops *ubifs_fast_find_free(struct ubifs_info *c)
{
	struct ubifs_lprops *lprops;
	struct ubifs_lpt_heap *heap;

	ubifs_assert(mutex_is_locked(&c->lp_mutex));

	heap = &c->lpt_heap[LPROPS_FREE - 1];
	if (heap->cnt == 0)
		return NULL;

	lprops = heap->arr[0];
	ubifs_assert(!(lprops->flags & LPROPS_TAKEN));
	ubifs_assert(!(lprops->flags & LPROPS_INDEX));
	return lprops;
}
