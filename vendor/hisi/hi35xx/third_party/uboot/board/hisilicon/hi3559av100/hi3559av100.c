#include "../../../lib/hw_dec/hw_decompress_v2.h"
#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <asm/arch/platform.h>
#include <spi_flash.h>
#include <linux/mtd/mtd.h>
#include <nand.h>
#include <netdev.h>
#include <mmc.h>
#include <sdhci.h>
#include <asm/armv8/mmu.h>
#include <command.h>
#include <hicpu_common.h>
#include <cpu_func.h>
#include <asm/mach-types.h>
#if defined(CONFIG_SHOW_BOOT_PROGRESS)
#endif
#define COMP_MODE_ENABLE ((unsigned int)0x0000EAEF)
#define UBOOT_DATA_ADDR     0x41000000UL
#define UBOOT_DATA_SIZE     0x80000UL
#if defined(CONFIG_HIFMC)
#endif
#if defined(CONFIG_MMC)
#endif
#define REG_BASE_GPIO0          0x12140000
#define GPIO0_0_DATA_OFST       0x4
#define GPIO_DIR_OFST       0x400
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
#endif /* CONFIG_AUTO_UPDATE */
#if (CONFIG_AUTO_UPDATE == 1)
#endif /* CONFIG_AUTO_UPDATE */
#ifdef CONFIG_HIGMACV300_ETH
#endif
#ifdef CONFIG_GENERIC_MMC
#ifdef CONFIG_MMC_PHY
#endif
#ifdef CONFIG_EMMC
#endif
#ifdef CONFIG_AUTO_SD_UPDATE
#endif
#endif
#define PMC_REG_BASE     0x180c0000
#define SENSOR_HUB_CRG_0 0x18020000
#define SENSOR_HUB_CRG_1 0x18020004
#define SENSOR_HUB_CRG_2 0x18020008
#define SENSOR_HUB_CRG_3 0x1802000C
#define SENSOR_HUB_CRG_4 0x18020010
#define SENSOR_HUB_CRG_11 0x1802002c
#define HEAD_SIZE   0X10
#define COMPRESSED_SIZE_OFFSET      0X0
#define UNCOMPRESSED_SIZE_OFFSET    0X4
#define HEAD_MAGIC_NUM0 0X70697A67 /* 'g''z''i''p' */
#define HEAD_MAGIC_NUM0_OFFSET 0X8
#define HEAD_MAGIC_NUM1 0X64616568 /* 'h''e''a''d' */
#define HEAD_MAGIC_NUM1_OFFSET 0XC
