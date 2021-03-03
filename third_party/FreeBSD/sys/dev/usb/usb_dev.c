#include "implementation/global_implementation.h"
#include "fs/fs.h"
#include <unistd.h>
#undef USB_DEBUG_VAR
#define	USB_DEBUG_VAR usb_fifo_debug
#if USB_HAVE_UGEN
#ifdef LOSCFG_USB_DEBUG
#endif
usb_fifo_alloc(struct mtx *mtx)
{
	struct usb_fifo *f;

	f = bsd_malloc(sizeof(*f), M_USBDEV, M_WAITOK | M_ZERO);
	if (f != NULL) {
		cv_init(&f->cv_io, "FIFO-IO");
		cv_init(&f->cv_drain, "FIFO-DRAIN");
		f->priv_mtx = mtx;
		f->refcount = 1;
		mtx_init(mtx, 0, 0, MTX_RECURSE);
	}
	return (f);
}
usb_fifo_create(struct usb_cdev_privdata *cpd,
    struct usb_cdev_refdata *crd)
{
	struct usb_device *udev = cpd->udev;
	struct usb_fifo *f = NULL;
	struct usb_endpoint *ep = NULL;
	uint8_t n;
	uint8_t is_tx;
	uint8_t is_rx;
	uint8_t no_null;
	uint8_t is_busy;
	int e = cpd->ep_addr;

	is_tx = ((unsigned int)cpd->fflags & FWRITE) ? 1 : 0;
	is_rx = ((unsigned int)cpd->fflags & FREAD) ? 1 : 0;
	no_null = 1;
	is_busy = 0;

	/* Preallocated FIFO */
	if (e < 0) {
		DPRINTFN(5, "Preallocated FIFO\n");
		if (is_tx) {
			f = udev->fifo[cpd->fifo_index + USB_FIFO_TX];
			if (f == NULL)
				return (EINVAL);
			crd->txfifo = f;
		}
		if (is_rx) {
			f = udev->fifo[cpd->fifo_index + USB_FIFO_RX];
			if (f == NULL)
				return (EINVAL);
			crd->rxfifo = f;
		}
		return (0);
	}

	KASSERT(e >= 0 && e <= 15, ("endpoint %d out of range", e));

	/* search for a free FIFO slot */
	DPRINTFN(5, "Endpoint device, searching for 0x%02x\n", e);
	for (n = 0;; n += 2) {

		if (n == USB_FIFO_MAX) {
			if (no_null) {
				no_null = 0;
				n = 0;
			} else {
				/* end of FIFOs reached */
				DPRINTFN(5, "out of FIFOs\n");
				return (ENOMEM);
			}
		}
		/* Check for TX FIFO */
		if (is_tx) {
			f = udev->fifo[n + USB_FIFO_TX];
			if (f != NULL) {
				if (f->dev_ep_index != e) {
					/* wrong endpoint index */
					continue;
				}
				if (f->curr_cpd != NULL) {
					/* FIFO is opened */
					is_busy = 1;
					continue;
				}
			} else if (no_null) {
				continue;
			}
		}
		/* Check for RX FIFO */
		if (is_rx) {
			f = udev->fifo[n + USB_FIFO_RX];
			if (f != NULL) {
				if (f->dev_ep_index != e) {
					/* wrong endpoint index */
					continue;
				}
				if (f->curr_cpd != NULL) {
					/* FIFO is opened */
					is_busy = 1;
					continue;
				}
			} else if (no_null) {
				continue;
			}
		}
		break;
	}

	if (no_null == 0) {
		if (e >= (USB_EP_MAX / 2)) {
			/* we don't create any endpoints in this range */
			DPRINTFN(5, "ep out of range\n");
			return (is_busy ? EBUSY : EINVAL);
		}
	}

	if ((e != 0) && is_busy) {
		/*
		 * Only the default control endpoint is allowed to be
		 * opened multiple times!
		 */
		DPRINTFN(5, "busy\n");
		return (EBUSY);
	}

	/* Check TX FIFO */
	if (is_tx &&
	    (udev->fifo[n + USB_FIFO_TX] == NULL)) {
		ep = usb_dev_get_ep(udev, e, USB_FIFO_TX);
		DPRINTFN(5, "dev_get_endpoint(%d, 0x%x)\n", e, USB_FIFO_TX);
		if (ep == NULL) {
			DPRINTFN(5, "dev_get_endpoint returned NULL\n");
			return (EINVAL);
		}
		f = usb_fifo_alloc(&udev->device_mtx);
		if (f == NULL) {
			DPRINTFN(5, "could not alloc tx fifo\n");
			return (ENOMEM);
		}
		/* update some fields */
		f->fifo_index = n + USB_FIFO_TX;
		f->dev_ep_index = e;
		f->priv_sc0 = ep;
		f->methods = &usb_ugen_methods;
		f->iface_index = ep->iface_index;
		f->udev = udev;
		mtx_lock(&usb_ref_lock);
		udev->fifo[n + USB_FIFO_TX] = f;
		mtx_unlock(&usb_ref_lock);
	}
	/* Check RX FIFO */
	if (is_rx &&
	    (udev->fifo[n + USB_FIFO_RX] == NULL)) {

		ep = usb_dev_get_ep(udev, e, USB_FIFO_RX);
		DPRINTFN(5, "dev_get_endpoint(%d, 0x%x)\n", e, USB_FIFO_RX);
		if (ep == NULL) {
			DPRINTFN(5, "dev_get_endpoint returned NULL\n");
			return (EINVAL);
		}
		f = usb_fifo_alloc(&udev->device_mtx);
		if (f == NULL) {
			DPRINTFN(5, "could not alloc rx fifo\n");
			return (ENOMEM);
		}
		/* update some fields */
		f->fifo_index = n + USB_FIFO_RX;
		f->dev_ep_index = e;
		f->priv_sc0 = ep;
		f->methods = &usb_ugen_methods;
		f->iface_index = ep->iface_index;
		f->udev = udev;
		mtx_lock(&usb_ref_lock);
		udev->fifo[n + USB_FIFO_RX] = f;
		mtx_unlock(&usb_ref_lock);
	}
	if (is_tx) {
		crd->txfifo = udev->fifo[n + USB_FIFO_TX];
	}
	if (is_rx) {
		crd->rxfifo = udev->fifo[n + USB_FIFO_RX];
	}
	/* fill out fifo index */
	DPRINTFN(5, "fifo index = %d\n", n);
	cpd->fifo_index = n;

	/* complete */

	return (0);
}
usb_fifo_free(struct usb_fifo *f)
{
	uint8_t n;

	if (f == NULL) {
		/* be NULL safe */
		return;
	}
	/* destroy symlink devices, if any */
	for (n = 0; n != 2; n++) {
		if (f->symlink[n]) {
			usb_free_symlink(f->symlink[n]);
			f->symlink[n] = NULL;
		}
	}
	mtx_lock(&usb_ref_lock);

	/* delink ourselves to stop calls from userland */
	if ((f->fifo_index < USB_FIFO_MAX) &&
	    (f->udev != NULL) &&
	    (f->udev->fifo[f->fifo_index] == f)) {
		f->udev->fifo[f->fifo_index] = NULL;
	} else {
		DPRINTFN(0, "USB FIFO %p has not been linked\n", f);
	}

	/* decrease refcount */
	f->refcount--;
	/* need to wait until all callers have exited */
	while (f->refcount != 0) {
		mtx_unlock(&usb_ref_lock);	/* avoid LOR */
		mtx_lock(f->priv_mtx);
		/* prevent write flush, if any */
		f->flag_iserror = 1;
		/* get I/O thread out of any sleep state */
		if (f->flag_sleeping) {
			f->flag_sleeping = 0;
			cv_broadcast(&f->cv_io);
		}
		mtx_unlock(f->priv_mtx);
		mtx_lock(&usb_ref_lock);

		/*
		 * Check if the "f->refcount" variable reached zero
		 * during the unlocked time before entering wait:
		 */
		if (f->refcount == 0)
			break;

		/* wait for sync */
		cv_wait(&f->cv_drain, &usb_ref_lock);
	}
	mtx_unlock(&usb_ref_lock);

	/* take care of closing the device here, if any */
	usb_fifo_close(f, 0);

	cv_destroy(&f->cv_io);
	cv_destroy(&f->cv_drain);

	bsd_free(f, M_USBDEV);
}
usb_dev_uninit(void *arg)
{
	int ret;
	mtx_destroy(&usb_ref_lock);
	sx_destroy(&usb_sym_lock);
	ret = rmdir(USB_DEVICE_DIR);
	if (ret < 0) {
		usb_err("usb rmdir error! ret = %d, errono = %d\n", ret, get_errno());
	}

}
usb_fifo_alloc_buffer(struct usb_fifo *f, usb_size_t bufsize,
    uint16_t nbuf)
{
	usb_fifo_free_buffer(f);

	/* allocate an endpoint */
	f->free_q.ifq_maxlen = nbuf;
	f->used_q.ifq_maxlen = nbuf;

	f->queue_data = usb_alloc_mbufs(
	    M_USBDEV, &f->free_q, bufsize, nbuf);

	if ((f->queue_data == NULL) && bufsize && nbuf) {
		return (ENOMEM);
	}
	return (0);			/* success */
}
usb_fifo_free_buffer(struct usb_fifo *f)
{
	if (f->queue_data) {
		/* free old buffer */
		bsd_free(f->queue_data, M_USBDEV);
		f->queue_data = NULL;
	}
	/* reset queues */

	memset(&f->free_q, 0, sizeof(f->free_q));
	memset(&f->used_q, 0, sizeof(f->used_q));
}
usb_fifo_detach(struct usb_fifo_sc *f_sc)
{
	if (f_sc == NULL) {
		return;
	}
	usb_fifo_free(f_sc->fp[USB_FIFO_TX]);
	usb_fifo_free(f_sc->fp[USB_FIFO_RX]);

	f_sc->fp[USB_FIFO_TX] = NULL;
	f_sc->fp[USB_FIFO_RX] = NULL;

	usb_destroy_dev(f_sc->dev);

	f_sc->dev = NULL;

	DPRINTFN(2, "detached %p\n", f_sc);
}
usb_alloc_symlink(const char *target)
{
	struct usb_symlink *ps = NULL;

	ps = bsd_malloc(sizeof(*ps), M_USBDEV, M_WAITOK);
	if (ps == NULL) {
		return (ps);
	}
	/* XXX no longer needed */
	strlcpy(ps->src_path, target, sizeof(ps->src_path));
	ps->src_len = strlen(ps->src_path);
	strlcpy(ps->dst_path, target, sizeof(ps->dst_path));
	ps->dst_len = strlen(ps->dst_path);

	sx_xlock(&usb_sym_lock);
	TAILQ_INSERT_TAIL(&usb_sym_head, ps, sym_entry);
	sx_xunlock(&usb_sym_lock);
	return (ps);
}
usb_free_symlink(struct usb_symlink *ps)
{
	if (ps == NULL) {
		return;
	}
	sx_xlock(&usb_sym_lock);
	TAILQ_REMOVE(&usb_sym_head, ps, sym_entry);
	sx_xunlock(&usb_sym_lock);

	bsd_free(ps, M_USBDEV);
}
#endif	/* USB_HAVE_UGEN */
