#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/compiler.h>
#include <linux/sched.h>
#include <linux/pagemap.h>
#include "mtd_dev.h"
#include "nodelist.h"
#include "los_crc32.h"
static inline void jffs2_remove_node_refs_from_ino_list(struct jffs2_sb_info *c,
			struct jffs2_raw_node_ref *ref, struct jffs2_eraseblock *jeb)
{
	struct jffs2_inode_cache *ic = NULL;
	struct jffs2_raw_node_ref **prev;

	prev = &ref->next_in_ino;

	/* Walk the inode's list once, removing any nodes from this eraseblock */
	while (1) {
		if (!(*prev)->next_in_ino) {
			/* We're looking at the jffs2_inode_cache, which is
			   at the end of the linked list. Stash it and continue
			   from the beginning of the list */
			ic = (struct jffs2_inode_cache *)(*prev);
			prev = &ic->nodes;
			continue;
		}

		if (SECTOR_ADDR((*prev)->flash_offset) == jeb->offset) {
			/* It's in the block we're erasing */
			struct jffs2_raw_node_ref *this;

			this = *prev;
			*prev = this->next_in_ino;
			this->next_in_ino = NULL;

			if (this == ref)
				break;

			continue;
		}
		/* Not to be deleted. Skip */
		prev = &((*prev)->next_in_ino);
	}

	/* PARANOIA */
	if (!ic) {
		JFFS2_WARNING("inode_cache/xattr_datum/xattr_ref"
			      " not found in remove_node_refs()!!\n");
		return;
	}

	jffs2_dbg(1, "Removed nodes in range 0x%08x-0x%08x from ino #%u\n",
		  jeb->offset, jeb->offset + c->sector_size, ic->ino);

	D2({
		int i=0;
		struct jffs2_raw_node_ref *this;
		printk(KERN_DEBUG "After remove_node_refs_from_ino_list: \n");

		this = ic->nodes;

		printk(KERN_DEBUG);
		while(this) {
			pr_cont("0x%08x(%d)->",
			       ref_offset(this), ref_flags(this));
			if (++i == 5) {
				printk(KERN_DEBUG);
				i=0;
			}
			this = this->next_in_ino;
		}
		pr_cont("\n");
	});

	switch (ic->class) {
#ifdef CONFIG_JFFS2_FS_XATTR
		case RAWNODE_CLASS_XATTR_DATUM:
			jffs2_release_xattr_datum(c, (struct jffs2_xattr_datum *)ic);
			break;
		case RAWNODE_CLASS_XATTR_REF:
			jffs2_release_xattr_ref(c, (struct jffs2_xattr_ref *)ic);
			break;
#endif
		default:
			if (ic->nodes == (void *)ic && ic->pino_nlink == 0)
				jffs2_del_ino_cache(c, ic);
	}
}
void jffs2_free_jeb_node_refs(struct jffs2_sb_info *c, struct jffs2_eraseblock *jeb)
{
	struct jffs2_raw_node_ref *block, *ref;
	jffs2_dbg(1, "Freeing all node refs for eraseblock offset 0x%08x\n",
		  jeb->offset);

	block = ref = jeb->first_node;

	while (ref) {
		if (ref->flash_offset == REF_LINK_NODE) {
			ref = ref->next_in_ino;
			jffs2_free_refblock(block);
			block = ref;
			continue;
		}
		if (ref->flash_offset != REF_EMPTY_NODE && ref->next_in_ino)
			jffs2_remove_node_refs_from_ino_list(c, ref, jeb);
		/* else it was a non-inode node or already removed, so don't bother */

		ref++;
	}
	jeb->first_node = jeb->last_node = NULL;
}
