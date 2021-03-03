#include <common.h>
#include <axi.h>
#include <dm.h>
static int sandbox_store_remove(struct udevice *dev)
{
	struct sandbox_store_priv *priv = dev_get_priv(dev);

	free(priv->store);

	return 0;
}
