#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <asm/byteorder.h>
#include <usb.h>
#include <malloc.h>
#include <asm/cache.h>
#include <linux/errno.h>
#include <usb/xhci.h>
#define CACHELINE_SIZE		CONFIG_SYS_CACHELINE_SIZE
static void xhci_segment_free(struct xhci_segment *seg)
{
	free(seg->trbs);
	seg->trbs = NULL;

	free(seg);
}
static void xhci_ring_free(struct xhci_ring *ring)
{
	struct xhci_segment *seg;
	struct xhci_segment *first_seg;

	BUG_ON(!ring);

	first_seg = ring->first_seg;
	seg = first_seg->next;
	while (seg != first_seg) {
		struct xhci_segment *next = seg->next;
		xhci_segment_free(seg);
		seg = next;
	}
	xhci_segment_free(first_seg);

	free(ring);
}
static void xhci_scratchpad_free(struct xhci_ctrl *ctrl)
{
	if (!ctrl->scratchpad)
		return;

	ctrl->dcbaa->dev_context_ptrs[0] = 0;

	free((void *)(uintptr_t)ctrl->scratchpad->sp_array[0]);
	free(ctrl->scratchpad->sp_array);
	free(ctrl->scratchpad);
	ctrl->scratchpad = NULL;
}
static void *xhci_malloc(unsigned int size)
{
	void *ptr;
	size_t cacheline_size = max(XHCI_ALIGNMENT, CACHELINE_SIZE);

	ptr = memalign(cacheline_size, ALIGN(size, cacheline_size));
	BUG_ON(!ptr);
	memset(ptr, '\0', size);

	xhci_flush_cache((uintptr_t)ptr, size);

	return ptr;
}
int xhci_mem_init(struct xhci_ctrl *ctrl, struct xhci_hccr *hccr,
					struct xhci_hcor *hcor)
{
	uint64_t val_64;
	uint64_t trb_64;
	uint32_t val;
	unsigned long deq;
	int i;
	struct xhci_segment *seg;

	/* DCBAA initialization */
	ctrl->dcbaa = (struct xhci_device_context_array *)
			xhci_malloc(sizeof(struct xhci_device_context_array));
	if (ctrl->dcbaa == NULL) {
		puts("unable to allocate DCBA\n");
		return -ENOMEM;
	}

	val_64 = (uintptr_t)ctrl->dcbaa;
	/* Set the pointer in DCBAA register */
	xhci_writeq(&hcor->or_dcbaap, val_64);

	/* Command ring control pointer register initialization */
	ctrl->cmd_ring = xhci_ring_alloc(1, true);

	/* Set the address in the Command Ring Control register */
	trb_64 = (uintptr_t)ctrl->cmd_ring->first_seg->trbs;
	val_64 = xhci_readq(&hcor->or_crcr);
	val_64 = (val_64 & (u64) CMD_RING_RSVD_BITS) |
		(trb_64 & (u64) ~CMD_RING_RSVD_BITS) |
		ctrl->cmd_ring->cycle_state;
	xhci_writeq(&hcor->or_crcr, val_64);

	/* write the address of db register */
	val = xhci_readl(&hccr->cr_dboff);
	val &= DBOFF_MASK;
	ctrl->dba = (struct xhci_doorbell_array *)((char *)hccr + val);

	/* write the address of runtime register */
	val = xhci_readl(&hccr->cr_rtsoff);
	val &= RTSOFF_MASK;
	ctrl->run_regs = (struct xhci_run_regs *)((char *)hccr + val);

	/* writting the address of ir_set structure */
	ctrl->ir_set = &ctrl->run_regs->ir_set[0];

	/* Event ring does not maintain link TRB */
	ctrl->event_ring = xhci_ring_alloc(ERST_NUM_SEGS, false);
	ctrl->erst.entries = (struct xhci_erst_entry *)
		xhci_malloc(sizeof(struct xhci_erst_entry) * ERST_NUM_SEGS);

	ctrl->erst.num_entries = ERST_NUM_SEGS;

	for (val = 0, seg = ctrl->event_ring->first_seg;
			val < ERST_NUM_SEGS;
			val++) {
		trb_64 = 0;
		trb_64 = (uintptr_t)seg->trbs;
		struct xhci_erst_entry *entry = &ctrl->erst.entries[val];
		xhci_writeq(&entry->seg_addr, trb_64);
		entry->seg_size = cpu_to_le32(TRBS_PER_SEGMENT);
		entry->rsvd = 0;
		seg = seg->next;
	}
	xhci_flush_cache((uintptr_t)ctrl->erst.entries,
			 ERST_NUM_SEGS * sizeof(struct xhci_erst_entry));

	deq = (unsigned long)ctrl->event_ring->dequeue;

	/* Update HC event ring dequeue pointer */
	xhci_writeq(&ctrl->ir_set->erst_dequeue,
				(u64)deq & (u64)~ERST_PTR_MASK);

	/* set ERST count with the number of entries in the segment table */
	val = xhci_readl(&ctrl->ir_set->erst_size);
	val &= ERST_SIZE_MASK;
	val |= ERST_NUM_SEGS;
	xhci_writel(&ctrl->ir_set->erst_size, val);

	/* this is the event ring segment table pointer */
	val_64 = xhci_readq(&ctrl->ir_set->erst_base);
	val_64 &= ERST_PTR_MASK;
	val_64 |= ((uintptr_t)(ctrl->erst.entries) & ~ERST_PTR_MASK);

	xhci_writeq(&ctrl->ir_set->erst_base, val_64);

	/* set up the scratchpad buffer array and scratchpad buffers */
	xhci_scratchpad_alloc(ctrl);

	/* initializing the virtual devices to NULL */
	for (i = 0; i < MAX_HC_SLOTS; ++i)
		ctrl->devs[i] = NULL;

	/*
	 * Just Zero'ing this register completely,
	 * or some spurious Device Notification Events
	 * might screw things here.
	 */
	xhci_writel(&hcor->or_dnctrl, 0x0);

	return 0;
}
#if CONFIG_IS_ENABLED(DM_USB)
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#endif
