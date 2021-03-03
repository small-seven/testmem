#include "implementation/global_implementation.h"
usb_alloc_mbufs(struct malloc_type *type, struct usb_ifqueue *ifq,
    usb_size_t block_size, uint16_t nblocks)
{
	struct usb_mbuf *m_ptr;
	uint8_t *data_ptr;
	void *free_ptr = NULL;
	usb_size_t alloc_size;

	/* align data */
	block_size += ((-block_size) & (USB_HOST_ALIGN - 1));

	if (nblocks && block_size) {

		alloc_size = (block_size + sizeof(struct usb_mbuf)) * nblocks;

		free_ptr = zalloc(alloc_size);

		if (free_ptr == NULL) {
			goto done;
		}
		m_ptr = free_ptr;
		data_ptr = (void *)(m_ptr + nblocks);

		while (nblocks--) {

			m_ptr->cur_data_ptr =
			    m_ptr->min_data_ptr = data_ptr;

			m_ptr->cur_data_len =
			    m_ptr->max_data_len = block_size;

			USB_IF_ENQUEUE(ifq, m_ptr);

			m_ptr++;
			data_ptr += block_size;
		}
	}
done:
	return (free_ptr);
}
