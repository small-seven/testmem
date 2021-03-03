#include <common.h>
#include <asm/io.h>
#include <linux/types.h>
#include <linux/bitops.h>
#include <linux/soc/ti/k3-sec-proxy.h>
#include <dm.h>
#include <mailbox-uclass.h>
#define RT_THREAD_STATUS			0x0
#define RT_THREAD_THRESHOLD			0x4
#define RT_THREAD_STATUS_ERROR_SHIFT		31
#define RT_THREAD_STATUS_ERROR_MASK		BIT(31)
#define RT_THREAD_STATUS_CUR_CNT_SHIFT		0
#define RT_THREAD_STATUS_CUR_CNT_MASK		GENMASK(7, 0)
#define SCFG_THREAD_CTRL			0x1000
#define SCFG_THREAD_CTRL_DIR_SHIFT		31
#define SCFG_THREAD_CTRL_DIR_MASK		BIT(31)
#define SEC_PROXY_THREAD(base, x)		((base) + (0x1000 * (x)))
#define THREAD_IS_RX				1
#define THREAD_IS_TX				0
static int k3_sec_proxy_free(struct mbox_chan *chan)
{
	debug("%s(chan=%p)\n", __func__, chan);

	return 0;
}
static int k3_sec_proxy_remove(struct udevice *dev)
{
	struct k3_sec_proxy_mbox *spm = dev_get_priv(dev);

	debug("%s(dev=%p)\n", __func__, dev);

	free(spm->chans);

	return 0;
}
