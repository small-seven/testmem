#include <common.h>
#include <dm.h>
#include <remoteproc.h>
#include <errno.h>
#include <clk.h>
#include <reset.h>
#include <asm/io.h>
#include <power-domain.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#include "ti_sci_proc.h"
#define KEYSTONE_RPROC_LOCAL_ADDRESS_MASK	(SZ_16M - 1)
static int k3_dsp_remove(struct udevice *dev)
{
	struct k3_dsp_privdata *dsp = dev_get_priv(dev);

	free(dsp->mem);

	return 0;
}
