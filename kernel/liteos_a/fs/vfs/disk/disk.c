#include "disk.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/mount.h"
#include "pthread.h"
#include "linux/spinlock.h"
#include "inode/inode.h"
#ifdef LOSCFG_DRIVERS_MMC
#include "mmc/block.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define MEM_ADDR_ALIGN_BYTE  64
#define RWE_RW_RW            0755
#define DISK_LOCK(mux) do {                                              \
#define DISK_UNLOCK(mux) do {                                              \
typedef VOID *(*StorageHookFunction)(VOID *);

static UINT32 OsReHookFuncAddDiskRef(StorageHookFunction handler,
                                     VOID *param) __attribute__((weakref("osReHookFuncAdd")));

static UINT32 OsReHookFuncDelDiskRef(StorageHookFunction handler) __attribute__((weakref("osReHookFuncDel")));

#ifdef LOSCFG_FS_FAT_CACHE
UINT32 GetFatBlockNums(VOID)
{
    return g_uwFatBlockNums;
}
#endif
INT32 los_alloc_diskid_byname(const CHAR *diskName)
{
    INT32 diskID;
    los_disk *disk = NULL;
    UINT32 intSave;
    size_t nameLen;

    if (diskName == NULL) {
        PRINT_ERR("The paramter disk_name is NULL");
        return VFS_ERROR;
    }

    nameLen = strlen(diskName);
    if (nameLen > DISK_NAME) {
        PRINT_ERR("diskName is too long!\n");
        return VFS_ERROR;
    }
    spin_lock_irqsave(&g_diskSpinlock, intSave);

    for (diskID = 0; diskID < SYS_MAX_DISK; diskID++) {
        disk = get_disk(diskID);
        if ((disk != NULL) && (disk->disk_status == STAT_UNUSED)) {
            disk->disk_status = STAT_UNREADY;
            break;
        }
    }

    spin_unlock_irqrestore(&g_diskSpinlock, intSave);

    if ((disk == NULL) || (diskID == SYS_MAX_DISK)) {
        PRINT_ERR("los_alloc_diskid_byname failed %d!\n", diskID);
        return VFS_ERROR;
    }

    if (disk->disk_name != NULL) {
        LOS_MemFree(m_aucSysMem0, disk->disk_name);
        disk->disk_name = NULL;
    }

    disk->disk_name = LOS_MemAlloc(m_aucSysMem0, (nameLen + 1));
    if (disk->disk_name == NULL) {
        PRINT_ERR("los_alloc_diskid_byname alloc disk name failed\n");
        return VFS_ERROR;
    }

    if (strncpy_s(disk->disk_name, (nameLen + 1), diskName, nameLen) != EOK) {
        PRINT_ERR("The strncpy_s failed.\n");
        return VFS_ERROR;
    }

    disk->disk_name[nameLen] = '\0';

    return diskID;
}
#ifdef LOSCFG_FS_FAT_CACHE
#endif
static los_part *DiskPartAllocate(struct inode *dev, UINT64 start, UINT64 count)
{
    UINT32 i;
    los_part *part = get_part(0); /* traversing from the beginning of the array */

    for (i = 0; i < SYS_MAX_PART; i++) {
        if (part->dev == NULL) {
            part->part_id = i;
            part->part_no_mbr = 0;
            part->dev = dev;
            part->sector_start = start;
            part->sector_count = count;
            part->part_name = NULL;
            LOS_ListInit(&part->list);

            return part;
        }
        part++;
    }

    return NULL;
}
static VOID DiskPartRelease(los_part *part)
{
    part->dev = NULL;
    part->part_no_disk = 0;
    part->part_no_mbr = 0;
    if (part->part_name != NULL) {
        free(part->part_name);
        part->part_name = NULL;
    }
}
#define DEV_NAME_BUFF_SIZE  (DISK_NAME + 3)
static INT32 DiskPartitionMemZalloc(size_t boundary, size_t size, CHAR **gptBuf, CHAR **partitionBuf)
{
    CHAR *buffer1 = NULL;
    CHAR *buffer2 = NULL;

    buffer1 = (CHAR *)memalign(boundary, size);
    if (buffer1 == NULL) {
        PRINT_ERR("%s buffer1 malloc %lu failed! %d\n", __FUNCTION__, size, __LINE__);
        return VFS_ERROR;
    }
    buffer2 = (CHAR *)memalign(boundary, size);
    if (buffer2 == NULL) {
        PRINT_ERR("%s buffer2 malloc %lu failed! %d\n", __FUNCTION__, size, __LINE__);
        free(buffer1);
        return VFS_ERROR;
    }
    (VOID)memset_s(buffer1, size, 0, size);
    (VOID)memset_s(buffer2, size, 0, size);

    *gptBuf = buffer1;
    *partitionBuf = buffer2;

    return ENOERR;
}
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#define GET_ERASE_BLOCK_SIZE 0x2
#ifdef LOSCFG_FS_FAT_CACHE
#ifdef LOSCFG_FS_FAT_CACHE_SYNC_THREAD
#endif
#define SECTOR_SIZE 512
static VOID DiskCacheDeinit(los_disk *disk)
{
    UINT32 diskID = disk->disk_id;
    if (GetDiskUsbStatus(diskID) == FALSE) {
        if (BcacheAsyncPrereadDeinit(disk->bcache) != LOS_OK) {
            PRINT_ERR("Blib async preread deinit failed in %s, %d\n", __FUNCTION__, __LINE__);
        }
#ifdef LOSCFG_FS_FAT_CACHE_SYNC_THREAD
        BcacheSyncThreadDeinit(disk->bcache);
#endif
    }

    BlockCacheDeinit(disk->bcache);
    disk->bcache = NULL;

    if (OsReHookFuncDelDiskRef != NULL) {
        (VOID)OsReHookFuncDelDiskRef((StorageHookFunction)OsSdSync);
    }
}
#endif
static INT32 DiskDeinit(los_disk *disk)
{
    los_part *part = NULL;
    char *diskName = NULL;
    CHAR devName[DEV_NAME_BUFF_SIZE];
    INT32 ret;

    if (LOS_ListEmpty(&disk->head) == FALSE) {
        part = LOS_DL_LIST_ENTRY(disk->head.pstNext, los_part, list);
        while (&part->list != &disk->head) {
            diskName = (disk->disk_name == NULL) ? "null" : disk->disk_name;
            ret = snprintf_s(devName, sizeof(devName), sizeof(devName) - 1, "%s%c%d",
                             diskName, 'p', disk->part_count - 1);
            if (ret < 0) {
                return -ENAMETOOLONG;
            }
            DiskPartDelFromDisk(disk, part);
            (VOID)unregister_blockdriver(devName);
            DiskPartRelease(part);

            part = LOS_DL_LIST_ENTRY(disk->head.pstNext, los_part, list);
        }
    }

    DISK_LOCK(&disk->disk_mutex);

#ifdef LOSCFG_FS_FAT_CACHE
    DiskCacheDeinit(disk);
#endif

    disk->dev = NULL;
    DISK_UNLOCK(&disk->disk_mutex);
    (VOID)unregister_blockdriver(disk->disk_name);
    if (disk->disk_name != NULL) {
        LOS_MemFree(m_aucSysMem0, disk->disk_name);
        disk->disk_name = NULL;
    }
    ret = pthread_mutex_destroy(&disk->disk_mutex);
    if (ret != 0) {
        PRINT_ERR("%s %d, mutex destroy failed, ret = %d\n", __FUNCTION__, __LINE__, ret);
        return -EFAULT;
    }

    disk->disk_status = STAT_UNUSED;

    return ENOERR;
}
#ifdef LOSCFG_FS_FAT_CACHE
#endif
INT32 los_disk_deinit(INT32 diskID)
{
    los_disk *disk = get_disk(diskID);
    if (disk == NULL) {
        return -EINVAL;
    }

    DISK_LOCK(&disk->disk_mutex);

    if (disk->disk_status != STAT_INUSED) {
        DISK_UNLOCK(&disk->disk_mutex);
        return -EINVAL;
    }

    disk->disk_status = STAT_UNREADY;
    DISK_UNLOCK(&disk->disk_mutex);

    return DiskDeinit(disk);
}
#ifdef LOSCFG_FS_FAT_CACHE
#endif
#ifdef LOSCFG_FS_FAT_CACHE
#else
#endif
#ifdef LOSCFG_DRIVERS_MMC
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
