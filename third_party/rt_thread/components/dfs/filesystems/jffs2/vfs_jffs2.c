#include "los_typedef.h"
#include "los_typedef.h"
#include "fileio.h"
#include "fcntl.h"
#include "sys/stat.h"
#undef mode_t

#include "vfs_jffs2.h"
#include "jffs2_config.h"
#include "porting.h"
#include "los_mux.h"
#include "inode/inode.h"
#include "sys/statfs.h"
#include "fs/dirent_fs.h"
#include "fs/fs.h"
#include "los_tables.h"
#include "mtd_list.h"
#include "port/fcntl.h"
#include "los_vm_filemap.h"

#ifdef LOSCFG_FS_JFFS

#if DEVICE_PART_MAX > 1
	#error "support only one jffs2 partition on a flash device!"
#endif

LosMux jffs2_lock;
cyg_mtab_entry *mte[CONFIG_MTD_PATTITION_NUM];
static const char jffs2_root_path[] = ".";
#define BLOCK_SIZE    4096

int jffs2_result_to_vfs(int result)
{
	if (result > 0)
		result = -result;
	return result;
}
#ifdef  CONFIG_JFFS2_NO_RELATIVEDIR
#endif
#ifdef  CONFIG_JFFS2_NO_RELATIVEDIR
#endif
#define REDUCED_VALUE    3
int JffsMutexCreate(void)
{
    if (LOS_MuxInit(&jffs2_lock, NULL) != LOS_OK) {
        PRINT_ERR("%s, LOS_MuxCreate failed\n", __FUNCTION__);
        return -1;
    } else {
        return 0;
    }
}
#endif
