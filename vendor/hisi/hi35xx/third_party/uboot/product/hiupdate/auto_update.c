#include <common.h>
#include <environment.h>
#include <command.h>
#include <malloc.h>
#include <image.h>
#include <asm/byteorder.h>
#include <asm/io.h>
#include <spi_flash.h>
#include <linux/mtd/mtd.h>
#include <fat.h>
#if (CONFIG_AUTO_UPDATE == 1)  /* cover the whole file */
#ifdef CONFIG_AUTO_SD_UPDATE
#ifndef CONFIG_MMC
#error "should have defined CONFIG_MMC"
#endif
#include <mmc.h>
#include "mmc_init.c"
#endif
#if defined CONFIG_AUTO_USB_UPDATE
#if !defined CONFIG_USB_OHCI && !defined CONFIG_USB_XHCI
#error "should have defined CONFIG_USB_OHCI or CONFIG_USB_XHCI"
#endif
#ifndef CONFIG_USB_STORAGE
#error "should have defined CONFIG_USB_STORAGE"
#endif
#include <usb.h>
#include "usb_init.c"
#endif
#undef AU_DEBUG
#undef debug
#ifdef  AU_DEBUG
#define debug(fmt, args...) printf(fmt, ##args)
#else
#define debug(fmt, args...)
#endif  /* AU_DEBUG */
#define AU_FIRMWARE "u-boot"
#define AU_KERNEL   "kernel"
#define AU_ROOTFS   "rootfs"
#define NAME_LEN	20
#define ENV_LEN		20
#define PERCENT		100
#define HEX		16
#define COUNT		3
#define MMC2		2
#define MAX_HZ		1000000UL
#define SPI_MODE3	3
#define MAX_UPDATE_INTF 3
#ifdef CONFIG_AUTO_SD_UPDATE
#endif
#ifdef CONFIG_AUTO_USB_UPDATE
#endif
#define AU_FL_FIRMWARE_ST   0x0
#define AU_FL_FIRMWARE_ND   0x7FFFF
#define AU_FL_KERNEL_ST     0x100000
#define AU_FL_KERNEL_ND     0x5FFFFF
#define AU_FL_ROOTFS_ST     0x600000
#define AU_FL_ROOTFS_ND     0xbFFFFF
#define IDX_FIRMWARE    0
#define IDX_KERNEL  1
#define IDX_ROOTFS  2
#define AU_MAXFILES 3
#if defined(CONFIG_HI3559AV100ES)
#define LOAD_ADDR ((unsigned char *)0x42000000)
#else
#define LOAD_ADDR ((unsigned char *)0x82000000)
#endif
#define MAX_LOADSZ ausize[IDX_ROOTFS]
#undef CHECK_VALID_DEBUG
#ifdef CHECK_VALID_DEBUG
#endif
#if (defined CONFIG_ARCH_HI3559AV100ES)
#endif
#endif /* CONFIG_AUTO_UPDATE */
