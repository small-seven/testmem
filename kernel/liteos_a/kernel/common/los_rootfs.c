#include "los_base.h"
#include "los_typedef.h"
#include "los_typedef.h"
#include "string.h"
#ifdef LOSCFG_PLATFORM_HI3518EV300
#include "mtd_partition.h"
#endif
#ifdef LOSCFG_DRIVERS_MMC
#include "mmc/block.h"
#include "disk.h"
#include "ff.h"
#endif
#include "sys/mount.h"
#include "inode/inode.h"
#ifdef LOSCFG_PLATFORM_ROOTFS
#include "los_rootfs.h"
#endif
#include "mtd_list.h"

#ifdef LOSCFG_PLATFORM_HI3518EV300
#define DEV_STORAGE_PATH       "/dev/spinorblk2"
#define SECOND_MTD_PART_NUM 2
#define STORAGE_SIZE 0x100000
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#ifdef LOSCFG_PLATFORM_HI3516DV300
#define STORAGE_SIZE 0x3200000
STATIC los_disk *g_emmcDisk = NULL;
#endif

#ifndef LOSCFG_SECURITY_BOOT
STATIC INT32 g_alignSize = 0;
#endif

#define VFAT_STORAGE_MOUNT_DIR_MODE 777
#define DEFAULT_STORAGE_MOUNT_DIR_MODE 755

#ifdef LOSCFG_DRIVERS_MMC
los_disk *GetMmcDisk(UINT8 type)
{
    const CHAR *mmcDevHead = "/dev/mmcblk";

    for (INT32 diskId = 0; diskId < SYS_MAX_DISK; diskId++) {
        los_disk *disk = get_disk(diskId);
        if (disk == NULL) {
            continue;
        } else if (disk->disk_name == NULL) {
#endif
#ifdef LOSCFG_PLATFORM_HI3516DV300
#endif
#ifdef LOSCFG_PLATFORM_HI3518EV300
#endif
#ifdef LOSCFG_DRIVERS_USB_MASS_STORAGE
#endif
#ifdef LOSCFG_DRIVERS_SD
#endif
#ifdef LOSCFG_PLATFORM_HI3516DV300
#endif
#ifndef LOSCFG_SECURITY_BOOT
#ifdef LOSCFG_PLATFORM_HI3516DV300
#endif
#ifdef LOSCFG_PLATFORM_HI3518EV300
#endif
#endif
#ifdef LOSCFG_PLATFORM_HI3516DV300
#endif
#ifdef LOSCFG_PLATFORM_HI3516DV300
#endif
#ifdef LOSCFG_PLATFORM_HI3518EV300
#endif
#ifdef LOSCFG_SECURITY_BOOT
#else
#endif
