#include "implementation/global_implementation.h"
#undef USB_DEBUG_VAR
#define	USB_DEBUG_VAR usb_debug
#if USB_HAVE_BUSDMA
usbd_transfer_setup_sub_malloc(struct usb_setup_params *parm,
    struct usb_page_cache **ppc, usb_size_t size, usb_size_t align,
    usb_size_t count)
{
	struct usb_page_cache *pc;
	struct usb_page *pg;
	void *buf;
	usb_size_t n_dma_pc;
	usb_size_t n_dma_pg;
	usb_size_t n_obj;
	usb_size_t x;
	usb_size_t y;
	usb_size_t r;
	usb_size_t z;

	USB_ASSERT(align > 0, ("Invalid alignment, 0x%08x\n",
	    align));
	USB_ASSERT(size > 0, ("Invalid size = 0\n"));

	if (count == 0) {
		return (0);		/* nothing to allocate */
	}
	/*
	 * Make sure that the size is aligned properly.
	 */
	size = -((-size) & (-align));

	/*
	 * Try multi-allocation chunks to reduce the number of DMA
	 * allocations, hence DMA allocations are slow.
	 */
	if (align == 1) {
		/* special case - non-cached multi page DMA memory */
		n_dma_pc = count;
		n_dma_pg = (2 + (size / USB_PAGE_SIZE));
		n_obj = 1;
	} else if (size >= USB_PAGE_SIZE) {
		n_dma_pc = count;
		n_dma_pg = 1;
		n_obj = 1;
	} else {
		/* compute number of objects per page */
		n_obj = (USB_PAGE_SIZE / size);
		/*
		 * Compute number of DMA chunks, rounded up
		 * to nearest one:
		 */
		n_dma_pc = ((count + n_obj - 1) / n_obj);
		n_dma_pg = 1;
	}

	/*
	 * DMA memory is allocated once, but mapped twice. That's why
	 * there is one list for auto-free and another list for
	 * non-auto-free which only holds the mapping and not the
	 * allocation.
	 */
	if (parm->buf == NULL) {
		/* reserve memory (auto-free) */
		parm->dma_page_ptr += n_dma_pc * n_dma_pg;
		parm->dma_page_cache_ptr += n_dma_pc;

		/* reserve memory (no-auto-free) */
		parm->dma_page_ptr += count * n_dma_pg;
		parm->xfer_page_cache_ptr += count;
		return (0);
	}
	for (x = 0; x != n_dma_pc; x++) {
		/* need to initialize the page cache */
		parm->dma_page_cache_ptr[x].tag_parent =
		    &parm->curr_xfer->xroot->dma_parent_tag;
	}
	for (x = 0; x != count; x++) {
		/* need to initialize the page cache */
		parm->xfer_page_cache_ptr[x].tag_parent =
		    &parm->curr_xfer->xroot->dma_parent_tag;
	}

	if (ppc != NULL) {
		*ppc = parm->xfer_page_cache_ptr;
	}
	r = count;			/* set remainder count */
	z = n_obj * size;		/* set allocation size */
	pc = parm->xfer_page_cache_ptr;
	pg = parm->dma_page_ptr;

	for (x = 0; x != n_dma_pc; x++) {

		if (r < n_obj) {
			/* compute last remainder */
			z = r * size;
			n_obj = r;
		}
		if (usb_pc_alloc_mem(parm->dma_page_cache_ptr,
		    pg, z, align)) {
			return (1);	/* failure */
		}
		/* Set beginning of current buffer */
		buf = parm->dma_page_cache_ptr->buffer;
		/* Make room for one DMA page cache and one page */
		parm->dma_page_cache_ptr++;
		pg += n_dma_pg;

		for (y = 0; (y != n_obj); y++, r--, pc++, pg += n_dma_pg) {

			/* Load sub-chunk into DMA */
			if (usb_pc_dmamap_create(pc, size)) {
				return (1);	/* failure */
			}
			pc->buffer = USB_ADD_BYTES(buf, y * size);
			pc->page_start = pg;

			mtx_lock(pc->tag_parent->mtx);
			(void)usb_pc_load_mem(pc, size, 1 /* synchronous */ );
			mtx_unlock(pc->tag_parent->mtx);
		}
	}

	parm->xfer_page_cache_ptr = pc;
	parm->dma_page_ptr = pg;
	return (0);
}
#endif
#if USB_HAVE_BUSDMA
#else
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_BUSDMA
#endif
#ifdef LOSCFG_USB_DEBUG
#endif
#if USB_HAVE_POWERD
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_POWERD
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_PF
#endif
#if USB_HAVE_BUSDMA
#endif
#if USB_HAVE_PF
#endif
#if USB_HAVE_TT_SUPPORT
#endif
#undef USB_DEBUG_VAR
