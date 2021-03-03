#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <dm/read.h>
#include <dma-uclass.h>
#include <dt-structs.h>
#include <errno.h>
#ifdef CONFIG_DMA_CHANNELS
# if CONFIG_IS_ENABLED(OF_CONTROL)
# endif /* OF_CONTROL */
int dma_free(struct dma *dma)
{
	struct dma_ops *ops = dma_dev_ops(dma->dev);

	debug("%s(dma=%p)\n", __func__, dma);

	if (!ops->free)
		return 0;

	return ops->free(dma);
}
#endif /* CONFIG_DMA_CHANNELS */
int dma_memcpy(void *dst, void *src, size_t len)
{
	struct udevice *dev;
	const struct dma_ops *ops;
	int ret;

	ret = dma_get_device(DMA_SUPPORTS_MEM_TO_MEM, &dev);
	if (ret < 0)
		return ret;

	ops = device_get_ops(dev);
	if (!ops->transfer)
		return -ENOSYS;

	/* Invalidate the area, so no writeback into the RAM races with DMA */
	invalidate_dcache_range((unsigned long)dst, (unsigned long)dst +
				roundup(len, ARCH_DMA_MINALIGN));

	return ops->transfer(dev, DMA_MEM_TO_MEM, dst, src, len);
}
