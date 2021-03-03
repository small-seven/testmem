#include <common.h>
#include <dm.h>
#include <dm/read.h>
#include <dma-uclass.h>
#include <dt-structs.h>
#include <errno.h>
#define SANDBOX_DMA_CH_CNT 3
#define SANDBOX_DMA_BUF_SIZE 1024
static int sandbox_dma_free(struct dma *dma)
{
	struct sandbox_dma_dev *ud = dev_get_priv(dma->dev);
	struct sandbox_dma_chan *uc;

	if (dma->id >= SANDBOX_DMA_CH_CNT)
		return -EINVAL;

	uc = &ud->channels[dma->id];
	if (!uc->in_use)
		return -EINVAL;

	uc->in_use = false;
	ud->buf_rx = NULL;
	ud->data_len = 0;
	debug("%s(dma id=%lu in_use=%d)\n", __func__, dma->id, uc->in_use);

	return 0;
}
