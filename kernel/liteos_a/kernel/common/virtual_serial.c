#include "virtual_serial.h"
#include "fcntl.h"
#ifdef LOSCFG_FILE_MODE
#include "stdarg.h"
#endif
#ifdef LOSCFG_FS_VFS
#include "inode/inode.h"
#include "console.h"
#endif
#include "uart.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if defined(LOSCFG_DRIVERS_USB_SERIAL_GADGET) || defined(LOSCFG_DRIVERS_USB_ETH_SER_GADGET)
#endif
#ifndef CONFIG_DISABLE_POLL
#endif
INT32 virtual_serial_deinit(VOID)
{
    INT32 ret;
    struct file *filep = NULL;
    struct inode *inode = NULL;
    CHAR *fullpath = NULL;
    struct inode_search_s desc;

    /* It's a process opposite virtual_serial_init */
    ret = vfs_normalize_path(NULL, SERIAL, &fullpath);
    if (ret < 0) {
        ret = EINVAL;
        goto ERROUT;
    }
    SETUP_SEARCH(&desc, fullpath, false);
    ret = inode_find(&desc);
    if (ret < 0) {
        ret = EACCES;
        goto ERROUT_WITH_FULLPATH;
    }
    inode = desc.node;

    filep = inode->i_private;
    if ((filep != NULL) && (inode->u.i_ops != NULL)) {
        (VOID)inode->u.i_ops->close(filep);     /* close filep */
        inode->i_private = NULL;
    } else {
        ret = EBADF;
        goto ERROUT_WITH_INODE;
    }
    inode_release(inode);
    free(fullpath);
    (VOID)unregister_driver(SERIAL);

    return ENOERR;

ERROUT_WITH_INODE:
    inode_release(inode);
ERROUT_WITH_FULLPATH:
    free(fullpath);
ERROUT:
    set_errno(ret);
    return VFS_ERROR;
}
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
