#include <common.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/log2.h>
#include <linux/math64.h>
#include <linux/sizes.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/spi-nor.h>
#include <spi-mem.h>
#include <spi.h>
#include "sf_internal.h"
#define HZ					CONFIG_SYS_HZ
#define DEFAULT_READY_WAIT_JIFFIES		(40UL * HZ)
#if defined(CONFIG_SPI_FLASH_SPANSION) || defined(CONFIG_SPI_FLASH_WINBOND)
#endif
#if defined(CONFIG_SPI_FLASH_SPANSION) ||	\
#endif /* CONFIG_SPI_FLASH_SPANSION */
#ifdef CONFIG_SPI_FLASH_MACRONIX
#endif
#if defined(CONFIG_SPI_FLASH_SPANSION) || defined(CONFIG_SPI_FLASH_WINBOND)
#endif /* CONFIG_SPI_FLASH_SPANSION */
#ifdef CONFIG_SPI_FLASH_MACRONIX
#endif
#if defined(CONFIG_SPI_FLASH_SPANSION) || defined(CONFIG_SPI_FLASH_WINBOND)
#endif
