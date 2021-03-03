#include <common.h>
#include <dm.h>
#include <env.h>
#include <pci.h>
#include <scsi.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#if !defined(CONFIG_DM_SCSI)
# ifdef CONFIG_SCSI_DEV_LIST
#  define SCSI_DEV_LIST CONFIG_SCSI_DEV_LIST
# else
#  ifdef CONFIG_SATA_ULI5288
#   define SCSI_VEND_ID 0x10b9
#   define SCSI_DEV_ID  0x5288
#  elif !defined(CONFIG_SCSI_AHCI_PLAT)
#   error no scsi device defined
#  endif
# define SCSI_DEV_LIST {SCSI_VEND_ID, SCSI_DEV_ID}
# endif
#endif
#if defined(CONFIG_PCI) && !defined(CONFIG_SCSI_AHCI_PLAT) && \
#endif
#if !defined(CONFIG_DM_SCSI)
#endif
#define SCSI_MAX_BLK 0xFFFF
#define SCSI_LBA48_READ	0xFFFFFFF
#ifdef CONFIG_SYS_64BIT_LBA
#endif
#ifdef CONFIG_BLK
#ifdef CONFIG_SYS_64BIT_LBA
#endif
#endif
#if defined(CONFIG_PCI) && !defined(CONFIG_SCSI_AHCI_PLAT) && \
#ifdef CONFIG_DM_PCI
#else
#endif
#ifdef DEBUG
#endif
#endif
#if !defined(CONFIG_DM_SCSI)
#endif
#if defined(CONFIG_DM_SCSI)
#else
#ifndef CONFIG_SPL_BUILD
#endif
#endif
#ifdef CONFIG_BLK
#else
#endif
