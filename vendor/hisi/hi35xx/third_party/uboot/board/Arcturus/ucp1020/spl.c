#include <common.h>
#include <console.h>
#include <env.h>
#include <env_internal.h>
#include <ns16550.h>
#include <malloc.h>
#include <mmc.h>
#include <nand.h>
#include <i2c.h>
#include <fsl_esdhc.h>
#include <spi_flash.h>
#ifdef CONFIG_SPL_SPI_BOOT
#endif
#ifdef CONFIG_SPL_MMC_BOOT
#elif defined(CONFIG_SPL_SPI_BOOT)
#endif
#ifndef CONFIG_SPL_NAND_BOOT
#endif
#ifdef CONFIG_SPL_MMC_BOOT
#endif
#ifdef CONFIG_SPL_NAND_BOOT
#else
#endif
#ifdef CONFIG_SYS_I2C
#else
#endif
#ifdef CONFIG_SPL_NAND_BOOT
#else
#endif
#ifdef CONFIG_SPL_MMC_BOOT
#elif defined(CONFIG_SPL_NAND_BOOT)
#endif
