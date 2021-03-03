#include <common.h>
#include <dm.h>
#include <spi.h>
#include <spi_flash.h>
#include <dm/device-internal.h>
#include "sf_internal.h"
void spi_flash_free(struct spi_flash *flash)
{
	device_remove(flash->spi->dev, DM_REMOVE_NORMAL);
}
#if defined(CONFIG_SPL_BUILD) && CONFIG_IS_ENABLED(USE_TINY_PRINTF)
#else
#endif
#if defined(CONFIG_NEEDS_MANUAL_RELOC)
#endif
