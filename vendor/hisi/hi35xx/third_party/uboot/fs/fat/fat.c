#include <common.h>
#include <blk.h>
#include <config.h>
#include <exports.h>
#include <fat.h>
#include <fs.h>
#include <asm/byteorder.h>
#include <part.h>
#include <malloc.h>
#include <memalign.h>
#include <linux/compiler.h>
#include <linux/ctype.h>
#define DOS_BOOT_MAGIC_OFFSET	0x1fe
#define DOS_FS_TYPE_OFFSET	0x36
#define DOS_FS32_TYPE_OFFSET	0x52
#if CONFIG_IS_ENABLED(PARTITION_UUIDS)
#endif
#if !CONFIG_IS_ENABLED(FAT_WRITE)
#endif
typedef struct {
	fsdata    *fsdata;        /* filesystem parameters */
	unsigned   start_clust;   /* first cluster */
	unsigned   clust;         /* current cluster */
	unsigned   next_clust;    /* next cluster if remaining == 0 */
	int        last_cluster;  /* set once we've read last cluster */
	int        is_root;       /* is iterator at root directory */
	int        remaining;     /* remaining dent's in current cluster */

	/* current iterator position values: */
	dir_entry *dent;          /* current directory entry */
	char       l_name[VFAT_MAXLEN_BYTES];    /* long (vfat) name */
	char       s_name[14];    /* short 8.3 name */
	char      *name;          /* l_name if there is one, else s_name */

	/* storage for current cluster in memory: */
	u8         block[MAX_CLUSTSIZE] __aligned(ARCH_DMA_MINALIGN);
} fat_itr;
#define TYPE_FILE 0x1
#define TYPE_DIR  0x2
#define TYPE_ANY  (TYPE_FILE | TYPE_DIR)
#if defined(CONFIG_IDE) || \
#endif
typedef struct {
	struct fs_dir_stream parent;
	struct fs_dirent dirent;
	fsdata fsdata;
	fat_itr itr;
} fat_dir;
