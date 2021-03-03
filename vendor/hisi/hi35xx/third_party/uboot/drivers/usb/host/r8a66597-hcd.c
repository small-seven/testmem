#include <common.h>
#include <console.h>
#include <dm.h>
#include <usb.h>
#include <asm/io.h>
#include <linux/iopoll.h>
#include <power/regulator.h>
#include "r8a66597.h"
#ifdef R8A66597_DEBUG
#define R8A66597_DPRINT		printf
#else
#define R8A66597_DPRINT(...)
#endif
#if (CONFIG_R8A66597_XTAL == 1)
#endif
#include <usbroothubdes.h>
static int r8a66597_usb_remove(struct udevice *dev)
{
	struct r8a66597 *priv = dev_get_priv(dev);
	int ret;

	disable_controller(priv);

	if (CONFIG_IS_ENABLED(DM_REGULATOR)) {
		ret = regulator_set_enable(priv->vbus_supply, false);
		if (ret) {
			dev_err(dev,
				"can't disable VBUS supply\n");
			return ret;
		}
	}

	return 0;
}
