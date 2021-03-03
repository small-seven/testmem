#include <common.h>
#include <console.h>
#include <env_internal.h>
#include <malloc.h>
#include <ns16550.h>
#include <nand.h>
#include <i2c.h>
#include <mmc.h>
#include <fsl_esdhc.h>
#include <spi_flash.h>
#include "../common/sleep.h"
#include "../common/spl.h"
#define FSL_CORENET_CCSR_PORSR1_RCW_MASK	0xFF800000
#if defined(CONFIG_SPL_NAND_BOOT) && defined(CONFIG_A008044_WORKAROUND)
#endif
#if defined(CONFIG_SPL_NAND_BOOT) && defined(CONFIG_A008044_WORKAROUND)
#endif
#ifdef CONFIG_DEEP_SLEEP
#endif
#ifdef CONFIG_SPL_MMC_BOOT
#endif
#if defined(CONFIG_ENV_IS_IN_NAND) || defined(CONFIG_ENV_IS_IN_MMC) || \
#ifdef CONFIG_SPL_NAND_BOOT
#endif
#ifdef CONFIG_SPL_MMC_BOOT
#endif
#ifdef CONFIG_SPL_SPI_BOOT
#endif
#endif
#ifdef CONFIG_SPL_MMC_BOOT
#elif defined(CONFIG_SPL_SPI_BOOT)
#elif defined(CONFIG_SPL_NAND_BOOT)
#endif
