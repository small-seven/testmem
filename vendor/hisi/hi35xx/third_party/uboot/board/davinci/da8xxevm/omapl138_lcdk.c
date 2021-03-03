#include <common.h>
#include <env.h>
#include <i2c.h>
#include <net.h>
#include <asm/arch/hardware.h>
#include <asm/ti-common/davinci_nand.h>
#include <asm/io.h>
#include <ns16550.h>
#include <dm/platdata.h>
#include <linux/errno.h>
#include <asm/mach-types.h>
#include <asm/arch/davinci_misc.h>
#ifdef CONFIG_MMC_DAVINCI
#include <mmc.h>
#include <asm/arch/sdmmc_defs.h>
#endif
#define pinmux(x)	(&davinci_syscfg_regs->pinmux[x])
#ifdef CONFIG_MMC_DAVINCI
#endif
#ifdef CONFIG_DRIVER_TI_EMAC
#endif /* CONFIG_DRIVER_TI_EMAC */
#ifdef CONFIG_NAND_DAVINCI
#endif
#ifdef CONFIG_DRIVER_TI_EMAC_USE_RMII
#define HAS_RMII 1
#else
#define HAS_RMII 0
#endif
#ifdef CONFIG_NAND_DAVINCI
#endif
#ifdef CONFIG_MMC_DAVINCI
#endif
#ifndef CONFIG_DA850_EVM_MAX_CPU_CLK
#define CONFIG_DA850_EVM_MAX_CPU_CLK	456000000
#endif
#ifdef CONFIG_NAND_DAVINCI
#endif
#ifdef CONFIG_MMC_DAVINCI
#endif
#ifdef CONFIG_DRIVER_TI_EMAC
#endif /* CONFIG_DRIVER_TI_EMAC */
#define CFG_MAC_ADDR_SPI_BUS	0
#define CFG_MAC_ADDR_SPI_CS	0
#define CFG_MAC_ADDR_SPI_MAX_HZ	CONFIG_SF_DEFAULT_SPEED
#define CFG_MAC_ADDR_SPI_MODE	SPI_MODE_3
#define CFG_MAC_ADDR_OFFSET	(flash->size - SZ_64K)
#ifdef CONFIG_DRIVER_TI_EMAC_USE_RMII
#endif /* CONFIG_DRIVER_TI_EMAC_USE_RMII */
#ifdef CONFIG_DRIVER_TI_EMAC_USE_RMII
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#ifdef CONFIG_MMC_DAVINCI
#endif
#endif
#ifdef CONFIG_SPL_BUILD
#endif
