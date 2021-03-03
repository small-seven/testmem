#include <los_memory.h>
#include "los_vm_iomap.h"
#include "los_vm_map.h"
#include <asm/dma.h>
#include <user_copy.h>
#include "implementation/global_implementation.h"
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_BUSDMA
usb_pc_common_mem_cb(struct usb_page_cache *pc, void *dma_handle, uint32_t length)
{
	struct usb_page *pg;
	usb_size_t rem;
	bus_size_t off;
	bus_addr_t phys = (bus_addr_t)(UINTPTR)dma_handle;

	pg = pc->page_start;
	pg->physaddr = phys & ~(USB_PAGE_SIZE - 1);
	rem = phys & (USB_PAGE_SIZE - 1);
	pc->page_offset_buf = rem;
	pc->page_offset_end += rem;
	length += rem;

	for (off = USB_PAGE_SIZE; off < length; off += USB_PAGE_SIZE) {
		pg++;
		pg->physaddr = (phys + off) & ~(USB_PAGE_SIZE - 1);
	}
}
usb_pc_alloc_mem(struct usb_page_cache *pc, struct usb_page *pg,
			    usb_size_t size, usb_size_t align)
{
	void *ptr;
	DMA_ADDR_T dma_handle;

	/* allocate zeroed memory */
	if (align < USB_CACHE_ALIGN_SIZE) {
		ptr = LOS_DmaMemAlloc(&dma_handle, size, USB_CACHE_ALIGN_SIZE, DMA_NOCACHE);
	} else {
		ptr = LOS_DmaMemAlloc(&dma_handle, size, align, DMA_NOCACHE);
	}
	if (ptr == NULL)
		goto error;

	(void)memset_s(ptr, size, 0, size);
	/* setup page cache */
	pc->buffer = (uint8_t *)ptr;
	pc->page_start = pg;
	pc->page_offset_buf = 0;
	pc->page_offset_end = size;
	pc->map = NULL;
	pc->tag = (bus_dma_tag_t)ptr;
	pc->ismultiseg = (align == 1);

	/* compute physical address */
	usb_pc_common_mem_cb(pc, (void *)(UINTPTR)dma_handle, size);

	usb_pc_cpu_flush(pc);
	return (0);

error:
	/* reset most of the page cache */
	pc->buffer = NULL;
	pc->page_start = NULL;
	pc->page_offset_buf = 0;
	pc->page_offset_end = 0;
	pc->map = NULL;
	pc->tag = NULL;
	return (1);
}
usb_pc_free_mem(struct usb_page_cache *pc)
{
	if ((pc != NULL) && (pc->buffer != NULL)) {
		LOS_DmaMemFree(pc->tag);
		pc->buffer = NULL;
	}
}
usb_pc_load_mem(struct usb_page_cache *pc, usb_size_t size, uint8_t data_sync)
{
	/* setup page cache */
	pc->page_offset_buf = 0;
	pc->page_offset_end = size;
	pc->ismultiseg = 1;

	mtx_assert(pc->tag_parent->mtx, MA_OWNED);

	if (size > 0) {
		/* compute physical address */
		usb_pc_common_mem_cb(pc, (void *)(UINTPTR)LOS_DmaVaddrToPaddr(pc->buffer), size);
	}
	if (data_sync == 0) {
		/*
		 * Call callback so that refcount is decremented
		 * properly:
		 */
		pc->tag_parent->dma_error = 0;
		(pc->tag_parent->func) (pc->tag_parent);
	}
	return (0);
}
usb_pc_dmamap_create(struct usb_page_cache *pc, usb_size_t size)
{
	return (0);	/* NOP, success */
}
usb_pc_dmamap_destroy(struct usb_page_cache *pc)
{
	/* NOP */
}
#endif
