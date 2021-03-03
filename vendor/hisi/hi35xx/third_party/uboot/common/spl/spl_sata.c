#include <common.h>
#include <spl.h>
#include <asm/u-boot.h>
#include <sata.h>
#include <scsi.h>
#include <errno.h>
#include <fat.h>
#include <image.h>
#ifndef CONFIG_SYS_SATA_FAT_BOOT_PARTITION
#define CONFIG_SYS_SATA_FAT_BOOT_PARTITION	1
#endif
#ifndef CONFIG_SPL_FS_LOAD_PAYLOAD_NAME
#define CONFIG_SPL_FS_LOAD_PAYLOAD_NAME	"u-boot.img"
#endif
#ifndef CONFIG_SPL_SATA_RAW_U_BOOT_SECTOR
#define CONFIG_SPL_SATA_RAW_U_BOOT_SECTOR 0x100
#endif
#if !defined(CONFIG_DM_SCSI) && !defined(CONFIG_AHCI)
#endif
#ifdef CONFIG_SPL_LIBCOMMON_SUPPORT
#endif
#ifdef CONFIG_SPL_OS_BOOT
#endif
