#include <common.h>
#include <asm/io.h>
#include <malloc.h>
#include <asm/dma-mapping.h>
#include <asm/bitops.h>
#include <dm.h>
#include <dm/read.h>
#include <dm/uclass.h>
#include <linux/compat.h>
#include <linux/soc/ti/k3-navss-ringacc.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#define set_bit(bit, bitmap)	__set_bit(bit, bitmap)
#define clear_bit(bit, bitmap)	__clear_bit(bit, bitmap)
#define dma_free_coherent(dev, size, cpu_addr, dma_handle) \
#define dma_zalloc_coherent(dev, size, dma_handle, flag) \
#define KNAV_RINGACC_CFG_RING_SIZE_ELCNT_MASK		GENMASK(19, 0)
#define KNAV_RINGACC_RT_REGS_STEP	0x1000
#define K3_RINGACC_PROXY_CFG_THREADS_MASK		GENMASK(15, 0)
#define K3_RINGACC_PROXY_TARGET_STEP	0x1000
#define K3_RINGACC_PROXY_NOT_USED	(-1)
#define KNAV_RINGACC_FIFO_WINDOW_SIZE_BYTES  (512U)
#define KNAV_RINGACC_FIFO_REGS_STEP	0x1000
#define KNAV_RINGACC_MAX_DB_RING_CNT    (127U)
#define KNAV_RING_FLAG_BUSY	BIT(1)
#define K3_NAV_RING_FLAG_SHARED	BIT(2)
int k3_nav_ringacc_ring_free(struct k3_nav_ring *ring)
{
	struct k3_nav_ringacc *ringacc;

	if (!ring)
		return -EINVAL;

	ringacc = ring->parent;

	pr_debug("%s flags: 0x%08x\n", __func__, ring->flags);

	if (!test_bit(ring->ring_id, ringacc->rings_inuse))
		return -EINVAL;

	if (--ring->use_count)
		goto out;

	if (!(ring->flags & KNAV_RING_FLAG_BUSY))
		goto no_init;

	k3_ringacc_ring_free_sci(ring);

	dma_free_coherent(ringacc->dev,
			  ring->size * (4 << ring->elm_size),
			  ring->ring_mem_virt, ring->ring_mem_dma);
	ring->flags &= ~KNAV_RING_FLAG_BUSY;
	ring->ops = NULL;
	if (ring->proxy_id != K3_RINGACC_PROXY_NOT_USED) {
		clear_bit(ring->proxy_id, ringacc->proxy_inuse);
		ring->proxy = NULL;
		ring->proxy_id = K3_RINGACC_PROXY_NOT_USED;
	}

no_init:
	clear_bit(ring->ring_id, ringacc->rings_inuse);

	module_put(ringacc->dev->driver->owner);

out:
	return 0;
}
u32 k3_nav_ringacc_ring_get_free(struct k3_nav_ring *ring)
{
	if (!ring || !(ring->flags & KNAV_RING_FLAG_BUSY))
		return -EINVAL;

	if (!ring->free)
		ring->free = ring->size - ringacc_readl(&ring->rt->occ);

	return ring->free;
}
