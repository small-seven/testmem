#include <common.h>
#include <dm.h>
#include <errno.h>
#include <memalign.h>
#include <asm/io.h>
#include <pci.h>
#include <miiphy.h>
#include "fsl_enetc.h"
static int enetc_remove(struct udevice *dev)
{
	struct enetc_priv *priv = dev_get_priv(dev);

	free(priv->enetc_txbd);
	free(priv->enetc_rxbd);

	return 0;
}
