#ifndef __UBOOT__
#include <linux/crc32.h>
#include <linux/slab.h>
#include <u-boot/crc.h>
#else
#include <linux/compat.h>
#include <linux/err.h>
#include <linux/stat.h>
#endif
#include "ubifs.h"
static void lnc_free(struct ubifs_zbranch *zbr)
{
	if (!zbr->leaf)
		return;
	kfree(zbr->leaf);
	zbr->leaf = NULL;
}
#ifndef __UBOOT__
#else
#endif
int ubifs_tnc_remove(struct ubifs_info *c, const union ubifs_key *key)
{
	int found, n, err = 0;
	struct ubifs_znode *znode;

	mutex_lock(&c->tnc_mutex);
	dbg_tnck(key, "key ");
	found = lookup_level0_dirty(c, key, &znode, &n);
	if (found < 0) {
		err = found;
		goto out_unlock;
	}
	if (found == 1)
		err = tnc_delete(c, znode, n);
	if (!err)
		err = dbg_check_tnc(c, 0);

out_unlock:
	mutex_unlock(&c->tnc_mutex);
	return err;
}
