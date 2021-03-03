#include <common.h>
#include <command.h>
#include <env.h>
#include <malloc.h>
#include <mapmem.h>
#include <linux/list.h>
#include <linux/ctype.h>
#include <jffs2/jffs2.h>
#include <jffs2/load_kernel.h>
#include <cramfs/cramfs_fs.h>
#include <asm/io.h>
#define	DEBUG_CRAMFS
#undef	DEBUG_CRAMFS
#ifdef  DEBUG_CRAMFS
# define DEBUGF(fmt, args...)	printf(fmt ,##args)
#else
# define DEBUGF(fmt, args...)
#endif
#include <flash.h>
#ifndef CONFIG_MTD_NOR_FLASH
# define OFFSET_ADJUSTMENT	0
#else
# define OFFSET_ADJUSTMENT	(flash_info[id.num].start[0])
#endif
#ifndef CONFIG_FS_JFFS2
#include <linux/stat.h>
#endif /* CONFIG_FS_JFFS2 */
