#include "fs/fs.h"
#include "fs/fs_operation.h"
#include "fs_other.h"
#include "unistd.h"
#include "los_mux.h"
#include "los_list.h"
#include "los_atomic.h"
#include "los_vm_filemap.h"
int remove_mapping_nolock(const char *fullpath, const struct file *ex_filp)
{
    int fd;
    struct file *filp = NULL;
    struct file_map *fmap = NULL;
    struct page_mapping *mapping = NULL;
    struct inode *node = NULL;

    if (fullpath == NULL) {
        set_errno(EINVAL);
        return EINVAL;
    }

    /* file start fd */

    for (fd = 3; fd < CONFIG_NFILE_DESCRIPTORS; fd++) {
        node = files_get_openfile(fd);
        if (node == NULL) {
            continue;
        }
        filp = &tg_filelist.fl_files[fd];

        /* ex_filp NULL: do not exclude any file, just matching the file name ; ex_filp not NULL: exclude it.
         * filp != ex_filp includes the two scenarios.
         */

        if (filp != ex_filp) {
            if (filp->f_path == NULL) {
                continue;
            }
            if ((strcmp(filp->f_path, fullpath) == 0)) {
                PRINT_WARN("%s is open(fd=%d), remove cache failed.\n", fullpath, fd);
                set_errno(EBUSY);
                return EBUSY;
            }
        }
    }

    (VOID)LOS_MuxLock(&g_file_mapping.lock, LOS_WAIT_FOREVER);

    mapping = find_mapping_nolock(fullpath);
    if (!mapping) {
        /* this scenario is a normal case */

        goto out;
    }

    (VOID)LOS_MuxDestroy(&mapping->mux_lock);
    clear_file_mapping_nolock(mapping);
    OsFileCacheRemove(mapping);
    fmap = LOS_DL_LIST_ENTRY(mapping,
    struct file_map, mapping);
    LOS_ListDelete(&fmap->head);
    LOS_MemFree(m_aucSysMem0, fmap);

out:
    (VOID)LOS_MuxUnlock(&g_file_mapping.lock);

    return OK;
}
int remove_mapping(const char *fullpath, const struct file *ex_filp)
{
    int ret;
    struct filelist *f_list = NULL;

    f_list = &tg_filelist;
    ret = sem_wait(&f_list->fl_sem);
    if (ret < 0) {
        PRINTK("sem_wait error, ret=%d\n", ret);
        return VFS_ERROR;
    }

    ret = remove_mapping_nolock(fullpath, ex_filp);

    (void)sem_post(&f_list->fl_sem);
    return OK;
}
