#include <common.h>
#include <spi.h>
#include <spi_flash.h>
#include "sf_internal.h"
#if !CONFIG_IS_ENABLED(SPI_FLASH_TINY)
#define INFO_NAME(_name) .name = _name,
#else
#define INFO_NAME(_name)
#endif
#define INFO(_name, _jedec_id, _ext_id, _sector_size, _n_sectors, _flags)	\
#define INFO6(_name, _jedec_id, _ext_id, _sector_size, _n_sectors, _flags)	\
#ifdef CONFIG_SPI_FLASH_ATMEL		/* ATMEL */
#endif
#ifdef CONFIG_SPI_FLASH_EON		/* EON */
#endif
#ifdef CONFIG_SPI_FLASH_GIGADEVICE	/* GIGADEVICE */
#endif
#ifdef CONFIG_SPI_FLASH_ISSI		/* ISSI */
#endif
#ifdef CONFIG_SPI_FLASH_MACRONIX	/* MACRONIX */
#endif
#ifdef CONFIG_SPI_FLASH_STMICRO		/* STMICRO */
#endif
#ifdef CONFIG_SPI_FLASH_SPANSION	/* SPANSION */
#endif
#ifdef CONFIG_SPI_FLASH_SST		/* SST */
#endif
#ifdef CONFIG_SPI_FLASH_STMICRO		/* STMICRO */
#endif
#ifdef CONFIG_SPI_FLASH_WINBOND		/* WINBOND */
#endif
#ifdef CONFIG_SPI_FLASH_XMC
#endif
