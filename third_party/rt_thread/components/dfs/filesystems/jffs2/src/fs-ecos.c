#include <stdio.h>    //prife for SEEK_SET SEEK_CUR SEEK_END
#include <linux/kernel.h>
#include <string.h>
#include <linux/pagemap.h>
#include <linux/semaphore.h>
#include <linux/delay.h>
#include "mtd_list.h"
#include "jffs2/nodelist.h"
#include "los_crc32.h"
#include "jffs2/compr.h"
#include "port/fcntl.h"
#include "porting.h"
#include "spinor.h"
#include "limits.h"
#include "los_process_pri.h"
#include "capability_type.h"
#include "capability_api.h"
#include "mtd_partition.h"
#include "vfs_jffs2.h"
#define JFFS_PATH_DIVIDERS  "/"
typedef struct jffs2_dirsearch jffs2_dirsearch;

//==========================================================================
// Ref count and nlink management

// FIXME: This seems like real cruft. Wouldn't it be better just to do the
// right thing?
static void icache_evict(struct _inode *root_i, struct _inode *i)
{
	struct _inode *this = root_i;
	struct _inode *next = NULL;
	struct _inode *temp = NULL;
	struct jffs2_inode_info *f = NULL;
	jffs_lock();
 restart:
	D2(PRINTK("icache_evict\n"));
	// If this is an absolute search path from the root,
	// remove all cached inodes with i_count of zero (these are only
	// held where needed for dotdot filepaths)

	while (this) {
		next = this->i_cache_next;
		if (this != i && this->i_count == 0) {
			struct _inode *parent = this->i_parent;

			if (this->i_cache_next)
				this->i_cache_next->i_cache_prev = this->i_cache_prev;
			if (this->i_cache_prev)
				this->i_cache_prev->i_cache_next = this->i_cache_next;
			jffs2_clear_inode(this);
			f = JFFS2_INODE_INFO(this);
			(void)mutex_destroy(&(f->sem));
			(void)memset_s(this, sizeof(*this), 0x5a, sizeof(*this));
			temp = this;
			free(this);
			if (parent && parent != temp) {
				parent->i_count--;
				this = root_i;
				goto restart;
			}
#ifdef CYGOPT_FS_JFFS2_GCTHREAD
#endif
#ifdef CYGOPT_FS_JFFS2_GCTHREAD
#endif
#ifndef CYGOPT_FS_JFFS2_WRITE
#endif
#ifdef CYGOPT_FS_JFFS2_WRITE
#endif
#ifdef CYGOPT_FS_JFFS2_WRITE
#else
#endif
#ifdef CYGOPT_FS_JFFS2_WRITE
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#endif /* CYGOPT_FS_JFFS2_WRITE */
#ifdef CYGPKG_FS_JFFS2_RET_DIRENT_DTYPE
#endif
#ifdef CYGPKG_FS_JFFS2_RET_DIRENT_DTYPE
#endif
void jffs2_gc_release_page(struct jffs2_sb_info *c,
		   unsigned char *ptr,
		   unsigned long *priv)
{
	/* Do nothing */
}
void jffs2_gc_release_inode(struct jffs2_sb_info *c,
		   struct jffs2_inode_info *f)
{
	jffs2_iput(OFNI_EDONI_2SFFJ(f));
}
