#include "menuconfig.h"
#ifdef LOSCFG_FS_VFS
#include "errno.h"
#include "unistd.h"
#include "fs/fd_table.h"
#include "fs/file.h"
#include "fs/fs.h"
#include "fs/fs_operation.h"
#include "sys/mount.h"
#include "los_task_pri.h"
#include "sys/utsname.h"
#include "sys/uio.h"
#include "poll.h"
#include "sys/prctl.h"
#include "los_exec_elf.h"
#include "los_syscall.h"
#include "dirent.h"
#include "user_copy.h"
#include "los_vm_map.h"
#include "los_memory.h"
#include "los_strncpy_from_user.h"
#include "fs_other.h"
#include "fs_file.h"
#include "capability_type.h"
#include "capability_api.h"
#ifdef LOSCFG_FILE_MODE
#else
#endif
#ifdef LOSCFG_FILE_MODE
#else
#endif
int SysFallocate(int fd, int mode, off_t offset, off_t len)
{
    int ret;

    /* Process fd convert to system global fd */
    fd = GetAssociatedSystemFd(fd);

    ret = fallocate(fd, mode, offset, len);
    if (ret < 0) {
        return -get_errno();
    }
    return ret;
}
int SysFallocate64(int fd, int mode, off64_t offset, off64_t len)
{
    int ret;

    /* Process fd convert to system global fd */
    fd = GetAssociatedSystemFd(fd);

    ret = fallocate64(fd, mode, offset, len);
    if (ret < 0) {
        return -get_errno();
    }
    return ret;
}
#ifdef LOSCFG_FS_FAT
#endif
#endif
