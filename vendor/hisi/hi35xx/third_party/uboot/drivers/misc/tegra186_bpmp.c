#include <common.h>
#include <dm.h>
#include <time.h>
#include <dm/lists.h>
#include <dm/root.h>
#include <mailbox.h>
#include <misc.h>
#include <asm/arch-tegra/bpmp_abi.h>
#include <asm/arch-tegra/ivc.h>
#define BPMP_IVC_FRAME_COUNT 1
#define BPMP_IVC_FRAME_SIZE 128
#define BPMP_FLAG_DO_ACK	BIT(0)
#define BPMP_FLAG_RING_DOORBELL	BIT(1)
static int tegra186_bpmp_remove(struct udevice *dev)
{
	struct tegra186_bpmp *priv = dev_get_priv(dev);

	debug("%s(dev=%p) (priv=%p)\n", __func__, dev, priv);

	mbox_free(&priv->mbox);

	return 0;
}
