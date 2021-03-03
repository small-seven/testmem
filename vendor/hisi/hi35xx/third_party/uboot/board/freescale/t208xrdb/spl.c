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
#include "../common/spl.h"
#if defined(CONFIG_SPL_MMC_BOOT)
#elif defined(CONFIG_SPL_SPI_BOOT)
#elif defined(CONFIG_SPL_NAND_BOOT)
#endif
#ifdef CONFIG_SPL_NAND_BOOT
#endif
#ifdef CONFIG_SPL_MMC_BOOT
#endif
#ifdef CONFIG_SPL_SPI_BOOT
#endif
#ifdef CONFIG_SPL_MMC_BOOT
#elif defined(CONFIG_SPL_SPI_BOOT)
#elif defined(CONFIG_SPL_NAND_BOOT)
#endif
