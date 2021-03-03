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
#include <asm/mach-types.h>
#if defined(CONFIG_SHOW_BOOT_PROGRESS)
#endif
#define COMP_MODE_ENABLE ((unsigned int)0x0000EAEF)
#define PCIE0_CLK_SRST_CTRL     0x3A40
#define PCIE_TST_SRST_REQ_SEL   25
#define PHY1_PORTA_CLK_SRST_CTRL        0x3B70
#define PHY1_PORTB_CLK_SRST_CTRL        0x3B90
#define PHY_TST_SRST_REQ                1
#define PHY1_PARA_SET_REG       0x1cc
#define PCIE_MODE_SHIFT         16
#define PCIE_MODE_MASK          0x7
#if (defined CONFIG_AUTO_USB_UPDATE)
#else
#endif
#ifdef CONFIG_RANDOM_ETHADDR
#endif
#if (CONFIG_AUTO_UPDATE == 1)
#endif /* CONFIG_AUTO_UPDATE */
#ifdef CONFIG_HIGMACV300_ETH
#endif
#ifdef CONFIG_GENERIC_MMC
#ifdef CONFIG_EMMC
#endif
#ifdef CONFIG_AUTO_SD_UPDATE
#endif
#endif
