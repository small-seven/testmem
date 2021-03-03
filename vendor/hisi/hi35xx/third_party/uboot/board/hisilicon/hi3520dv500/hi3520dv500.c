#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <asm/arch/platform.h>
#include <spi_flash.h>
#include <linux/mtd/mtd.h>
#include <nand.h>
#include <netdev.h>
#include <mmc.h>
#include <asm/sections.h>
#include <sdhci.h>
#include <hicpu_common.h>
#include <asm/mach-types.h>
#ifndef CONFIG_SYS_DCACHE_OFF
#endif
#if defined(CONFIG_SHOW_BOOT_PROGRESS)
#endif
#define COMP_MODE_ENABLE ((unsigned int)0x0000EAEF)
#if (defined CONFIG_AUTO_USB_UPDATE)
#else
#endif
#ifdef CONFIG_RANDOM_ETHADDR
#endif
#if (CONFIG_AUTO_UPDATE == 1)
#endif
#ifdef CONFIG_HISFV300_ETH
#endif
#ifdef CONFIG_GENERIC_MMC
#ifdef CONFIG_HISI_SDHCI
#ifdef CONFIG_EMMC
#endif
#ifdef CONFIG_AUTO_SD_UPDATE
#endif
#endif
#endif
#ifdef CONFIG_ARMV7_NONSEC
#endif
