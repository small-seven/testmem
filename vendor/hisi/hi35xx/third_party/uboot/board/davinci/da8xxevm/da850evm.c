#include <common.h>
#include <dm.h>
#include <env.h>
#include <i2c.h>
#include <net.h>
#include <spi.h>
#include <spi_flash.h>
#include <asm/arch/hardware.h>
#include <asm/ti-common/davinci_nand.h>
#include <asm/arch/emac_defs.h>
#include <asm/arch/pinmux_defs.h>
#include <asm/io.h>
#include <asm/arch/davinci_misc.h>
#include <linux/errno.h>
#include <hwconfig.h>
#include <asm/mach-types.h>
#include <asm/gpio.h>
#ifdef CONFIG_MMC_DAVINCI
#include <mmc.h>
#include <asm/arch/sdmmc_defs.h>
#endif
#ifdef CONFIG_DRIVER_TI_EMAC
#ifdef CONFIG_DRIVER_TI_EMAC_USE_RMII
#define HAS_RMII 1
#else
#define HAS_RMII 0
#endif
#endif /* CONFIG_DRIVER_TI_EMAC */
#define CFG_MAC_ADDR_SPI_BUS	0
#define CFG_MAC_ADDR_SPI_CS	0
#define CFG_MAC_ADDR_SPI_MAX_HZ	CONFIG_SF_DEFAULT_SPEED
#define CFG_MAC_ADDR_SPI_MODE	SPI_MODE_3
#define CFG_MAC_ADDR_OFFSET	(flash->size - SZ_64K)
#ifdef CONFIG_MAC_ADDR_IN_SPIFLASH
#endif
#if defined(CONFIG_MAC_ADDR_IN_SPIFLASH) || defined(CONFIG_MAC_ADDR_IN_EEPROM)
#endif
#ifdef CONFIG_MAC_ADDR_IN_SPIFLASH
#elif defined(CONFIG_MAC_ADDR_IN_EEPROM)
#endif
#ifdef CONFIG_USE_NOR
#endif
#ifdef CONFIG_MMC_DAVINCI
#endif
#ifdef CONFIG_DRIVER_TI_EMAC
#ifdef CONFIG_DRIVER_TI_EMAC_USE_RMII
#else
#endif
#endif
#ifdef CONFIG_SPI_FLASH
#endif
#ifdef CONFIG_NAND_DAVINCI
#elif defined(CONFIG_USE_NOR)
#endif
#ifdef CONFIG_MMC_DAVINCI
#endif
#ifdef CONFIG_MMC_DAVINCI
#endif
#ifndef CONFIG_DA850_EVM_MAX_CPU_CLK
#define CONFIG_DA850_EVM_MAX_CPU_CLK	300000000
#endif
#define REV_AM18X_EVM		0x100
#ifdef CONFIG_NAND_DAVINCI
#endif
#ifdef CONFIG_USE_NOR
#endif
#ifdef CONFIG_MMC_DAVINCI
#endif
#ifdef CONFIG_DRIVER_TI_EMAC
#endif /* CONFIG_DRIVER_TI_EMAC */
#ifdef CONFIG_DRIVER_TI_EMAC
#ifdef CONFIG_DRIVER_TI_EMAC_USE_RMII
#endif /* CONFIG_DRIVER_TI_EMAC_USE_RMII */
#ifdef CONFIG_DRIVER_TI_EMAC_USE_RMII
#endif
#endif /* CONFIG_DRIVER_TI_EMAC */
