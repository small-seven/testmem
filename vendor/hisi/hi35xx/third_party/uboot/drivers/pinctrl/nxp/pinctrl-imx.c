#include <common.h>
#include <mapmem.h>
#include <linux/io.h>
#include <linux/err.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include "pinctrl-imx.h"
int imx_pinctrl_remove(struct udevice *dev)
{
	struct imx_pinctrl_priv *priv = dev_get_priv(dev);
	struct imx_pinctrl_soc_info *info = priv->info;

	if (info->flags & IMX8_USE_SCU)
		return 0;

	if (info->input_sel_base)
		unmap_sysmem(info->input_sel_base);
	if (info->base)
		unmap_sysmem(info->base);

	return 0;
}
