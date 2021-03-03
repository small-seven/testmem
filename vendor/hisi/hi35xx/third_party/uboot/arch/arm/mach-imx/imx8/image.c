#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <mmc.h>
#include <spi_flash.h>
#include <nand.h>
#include <asm/arch/image.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/boot_mode.h>
#define MMC_DEV		0
#define QSPI_DEV	1
#define NAND_DEV	2
#define QSPI_NOR_DEV	3
#ifdef CONFIG_SPL_MMC_SUPPORT
#endif
#ifdef CONFIG_SPL_SPI_LOAD
#endif
#ifdef CONFIG_SPL_NAND_SUPPORT
#endif
#ifdef CONFIG_SPL_NOR_SUPPORT
#endif
#ifdef CONFIG_SPL_SPI_LOAD
#endif
#ifdef CONFIG_SPL_MMC_SUPPORT
#endif
#ifdef CONFIG_SPL_NAND_SUPPORT
#endif
#ifdef CONFIG_SPL_NOR_SUPPORT
#endif
