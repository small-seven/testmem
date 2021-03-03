#include <common.h>
#include <config.h>
#include <spl.h>
#include <asm/u-boot.h>
#include <asm/utils.h>
#include <nand.h>
#include <asm/arch/dm365_lowlevel.h>
#include <ns16550.h>
#include <malloc.h>
#include <spi_flash.h>
#include <mmc.h>
#ifndef CONFIG_SPL_LIBCOMMON_SUPPORT
#endif /* CONFIG_SPL_LIBCOMMON_SUPPORT */
#ifdef CONFIG_SPL_NAND_SUPPORT
#endif
#ifdef CONFIG_SPL_MMC_SUPPORT
#endif
#ifdef CONFIG_SPL_SPI_FLASH_SUPPORT
#endif
