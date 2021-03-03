#include <common.h>
#include <cpu_func.h>
#include <command.h>
#include <dm.h>
#include <pci.h>
#include <asm/processor.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <malloc.h>
#include <memalign.h>
#include <pci.h>
#include <scsi.h>
#include <libata.h>
#include <linux/ctype.h>
#include <ahci.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#ifndef CONFIG_DM_SCSI
#endif
#define writel_with_flush(a,b)	do { writel(a,b); readl(b); } while (0)
#ifndef MAX_SATA_BLOCKS_READ_WRITE
#define MAX_SATA_BLOCKS_READ_WRITE	0x80
#endif
#define WAIT_MS_SPINUP	20000
#define WAIT_MS_DATAIO	10000
#define WAIT_MS_FLUSH	5000
#define WAIT_MS_LINKUP	200
#define AHCI_CAP_S64A BIT(31)
#define msleep(a) udelay(a * 1000)
#ifdef CONFIG_SUNXI_AHCI
#endif
#if !defined(CONFIG_SCSI_AHCI_PLAT) && !defined(CONFIG_DM_SCSI)
# ifdef CONFIG_DM_PCI
# else
# endif
#endif
#if !defined(CONFIG_SCSI_AHCI_PLAT) && !defined(CONFIG_DM_SCSI)
# ifdef CONFIG_DM_PCI
# else
# endif
#endif
#if !defined(CONFIG_DM_SCSI)
#endif
#ifdef CONFIG_SUNXI_AHCI
#endif
#if !defined(CONFIG_DM_SCSI)
#ifndef CONFIG_SCSI_AHCI_PLAT
# ifdef CONFIG_DM_PCI
# else
# endif
#endif
#endif
#if !defined(CONFIG_SCSI_AHCI_PLAT) && !defined(CONFIG_DM_SCSI)
# if defined(CONFIG_DM_PCI)
# else
# endif
#endif
#if defined(CONFIG_SCSI_AHCI_PLAT) || defined(CONFIG_DM_SCSI)
#else
# ifdef CONFIG_DM_PCI
# else
# endif
#endif
#if defined(CONFIG_DM_SCSI) || !defined(CONFIG_SCSI_AHCI_PLAT)
# if defined(CONFIG_DM_PCI) || defined(CONFIG_DM_SCSI)
# else
# endif
#if !defined(CONFIG_DM_SCSI)
#endif
#if !defined(CONFIG_DM_SCSI)
#ifdef CONFIG_DM_PCI
#else
#endif
#else
#endif
#endif
#define MAX_DATA_BYTE_COUNT  (4*1024*1024)
#ifdef CONFIG_PHYS_64BIT
#endif
#ifdef CONFIG_SUNXI_AHCI
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_SYS_64BIT_LBA
#endif
#ifdef CONFIG_DM_SCSI
#else
#endif
#ifndef CONFIG_DM_SCSI
#ifndef CONFIG_SCSI_AHCI_PLAT
# if defined(CONFIG_DM_PCI)
# else
# endif
#else
#endif
#endif
#ifndef CONFIG_SCSI_AHCI_PLAT
# if defined(CONFIG_DM_PCI) || defined(CONFIG_DM_SCSI)
#endif
#endif
#ifdef CONFIG_SCSI_AHCI_PLAT
#ifndef CONFIG_DM_SCSI
#endif
#endif /* CONFIG_SCSI_AHCI_PLAT */
#ifdef CONFIG_DM_SCSI
#ifdef CONFIG_DM_PCI
#endif
#else
#endif
