#include "vfs_config.h"
#include "sys/types.h"
#include "assert.h"
#include "errno.h"
#include "fcntl.h"
#include "sched.h"
#include "unistd.h"
#include "inode/inode.h"
static ssize_t file_fallocate(FAR struct file *filep, int mode, off_t offset, off_t len)
{
    FAR struct inode *inode = NULL;
    int ret;
    int err;

    if (len <= 0) {
        err = EINVAL;
        goto errout;
    }

    /* Was this file opened for write access? */

    if (((unsigned int)(filep->f_oflags) & O_ACCMODE) == O_RDONLY) {
        err = EACCES;
        goto errout;
    }

    /* Is a driver registered? Does it support the fallocate method? */

    inode = filep->f_inode;
    if (!inode || !inode->u.i_mops || !inode->u.i_mops->fallocate) {
        err = EBADF;
        goto errout;
    }

    /* Yes, then let the driver perform the fallocate */

    ret = inode->u.i_mops->fallocate(filep, mode, offset, len);
    if (ret < 0) {
        err = -ret;
        goto errout;
    }

    return ret;

errout:
    set_errno(err);
    return VFS_ERROR;
}
int fallocate(int fd, int mode, off_t offset, off_t len)
{
#if CONFIG_NFILE_DESCRIPTORS > 0
    FAR struct file *filep = NULL;
#endif

/* Did we get a valid file descriptor? */

#if CONFIG_NFILE_DESCRIPTORS > 0
    if ((unsigned int)fd >= CONFIG_NFILE_DESCRIPTORS)
#endif
    {
        set_errno(EBADF);
        return VFS_ERROR;
    }

#if CONFIG_NFILE_DESCRIPTORS > 0

    /* The descriptor is in the right range to be a file descriptor... write to the file.*/

    int ret = fs_getfilep(fd, &filep);
    if (ret < 0)
      {
        /* The errno value has already been set */
        return VFS_ERROR;
      }

    if (filep->f_oflags & O_DIRECTORY)
      {
        set_errno(EBADF);
        return VFS_ERROR;
      }

    /* Perform the fallocate operation using the file descriptor as an index */

    return file_fallocate(filep, mode, offset, len);
#endif
}
