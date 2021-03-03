#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/delay.h>
#include <linux/semaphore.h>
#include <linux/pagemap.h>
#include <linux/compiler.h>
#include <mtd_dev.h>
#include "nodelist.h"
#include "os-linux.h"
#include "los_crc32.h"
#ifdef JFFS2_DBG_READINODE_MESSAGES
#endif
static void jffs2_free_tmp_dnode_info_list(struct rb_root *list)
{
	struct jffs2_tmp_dnode_info *tn;
	struct rb_node *rbn,*next;

	RB_POSTORDER_FOREACH_SAFE(rbn, linux_root, (struct linux_root *)list, next) {
		tn = (struct jffs2_tmp_dnode_info *)rbn;
		jffs2_free_full_dnode(tn->fn);
		jffs2_free_tmp_dnode_info(tn);
	}

	*list = RB_ROOT;
}
static void jffs2_free_full_dirent_list(struct jffs2_full_dirent *fd)
{
	struct jffs2_full_dirent *next;

	while (fd) {
		next = fd->next;
		jffs2_free_full_dirent(fd);
		fd = next;
	}
}
#ifdef JFFS2_DBG_READINODE2_MESSAGES
#endif
