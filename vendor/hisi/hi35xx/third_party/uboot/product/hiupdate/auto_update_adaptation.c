#include <common.h>
#include <command.h>
#include <malloc.h>
#include <image.h>
#include <asm/byteorder.h>
#include <asm/io.h>
#include <spi_flash.h>
#include <linux/mtd/mtd.h>
#include <fat.h>
#include <console.h>
#include <mmc.h>
#include <sparse_format.h>
#include <linux/kernel.h>
#include <nand.h>
#if (CONFIG_AUTO_UPDATE == 1)  /* cover the whole file */
#ifdef CONFIG_AUTO_SD_UPDATE
#ifndef CONFIG_MMC
#error "should have defined CONFIG_MMC"
#endif
#include <mmc.h>
#include "mmc_init.c"
#endif
#if defined CONFIG_AUTO_USB_UPDATE
#ifndef CONFIG_HISI_MC
#if !defined CONFIG_USB_OHCI && !defined CONFIG_USB_XHCI_HCD
#error "should have defined CONFIG_USB_OHCI or CONFIG_USB_XHCI"
#endif
#endif
#ifndef CONFIG_USB_STORAGE
#error "should have defined CONFIG_USB_STORAGE"
#endif
#include <usb.h>
#include "usb_init.c"
#endif
#include "../../fs/ext4/unsparse.h"
#undef AU_DEBUG
#undef debug_print
#ifdef  AU_DEBUG
#define debug_print(fmt, args...) printf(fmt, ##args)
#else
#define debug_print(fmt, args...)
#endif  /* AU_DEBUG */
#define AU_CONFIG   "config"
#define CONFIG_MAX_SIZE  	2048
#define BLOCK_SIZE           	512
#define STR_LEN			80
#define LINE			16
#define EMMC_BLOCK_SHIFT	9
#define NAME_LEN		20
#define SIZE_M			(1024 * 1024)
#define SIZE_K			1024
#define DECI_VALUE		10
#define STR_STEPS		2
#define PERCENT_VALUE		100
#define STOR_DEV_OFFSET		16
#define STOR_DEV_MASK		0x03
#define STOR_PART		18
#define STOR_PART_MASK		0x1f
#ifdef CONFIG_HISI_UPGRADE_BY_SEGMENT
#define SECTION_SIZE         0x1000000UL   /* 16M  */
#define BLOCK_SIZE           512
#define DEFAULT_BLOCK_SIZE   4096
#define CHUNK_HEAD_SIZE      12
#define BOUNDARY             (DEFAULT_BLOCK_SIZE + CHUNK_HEAD_SIZE)
#define HEX_DUMP_LEN         128
#endif
#define AU_FIRMWARE "u-boot.bin"
#define AU_KERNEL   "kernel"
#include "nand.h"
#if defined(CONFIG_CMD_SF) || defined(CONFIG_CMD_NAND)
#endif
#ifdef CONFIG_CMD_SF
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_SUPPORT_EMMC_BOOT
#ifndef CONFIG_HISI_UPGRADE_BY_SEGMENT
#endif
#endif
#define UPDATE_MEDIUM_SPINOR 0
#define UPDATE_MEDIUM_NAND   1
#define UPDATE_MEDIUM_EMMC   2
#ifdef CONFIG_CMD_SF
#else
#endif
#ifdef CONFIG_CMD_NAND
#else
#endif
#ifdef CONFIG_SUPPORT_EMMC_BOOT
#ifndef CONFIG_HISI_UPGRADE_BY_SEGMENT
#else
#endif
#endif
#define MAX_UPDATE_INTF 3
#ifdef CONFIG_AUTO_SD_UPDATE
#endif
#ifdef CONFIG_AUTO_USB_UPDATE
#endif
#define IDX_FIRMWARE    0
#define IDX_KERNEL  1
#define IDX_ROOTFS  2
#define AU_MAXFILES 32
#define NAME_MAX_LEN 0x20
#ifdef CONFIG_HISI_UPGRADE_BY_SEGMENT
typedef struct buff_layout {
	unsigned long offset;  /* chunk header offset in next buffer */
	u32 count;      /* chunk header count */
	u32 remain;    /* remain add offset equals chunk_len */
	u32 len;      /* all the data length we need to handle in buffer */
	u32 type;    /* the last chunk type */
	u8  flag;   /* 0: filesize < SECTION_SIZE 1: filesize > SECTION_SIZE */
} buff_layout_t;
#if (defined CONFIG_EMMC) || (defined CONFIG_CMD_UFS)
#endif
#endif
#if 	defined(CONFIG_TARGET_HI3559AV100) || defined(CONFIG_TARGET_HI3516EV200) || \
#define LOAD_ADDR ((unsigned char *)0x42000000)
#elif 	defined(CONFIG_TARGET_HI3519AV100) || defined(CONFIG_TARGET_HI3556AV100)
#define LOAD_ADDR ((unsigned char *)0x22000000)
#else
#define LOAD_ADDR ((unsigned char *)0x83000000)
#endif
#define MAX_LOADSZ ausize[IDX_ROOTFS]
#ifdef CONFIG_HISI_UPGRADE_BY_SEGMENT
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_CMD_NAND
#endif
#endif
#ifndef CONFIG_HISI_UPGRADE_BY_SEGMENT
#else
#endif
#ifndef CONFIG_HISI_UPGRADE_BY_SEGMENT
#else
#if (defined CONFIG_EMMC) || (defined CONFIG_CMD_UFS)
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifndef CONFIG_CMD_NAND
#endif
#if (defined CONFIG_EMMC) || (defined CONFIG_CMD_UFS)
#endif
#if (defined CONFIG_EMMC) || (defined CONFIG_CMD_UFS)
#else
#endif
#endif
#define ENV_MAX_LEN    (CONFIG_MAX_SIZE / 2)
#ifdef CONFIG_EMMC
#endif
#if 	(defined CONFIG_TARGET_HI3519AV100) || (defined CONFIG_TARGET_HI3556AV100) || \
#else
#endif
#ifdef CONFIG_EMMC
#else
#endif
#ifdef CONFIG_EMMC
#endif
#endif /* CONFIG_AUTO_UPDATE */
