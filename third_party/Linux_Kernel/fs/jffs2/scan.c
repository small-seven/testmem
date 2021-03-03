#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/pagemap.h>
#include <linux/compiler.h>
#include "nodelist.h"
#include "summary.h"
#include "debug.h"
#include "mtd_dev.h"
#include "los_typedef.h"
#include "los_typedef.h"
#include "los_crc32.h"

#define DEFAULT_EMPTY_SCAN_SIZE 256

#define noisy_printk(noise, fmt, ...)					\
do {									\
	if (*(noise)) {							\
		pr_notice(fmt, ##__VA_ARGS__);				\
		(*(noise))--;						\
		if (!(*(noise)))					\
			pr_notice("Further such events for this erase block will not be printed\n"); \
	}								\
static inline int min_free(struct jffs2_sb_info *c)
{
	uint32_t min = 2 * sizeof(struct jffs2_raw_inode);
#ifdef CONFIG_JFFS2_FS_WRITEBUFFER
	if (!jffs2_can_mark_obsolete(c) && min < c->wbuf_pagesize)
		return c->wbuf_pagesize;
#endif
	return min;

}
#ifdef CONFIG_JFFS2_FS_WRITEBUFFER
#endif
#ifdef CONFIG_JFFS2_FS_XATTR
#endif
#ifdef CONFIG_JFFS2_FS_WRITEBUFFER
#endif
#ifdef CONFIG_JFFS2_FS_WRITEBUFFER
#endif
#ifdef CONFIG_JFFS2_FS_WRITEBUFFER
#endif
#ifdef CONFIG_JFFS2_FS_XATTR
#endif	/* CONFIG_JFFS2_FS_XATTR */
