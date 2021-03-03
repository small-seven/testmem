#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <mtd_dev.h>
#include "nodelist.h"
#include "los_exc.h"
#define for_each_inode(i, c, ic)			\
static void jffs2_build_remove_unlinked_inode(struct jffs2_sb_info *c,
					struct jffs2_inode_cache *ic,
					struct jffs2_full_dirent **dead_fds)
{
	struct jffs2_raw_node_ref *raw;
	struct jffs2_full_dirent *fd;

	dbg_fsbuild("removing ino #%u with nlink == zero.\n", ic->ino);

	raw = ic->nodes;
	while (raw != (void *)ic) {
		struct jffs2_raw_node_ref *next = raw->next_in_ino;
		dbg_fsbuild("obsoleting node at 0x%08x\n", ref_offset(raw));
		jffs2_mark_node_obsolete(c, raw);
		raw = next;
	}

	if (ic->scan_dents) {
		int whinged = 0;
		dbg_fsbuild("inode #%u was a directory which may have children...\n", ic->ino);

		while(ic->scan_dents) {
			struct jffs2_inode_cache *child_ic;

			fd = ic->scan_dents;
			ic->scan_dents = fd->next;

			if (!fd->ino) {
				/* It's a deletion dirent. Ignore it */
				dbg_fsbuild("child \"%s\" is a deletion dirent, skipping...\n", fd->name);
				jffs2_free_full_dirent(fd);
				continue;
			}
			if (!whinged)
				whinged = 1;

			dbg_fsbuild("removing child \"%s\", ino #%u\n", fd->name, fd->ino);

			child_ic = jffs2_get_ino_cache(c, fd->ino);
			if (!child_ic) {
				dbg_fsbuild("cannot remove child \"%s\", ino #%u, because it doesn't exist\n",
						fd->name, fd->ino);
				jffs2_free_full_dirent(fd);
				continue;
			}

			/* Reduce nlink of the child. If it's now zero, stick it on the
			   dead_fds list to be cleaned up later. Else just free the fd */

			if (fd->type == DT_DIR)
				child_ic->pino_nlink = 0;
			else
				child_ic->pino_nlink--;

			if (!child_ic->pino_nlink) {
				dbg_fsbuild("inode #%u (\"%s\") now has no links; adding to dead_fds list.\n",
					  fd->ino, fd->name);
				fd->next = *dead_fds;
				*dead_fds = fd;
			} else {
				dbg_fsbuild("inode #%u (\"%s\") has now got nlink %d. Ignoring.\n",
					  fd->ino, fd->name, child_ic->pino_nlink);
				jffs2_free_full_dirent(fd);
			}
		}
	}

	/*
	   We don't delete the inocache from the hash list and free it yet.
	   The erase code will do that, when all the nodes are completely gone.
	*/
}
#ifndef __ECOS
#endif
#ifndef __ECOS
#endif
