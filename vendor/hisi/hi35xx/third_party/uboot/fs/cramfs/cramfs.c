#include <common.h>
#include <malloc.h>
#include <asm/byteorder.h>
#include <linux/stat.h>
#include <jffs2/jffs2.h>
#include <jffs2/load_kernel.h>
#include <cramfs/cramfs_fs.h>
#define CRAMINO(x)	(CRAMFS_GET_OFFSET(x) ? CRAMFS_GET_OFFSET(x)<<2 : 1)
#define OFFSET(x)	((x)->i_ino)
#if defined(CONFIG_MTD_NOR_FLASH)
#define PART_OFFSET(x)	((ulong)x->offset + \
#else
#define PART_OFFSET(x)	((ulong)x->offset)
#endif
