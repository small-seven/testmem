#define LOG_CATEGORY UCLASS_SPI_FLASH
#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <spi.h>
#include <os.h>
#include <spi_flash.h>
#include "sf_internal.h"
#include <asm/getopt.h>
#include <asm/spi.h>
#include <asm/state.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/uclass-internal.h>
#if CONFIG_IS_ENABLED(LOG)
#endif /* LOG */
#define STAT_WIP	(1 << 0)
#define STAT_WEL	(1 << 1)
#define STAT_BP_SHIFT	2
#define STAT_BP_MASK	(7 << STAT_BP_SHIFT)
#define SF_ADDR_LEN	3
#define IDCODE_LEN 3
static int sandbox_sf_remove(struct udevice *dev)
{
	struct sandbox_spi_flash *sbsf = dev_get_priv(dev);

	os_close(sbsf->fd);

	return 0;
}
#ifdef CONFIG_SPI_FLASH
#endif
