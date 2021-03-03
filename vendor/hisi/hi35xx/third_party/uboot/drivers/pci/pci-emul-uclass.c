#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <linux/libfdt.h>
#include <pci.h>
#include <dm/lists.h>
static int sandbox_pci_emul_pre_remove(struct udevice *dev)
{
	struct sandbox_pci_emul_priv *priv = dev->uclass->priv;

	priv->dev_count--;
	sandbox_set_enable_pci_map(priv->dev_count > 0);

	return 0;
}
