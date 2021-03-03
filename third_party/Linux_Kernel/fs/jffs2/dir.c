#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include "los_crc32.h"
#include "nodelist.h"
#include "vfs_jffs2.h"
#include "porting.h"
int jffs2_create(struct _inode *dir_i, const unsigned char *d_name, int mode,
				 struct _inode **new_i)
{
	struct jffs2_raw_inode *ri;
	struct jffs2_inode_info *f, *dir_f;
	struct jffs2_sb_info *c;
	struct _inode *inode;
	int ret;
	mode  &= ~S_IFMT;
	mode |= S_IFREG;
	ri = jffs2_alloc_raw_inode();
	if (!ri)
		return -ENOMEM;

	c = JFFS2_SB_INFO(dir_i->i_sb);

	D1(printk(KERN_DEBUG "jffs2_create()\n"));
	inode = jffs2_new_inode(dir_i, mode, ri);

	if (IS_ERR(inode)) {
		D1(printk(KERN_DEBUG "jffs2_new_inode() failed, error:%ld\n", PTR_ERR(inode)));
		jffs2_free_raw_inode(ri);
		return PTR_ERR(inode);
	}

	f = JFFS2_INODE_INFO(inode);
	dir_f = JFFS2_INODE_INFO(dir_i);

	/* jffs2_do_create() will want to lock it, _after_ reserving
	   space and taking c-alloc_sem. If we keep it locked here,
	   lockdep gets unhappy (although it's a false positive;
	   nothing else will be looking at this inode yet so there's
	   no chance of AB-BA deadlock involving its f->sem). */
	mutex_unlock(&f->sem);
	ret = jffs2_do_create(c, dir_f, f, ri,
				(const char *)d_name,
				strlen((char *)d_name));

	if (ret) {
		inode->i_nlink = 0;
		jffs2_iput(inode);
		jffs2_free_raw_inode(ri);
		return ret;
	}

	jffs2_free_raw_inode(ri);

	D1(printk(KERN_DEBUG "jffs2_create: Created ino #%lu with mode %o, nlink %d(%d)\n",
		inode->i_ino, inode->i_mode, inode->i_nlink, f->inocache->pino_nlink));
	*new_i = inode;
	return 0;
}