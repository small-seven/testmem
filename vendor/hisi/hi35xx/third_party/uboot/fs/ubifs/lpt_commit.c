#ifndef __UBOOT__
#include <linux/crc16.h>
#include <linux/slab.h>
#include <linux/random.h>
#else
#include <linux/compat.h>
#include <linux/err.h>
#include "crc16.h"
#endif
#include "ubifs.h"
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
void ubifs_lpt_free(struct ubifs_info *c, int wr_only)
{
	struct ubifs_nnode *nnode;
	int i, hght;

	/* Free write-only things first */

	free_obsolete_cnodes(c); /* Leftover from a failed commit */

	vfree(c->ltab_cmt);
	c->ltab_cmt = NULL;
	vfree(c->lpt_buf);
	c->lpt_buf = NULL;
	kfree(c->lsave);
	c->lsave = NULL;

	if (wr_only)
		return;

	/* Now free the rest */

	nnode = first_nnode(c, &hght);
	while (nnode) {
		for (i = 0; i < UBIFS_LPT_FANOUT; i++)
			kfree(nnode->nbranch[i].nnode);
		nnode = next_nnode(c, nnode, &hght);
	}
	for (i = 0; i < LPROPS_HEAP_CNT; i++)
		kfree(c->lpt_heap[i].arr);
	kfree(c->dirty_idx.arr);
	kfree(c->nroot);
	vfree(c->ltab);
	kfree(c->lpt_nod_buf);
}
#ifndef __UBOOT__
#endif
