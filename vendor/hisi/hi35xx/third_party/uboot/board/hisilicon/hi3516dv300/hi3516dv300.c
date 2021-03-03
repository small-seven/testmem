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
#include <hicpu_common.h>
#include <asm/mach-types.h>
#include <cpu_func.h>
#ifndef CONFIG_SYS_DCACHE_OFF
#endif
#if defined(CONFIG_SHOW_BOOT_PROGRESS)
#endif
#define COMP_MODE_ENABLE ((unsigned int)0x0000EAEF)
#define UBOOT_DATA_ADDR     0x81000000UL
#define UBOOT_DATA_SIZE     0x80000UL
#if defined(CONFIG_HIFMC)
#endif
#if defined(CONFIG_SUPPORT_EMMC_BOOT)
#endif
#define REG_BASE_GPIO0          0x120d0000
#define GPIO0_0_DATA_OFST       0x4
#define GPIO_DIR_OFST           0x400
#if (defined CONFIG_AUTO_SD_UPDATE) || (defined CONFIG_AUTO_USB_UPDATE)
#else
#endif
#ifdef CONFIG_RANDOM_ETHADDR
#endif
#if (CONFIG_AUTO_UPDATE == 1)
#ifdef CFG_MMU_HANDLEOK
#endif
#ifdef CFG_MMU_HANDLEOK
#endif
#endif
#if (CONFIG_AUTO_UPDATE == 1)
#endif
#ifdef CONFIG_HISFV300_ETH
#endif
#ifdef CONFIG_GENERIC_MMC
#ifdef CONFIG_SUPPORT_EMMC_BOOT
#endif
#ifdef CONFIG_AUTO_SD_UPDATE
#endif
#endif
#ifdef CONFIG_ARMV7_NONSEC
#endif
