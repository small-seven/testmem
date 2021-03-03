#define pr_fmt(fmt) "udma: " fmt
#include <common.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <asm/bitops.h>
#include <malloc.h>
#include <asm/dma-mapping.h>
#include <dm.h>
#include <dm/read.h>
#include <dm/of_access.h>
#include <dma.h>
#include <dma-uclass.h>
#include <linux/delay.h>
#include <dt-bindings/dma/k3-udma.h>
#include <linux/soc/ti/k3-navss-ringacc.h>
#include <linux/soc/ti/cppi5.h>
#include <linux/soc/ti/ti-udma.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#include "k3-udma-hwdef.h"
#if BITS_PER_LONG == 64
#define RINGACC_RING_USE_PROXY	(0)
#else
#define RINGACC_RING_USE_PROXY	(1)
#endif
#define UDMA_CH_1000(ch)		(ch * 0x1000)
#define UDMA_CH_100(ch)			(ch * 0x100)
#define UDMA_CH_40(ch)			(ch * 0x40)
#ifdef PKTBUFSRX
#define UDMA_RX_DESC_NUM PKTBUFSRX
#else
#define UDMA_RX_DESC_NUM 4
#endif
#define UDMA_RESERVE_RESOURCE(res)					\
#define UDMA_MAX_CHANNELS	192
static int *udma_prep_dma_memcpy(struct udma_chan *uc, dma_addr_t dest,
				 dma_addr_t src, size_t len)
{
	u32 tc_ring_id = k3_nav_ringacc_get_ring_id(uc->tchan->tc_ring);
	struct cppi5_tr_type15_t *tr_req;
	int num_tr;
	size_t tr_size = sizeof(struct cppi5_tr_type15_t);
	u16 tr0_cnt0, tr0_cnt1, tr1_cnt0;
	unsigned long dummy;
	void *tr_desc;
	size_t desc_size;

	if (len < SZ_64K) {
		num_tr = 1;
		tr0_cnt0 = len;
		tr0_cnt1 = 1;
	} else {
		unsigned long align_to = __ffs(src | dest);

		if (align_to > 3)
			align_to = 3;
		/*
		 * Keep simple: tr0: SZ_64K-alignment blocks,
		 *		tr1: the remaining
		 */
		num_tr = 2;
		tr0_cnt0 = (SZ_64K - BIT(align_to));
		if (len / tr0_cnt0 >= SZ_64K) {
			dev_err(uc->ud->dev, "size %zu is not supported\n",
				len);
			return NULL;
		}

		tr0_cnt1 = len / tr0_cnt0;
		tr1_cnt0 = len % tr0_cnt0;
	}

	desc_size = cppi5_trdesc_calc_size(num_tr, tr_size);
	tr_desc = dma_alloc_coherent(desc_size, &dummy);
	if (!tr_desc)
		return NULL;
	memset(tr_desc, 0, desc_size);

	cppi5_trdesc_init(tr_desc, num_tr, tr_size, 0, 0);
	cppi5_desc_set_pktids(tr_desc, uc->id, 0x3fff);
	cppi5_desc_set_retpolicy(tr_desc, 0, tc_ring_id);

	tr_req = tr_desc + tr_size;

	cppi5_tr_init(&tr_req[0].flags, CPPI5_TR_TYPE15, false, true,
		      CPPI5_TR_EVENT_SIZE_COMPLETION, 1);
	cppi5_tr_csf_set(&tr_req[0].flags, CPPI5_TR_CSF_SUPR_EVT);

	tr_req[0].addr = src;
	tr_req[0].icnt0 = tr0_cnt0;
	tr_req[0].icnt1 = tr0_cnt1;
	tr_req[0].icnt2 = 1;
	tr_req[0].icnt3 = 1;
	tr_req[0].dim1 = tr0_cnt0;

	tr_req[0].daddr = dest;
	tr_req[0].dicnt0 = tr0_cnt0;
	tr_req[0].dicnt1 = tr0_cnt1;
	tr_req[0].dicnt2 = 1;
	tr_req[0].dicnt3 = 1;
	tr_req[0].ddim1 = tr0_cnt0;

	if (num_tr == 2) {
		cppi5_tr_init(&tr_req[1].flags, CPPI5_TR_TYPE15, false, true,
			      CPPI5_TR_EVENT_SIZE_COMPLETION, 0);
		cppi5_tr_csf_set(&tr_req[1].flags, CPPI5_TR_CSF_SUPR_EVT);

		tr_req[1].addr = src + tr0_cnt1 * tr0_cnt0;
		tr_req[1].icnt0 = tr1_cnt0;
		tr_req[1].icnt1 = 1;
		tr_req[1].icnt2 = 1;
		tr_req[1].icnt3 = 1;

		tr_req[1].daddr = dest + tr0_cnt1 * tr0_cnt0;
		tr_req[1].dicnt0 = tr1_cnt0;
		tr_req[1].dicnt1 = 1;
		tr_req[1].dicnt2 = 1;
		tr_req[1].dicnt3 = 1;
	}

	cppi5_tr_csf_set(&tr_req[num_tr - 1].flags, CPPI5_TR_CSF_EOP);

	if (!udma_is_coherent(uc)) {
		flush_dcache_range((u64)tr_desc,
				   ALIGN((u64)tr_desc + desc_size,
					 ARCH_DMA_MINALIGN));
	}

	k3_nav_ringacc_ring_push(uc->tchan->t_ring, &tr_desc);

	return 0;
}
static int udma_free(struct dma *dma)
{
	struct udma_dev *ud = dev_get_priv(dma->dev);
	struct udma_chan *uc;

	if (dma->id >= (ud->rchan_cnt + ud->tchan_cnt)) {
		dev_err(dma->dev, "invalid dma ch_id %lu\n", dma->id);
		return -EINVAL;
	}
	uc = &ud->channels[dma->id];

	if (udma_is_chan_running(uc))
		udma_stop(uc);
	udma_free_chan_resources(uc);

	uc->in_use = false;

	return 0;
}
