#ifndef __UBOOT__
#include <linux/dmaengine.h>
#include <linux/pm_runtime.h>
#include "internals.h"
#else
#include <spi.h>
#include <spi-mem.h>
#endif
#ifndef __UBOOT__
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
static int spi_mem_remove(struct spi_device *spi)
{
	struct spi_mem_driver *memdrv = to_spi_mem_drv(spi->dev.driver);
	struct spi_mem *mem = spi_get_drvdata(spi);

	if (memdrv->remove)
		return memdrv->remove(mem);

	return 0;
}
#endif /* __UBOOT__ */
