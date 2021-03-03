#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/rbtree.h>
#include <linux/pagemap.h>
#include <mtd_dev.h>
#include "nodelist.h"
#include "jffs2.h"
#include "los_crc32.h"
#ifdef CONFIG_JFFS2_FS_XATTR
#endif
void jffs2_free_ino_caches(struct jffs2_sb_info *c)
{
	int i;
	struct jffs2_inode_cache *this, *next;

	for (i=0; i < c->inocache_hashsize; i++) {
		this = c->inocache_list[i];
		while (this) {
			next = this->next;
			jffs2_xattr_free_inode(c, this);
			jffs2_free_inode_cache(this);
			this = next;
		}
		c->inocache_list[i] = NULL;
	}
}
void jffs2_free_raw_node_refs(struct jffs2_sb_info *c)
{
	int i;
	struct jffs2_raw_node_ref *this, *next;
	struct super_block *sb = NULL;
	struct MtdNorDev *device = NULL;
	sb = OFNI_BS_2SFFJ(c);
	device = (struct MtdNorDev*)(sb->s_dev);

	for (i=device->blockStart; i<c->nr_blocks+device->blockStart; i++) {
		this = c->blocks[i].first_node;
		while (this) {
			if (this[REFS_PER_BLOCK].flash_offset == REF_LINK_NODE)
				next = this[REFS_PER_BLOCK].next_in_ino;
			else
				next = NULL;

			jffs2_free_refblock(this);
			this = next;
		}
		c->blocks[i].first_node = c->blocks[i].last_node = NULL;
	}
}
#ifdef TEST_TOTLEN
#endif
#ifdef TEST_TOTLEN
#endif
#ifdef TEST_TOTLEN
#if defined(JFFS2_DBG_DUMPS) || defined(JFFS2_DBG_PARANOIA_CHECKS)
#endif
#endif /* TEST_TOTLEN */
