#include <common.h>
#include <clk.h>
#include <dm.h>
#include <fdtdec.h>
#include <malloc.h>
#include <reset.h>
#include <spi.h>
#include <linux/errno.h>
#include "cadence_qspi.h"
#define CQSPI_STIG_READ			0
#define CQSPI_STIG_WRITE		1
#define CQSPI_INDIRECT_READ		2
#define CQSPI_INDIRECT_WRITE		3
static int cadence_spi_remove(struct udevice *dev)
{
	struct cadence_spi_priv *priv = dev_get_priv(dev);

	return reset_release_bulk(&priv->resets);
}
#ifdef CONFIG_CQSPI_REF_CLK
#else
#endif
