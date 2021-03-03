#include "fatfs.h"
#ifdef LOSCFG_FS_FAT
#include <string.h>
#include <sys/mount.h>
#include "errno.h"
#include "ff.h"
#include "dirop_fat.h"
#include "disk_pri.h"
#include "los_tables.h"
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#include "virpart.h"
#include "errcode_fat.h"
#include "virpartff.h"
#endif
#ifdef LOSCFG_FS_FAT_CACHE
#include "bcache.h"
#endif
#include "los_config.h"
#include "los_vm_filemap.h"
#include "los_process_pri.h"
#include "capability_type.h"
#include "capability_api.h"
#include "fs_other.h"
#include "los_strncpy_from_user.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#define DRIVER_NAME_LEN    8
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifndef FF_MULTI_PARTITION
#endif
typedef struct MatchOption MatchTable[];
enum {
    OptionUid,
    OptionGid,
    OptionUmask,
    OptionDmask,
    OptionFmask,
    OptionErr,
};
#if FF_FS_MINIMIZE <= 1
#else
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#define FAT_USER_SHIFT 6
#define FAT_GROUP_SHIFT 3
#define FAT_NO_PERM 1
#define FAT_PERM 0
#if !FF_FS_TINY
#endif
#if FF_FS_MINIMIZE <= 2
#else
#endif
#if !FF_FS_TINY
#endif
#if !FF_FS_TINY
#endif
#if !FF_FS_READONLY
#else
#endif
#if !FF_FS_READONLY
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#else
#endif
#if FF_FS_MINIMIZE <= 2
#else
#endif
#if FF_FS_MINIMIZE <= 2
#else
#endif
#if FF_FS_MINIMIZE == 0 && !FF_FS_READONLY
#else
#endif
#if FF_FS_MINIMIZE == 0 && !FF_FS_READONLY
#else
#endif
#if FF_FS_MINIMIZE == 0
#if FF_MAX_SS != FF_MIN_SS
#else
#endif
#if FF_MAX_SS != FF_MIN_SS
#else
#endif
#else
#endif
#define VOL_NAME_LEN 4
#if FF_FS_MINIMIZE == 0 && !FF_FS_READONLY
#if FF_MAX_SS != FF_MIN_SS
#else
#endif
#if FF_USE_LFN
#else
#endif
#else
#endif
#if FF_FS_MINIMIZE == 0 && !FF_FS_READONLY
#else
#endif
#if FF_FS_MINIMIZE <= 1
#else
#endif
#if FF_FS_MINIMIZE <= 1
#else
#endif
#if FF_FS_MINIMIZE <= 1
#else
#endif
#if FF_FS_MINIMIZE <= 1
#ifdef _DIRENT_HAVE_D_NAMLEN
#endif
#ifdef _DIRENT_HAVE_D_OFF
#endif
#else
#endif
#if FF_FS_MINIMIZE <= 1
#else
#endif
#if FF_FS_MINIMIZE == 0 && !FF_FS_READONLY
#else
#endif
#if FF_FS_MINIMIZE == 0 && !FF_FS_READONLY
#else
#endif
#define DMA_ALLGN  64
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#define INDEX_LABEL_LEN 15
#if FF_USE_LABEL
#endif
#if FF_USE_MKFS && !FF_FS_READONLY
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#else
#endif
#if FF_FS_MINIMIZE == 0 && !FF_FS_READONLY
#else
#endif
#if FF_USE_LABEL
#else
#endif
int fatfs_fallocate(FAR struct file *filep, int mode, off_t offset, off_t len)
{
#if FF_USE_EXPAND && !FF_FS_READONLY
    FIL *fp = (FIL *)(filep->f_priv);
    FRESULT res;

    FAT_CHECK(fp);

    if (len <= 0 || offset < 0) {
        return -EINVAL;
    }

    if (mode != FALLOC_FL_KEEP_SIZE) {
        return -EINVAL;
    }

    if (filep->f_inode->mountflags == MS_RDONLY) {
        return -EACCES;
    }

    res = f_expand(fp, (FSIZE_t)offset, (FSIZE_t)len, FALLOC_FL_KEEP_SIZE);

    if (res == FR_OK) {
        res = f_sync(fp);
    }

    return fatfs_2_vfs(res);
#else
    return -ENOSYS;
#endif
}
int fatfs_fallocate64(FAR struct file *filep, int mode, off64_t offset, off64_t len)
{
#if FF_USE_EXPAND && !FF_FS_READONLY
    FIL *fp = (FIL *)(filep->f_priv);
    FRESULT  res;

    FAT_CHECK(fp);

    if (len >= FAT32_MAXSZIE || len <= 0 || offset >= FAT32_MAXSZIE || offset < 0) {
        return -EINVAL;
    }

    if (mode != FALLOC_FL_KEEP_SIZE) {
        return -EINVAL;
    }

    if (filep->f_inode->mountflags == MS_RDONLY) {
        return -EACCES;
    }

    res = f_expand(fp, (FSIZE_t)offset, (FSIZE_t)len, FALLOC_FL_KEEP_SIZE);

    if (res == FR_OK) {
        res = f_sync(fp);
    }

    return fatfs_2_vfs(res);
#else
    return -ENOSYS;
#endif
}
#if FF_FS_MINIMIZE == 0 && !FF_FS_READONLY
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#if FF_USE_EXPAND
#else
#endif
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#else
#endif
#if FF_FS_MINIMIZE == 0 && !FF_FS_READONLY
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#if FF_USE_EXPAND
#else
#endif
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#else
#endif
#define DATE_OFFSET 16
#define CHECK_FILE_NUM 3
static INT FatFsTimeMin(DIR_FILE dirFile[])
{
    INT min = 0;
    DWORD timeMin = 0;

    MIN((dirFile[0].fno.fdate << DATE_OFFSET | dirFile[0].fno.ftime),
        (dirFile[1].fno.fdate << DATE_OFFSET | dirFile[1].fno.ftime), timeMin);
    MIN((DWORD)(dirFile[2].fno.fdate << DATE_OFFSET | dirFile[2].fno.ftime), timeMin, timeMin);
    if (timeMin == (dirFile[0].fno.fdate << DATE_OFFSET | dirFile[0].fno.ftime)) {
        min = 0;
    } else if (timeMin == (dirFile[1].fno.fdate << DATE_OFFSET | dirFile[1].fno.ftime)) {
        min = 1;
    } else if (timeMin == (dirFile[2].fno.fdate << DATE_OFFSET | dirFile[2].fno.ftime)) {
        min = 2; /* check the latest three files */
    }

    return min;
}
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#endif /* LOSCFG_FS_FAT */
