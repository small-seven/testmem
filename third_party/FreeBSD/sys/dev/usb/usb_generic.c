#include "implementation/global_implementation.h"
#if USB_HAVE_UGEN
#define	UGEN_BULK_FS_BUFFER_SIZE	(64*32)	/* bytes */
#define	UGEN_BULK_HS_BUFFER_SIZE	(1024*32)	/* bytes */
#define	UGEN_HW_FRAMES	50		/* number of milliseconds per transfer */
#if (USB_HAVE_FIXED_CONFIG == 0)
#else
#endif
ugen_fs_uninit(struct usb_fifo *f)
{
	if (f->fs_xfer == NULL) {
		return (EINVAL);
	}
	usbd_transfer_unsetup(f->fs_xfer, f->fs_ep_max);
	bsd_free(f->fs_xfer, M_USB);
	f->fs_xfer = NULL;
	f->fs_ep_max = 0;
	f->fs_ep_ptr = NULL;
	f->flag_iscomplete = 0;
	usb_fifo_free_buffer(f);
	return (0);
}
#if USB_HAVE_POWERD
#endif
#if USB_HAVE_POWERD
#endif
#endif	/* USB_HAVE_UGEN */
