#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <spi.h>
#include <spi_flash.h>
#include "sf_internal.h"
#if CONFIG_IS_ENABLED(SPI_FLASH_MTD)
#endif
#ifndef CONFIG_DM_SPI_FLASH
void spi_flash_free(struct spi_flash *flash)
{
#if CONFIG_IS_ENABLED(SPI_FLASH_MTD)
	spi_flash_mtd_unregister();
#endif
	spi_free_slave(flash->spi);
	free(flash);
}
#else /* defined CONFIG_DM_SPI_FLASH */
static int spi_flash_std_remove(struct udevice *dev)
{
#if CONFIG_IS_ENABLED(SPI_FLASH_MTD)
	spi_flash_mtd_unregister();
#endif
	return 0;
}
#endif /* CONFIG_DM_SPI_FLASH */
