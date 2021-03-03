#include "implementation/global_implementation.h"
#include "fs/fs.h"
#undef USB_DEBUG_VAR
#define USB_DEBUG_VAR   usb_debug
#if USB_HAVE_DEVCTL
#endif
#if USB_HAVE_UGEN
#endif
#ifdef	USB_TEMPLATE
#else
#endif
#if USB_HAVE_UGEN
#endif
#if USB_HAVE_UGEN
#endif
#ifdef LOSCFG_DRIVERS_USB_WIRELESS
#endif
#if USB_HAVE_UGEN
#endif
#if (USB_HAVE_FIXED_IFACE == 0)
#endif
#if (USB_HAVE_FIXED_ENDPOINT == 0)
#endif
#if (USB_HAVE_FIXED_IFACE == 0) || (USB_HAVE_FIXED_ENDPOINT == 0)
#endif
#if (USB_HAVE_FIXED_IFACE == 0)
#endif
#if (USB_HAVE_FIXED_ENDPOINT == 0)
#endif
#if USB_HAVE_UGEN
#endif
usb_detach_device_sub(struct usb_device *udev, device_t *ppdev,
    char **ppnpinfo, uint8_t flag)
{
	device_t dev;
	char *pnpinfo;
	int err;

	dev = *ppdev;

	if (dev) {
		/*
		 * NOTE: It is important to clear "*ppdev" before deleting
		 * the child due to some device methods being called late
		 * during the delete process !
		 */
		*ppdev = NULL;

		if (!rebooting) {
			device_printf(dev, "at %s, port %d, addr %d "
			    "(disconnected)\n",
			    device_get_nameunit(udev->parent_dev),
			    udev->port_no, udev->address);
		}

		if (device_is_attached(dev)) {
			if (udev->flags.peer_suspended) {
				err = DEVICE_RESUME(dev);
				if (err) {
					device_printf(dev, "Resume failed\n");
				}
			}
		}
		/* detach and delete child */
		if (device_delete_child(udev->parent_dev, dev)) {
			goto error;
		}
	}

	pnpinfo = *ppnpinfo;
	if (pnpinfo != NULL) {
		*ppnpinfo = NULL;
		bsd_free(pnpinfo, M_USBDEV);
	}
	return;

error:
	/* Detach is not allowed to fail in the USB world */
	panic("usb_detach_device_sub: A USB driver would not detach\n");
}
usb_detach_device(struct usb_device *udev, uint8_t iface_index,
    uint8_t flag)
{
	struct usb_interface *iface;
	uint8_t i;

	if (udev == NULL) {
		/* nothing to do */
		return;
	}
	DPRINTFN(4, "udev=%p\n", udev);

	sx_assert(&udev->enum_sx, SA_LOCKED);

	/*
	 * First detach the child to give the child's detach routine a
	 * chance to detach the sub-devices in the correct order.
	 * Then delete the child using "device_delete_child()" which
	 * will detach all sub-devices from the bottom and upwards!
	 */
	if (iface_index != USB_IFACE_INDEX_ANY) {
		i = iface_index;
		iface_index = i + 1;
	} else {
		i = 0;
		iface_index = USB_IFACE_MAX;
	}

	/* do the detach */

	for (; i != iface_index; i++) {

		iface = usbd_get_iface(udev, i);
		if (iface == NULL) {
			/* looks like the end of the USB interfaces */
			break;
		}
		usb_detach_device_sub(udev, &iface->subdev,
		    &iface->pnpinfo, flag);
	}
}
usb_alloc_device(device_t parent_dev, struct usb_bus *bus,
    struct usb_device *parent_hub, uint8_t depth, uint8_t port_index,
    uint8_t port_no, enum usb_dev_speed speed, enum usb_hc_mode mode)
{
	struct usb_attach_arg uaa;
	struct usb_device *udev;
	struct usb_device *adev;
	struct usb_device *hub;
	uint8_t *scratch_ptr;
	usb_error_t err;
	uint8_t device_index;
	uint8_t config_index;
	uint8_t config_quirk;
	uint8_t set_config_failed;
	uint8_t do_unlock;

	DPRINTF("parent_dev=%p, bus=%p, parent_hub=%p, depth=%u, "
	    "port_index=%u, port_no=%u, speed=%u, usb_mode=%u\n",
	    parent_dev, bus, parent_hub, depth, port_index, port_no,
	    speed, mode);

	/*
	 * Find an unused device index. In USB Host mode this is the
	 * same as the device address.
	 *
	 * Device index zero is not used and device index 1 should
	 * always be the root hub.
	 */
	for (device_index = USB_ROOT_HUB_ADDR;
	    (device_index != bus->devices_max) &&
	    (bus->devices[device_index] != NULL);
	    device_index++) /* nop */;

	if (device_index == bus->devices_max) {
		device_printf(bus->bdev,
		    "No free USB device index for new device\n");
		return (NULL);
	}

	if (depth > 0x10) {
		device_printf(bus->bdev,
		    "Invalid device depth\n");
		return (NULL);
	}
	udev = bsd_malloc(sizeof(*udev), M_USB, M_WAITOK | M_ZERO);
	if (udev == NULL) {
		return (NULL);
	}
	/* initialise our SX-lock */
	sx_init_flags(&udev->enum_sx, "USB config SX lock", SX_DUPOK);
	sx_init_flags(&udev->sr_sx, "USB suspend and resume SX lock", SX_NOWITNESS);
	sx_init_flags(&udev->ctrl_sx, "USB control transfer SX lock", SX_DUPOK);

	cv_init(&udev->ctrlreq_cv, "WCTRL");
	cv_init(&udev->ref_cv, "UGONE");

	/* initialise our mutex */
	mtx_init(&udev->device_mtx, "USB device mutex", NULL, MTX_DEF);

	/* initialise generic clear stall */
	udev->cs_msg[0].hdr.pm_callback = &usbd_clear_stall_proc;
	udev->cs_msg[0].udev = udev;
	udev->cs_msg[1].hdr.pm_callback = &usbd_clear_stall_proc;
	udev->cs_msg[1].udev = udev;

	/* initialise some USB device fields */
	udev->parent_hub = parent_hub;
	udev->parent_dev = parent_dev;
	udev->port_index = port_index;
	udev->port_no = port_no;
	udev->depth = depth;
	udev->bus = bus;
	udev->address = USB_START_ADDR;	/* default value */
	udev->plugtime = (usb_ticks_t)CUR_TICKS;
	/*
	 * We need to force the power mode to "on" because there are plenty
	 * of USB devices out there that do not work very well with
	 * automatic suspend and resume!
	 */
	udev->power_mode = usbd_filter_power_mode(udev, USB_POWER_MODE_ON);
	udev->pwr_save.last_xfer_time = CUR_TICKS;
	/* we are not ready yet */
	udev->refcount = 1;

	/* set up default endpoint descriptor */
	udev->ctrl_ep_desc.bLength = sizeof(udev->ctrl_ep_desc);
	udev->ctrl_ep_desc.bDescriptorType = UDESC_ENDPOINT;
	udev->ctrl_ep_desc.bEndpointAddress = USB_CONTROL_ENDPOINT;
	udev->ctrl_ep_desc.bmAttributes = UE_CONTROL;
	udev->ctrl_ep_desc.wMaxPacketSize[0] = USB_MAX_IPACKET;
	udev->ctrl_ep_desc.wMaxPacketSize[1] = 0;
	udev->ctrl_ep_desc.bInterval = 0;

	/* set up default endpoint companion descriptor */
	udev->ctrl_ep_comp_desc.bLength = sizeof(udev->ctrl_ep_comp_desc);
	udev->ctrl_ep_comp_desc.bDescriptorType = UDESC_ENDPOINT_SS_COMP;

	udev->ddesc.bMaxPacketSize = USB_MAX_IPACKET;

	udev->speed = speed;
	udev->flags.usb_mode = mode;

	/* search for our High Speed USB HUB, if any */

	adev = udev;
	hub = udev->parent_hub;

	while (hub) {
		if (hub->speed == USB_SPEED_HIGH) {
			udev->hs_hub_addr = hub->address;
			udev->parent_hs_hub = hub;
			udev->hs_port_no = adev->port_no;
			break;
		}
		adev = hub;
		hub = hub->parent_hub;
	}

	/* init the default endpoint */
	usb_init_endpoint(udev, 0,
	    &udev->ctrl_ep_desc,
	    &udev->ctrl_ep_comp_desc,
	    &udev->ctrl_ep);

	/* set device index */
	udev->device_index = device_index;

#if USB_HAVE_UGEN
	/* Create ugen name */
	(void)snprintf_s(udev->ugen_name, sizeof(udev->ugen_name),
	    sizeof(udev->ugen_name) - 1, USB_GENERIC_NAME "%u.%u",
	    device_get_unit(bus->bdev), device_index);
	LIST_FIRST(&udev->pd_list) = NULL;

	/* Create the control endpoint device */
	udev->ctrl_dev = usb_make_dev(udev, NULL, 0, 0,
	    FREAD|FWRITE, UID_ROOT, GID_OPERATOR, 0600);
#endif
	/* Initialise device */
	if (bus->methods->device_init != NULL) {
		err = (bus->methods->device_init) (udev);
		if (err != 0) {
			DPRINTFN(0, "device init %d failed "
			    "(%s, ignored)\n", device_index,
			    usbd_errstr(err));
			goto done;
		}
	}

	/* set powered device state after device init is complete */
	usb_set_device_state(udev, USB_STATE_POWERED);

	if (udev->flags.usb_mode == USB_MODE_HOST) {

		err = usbd_req_set_address(udev, NULL, device_index);

		/*
		 * This is the new USB device address from now on, if
		 * the set address request didn't set it already.
		 */
		if (udev->address == USB_START_ADDR)
			udev->address = device_index;
		/*
		 * We ignore any set-address errors, hence there are
		 * buggy USB devices out there that actually receive
		 * the SETUP PID, but manage to set the address before
		 * the STATUS stage is ACK'ed. If the device responds
		 * to the subsequent get-descriptor at the new
		 * address, then we know that the set-address command
		 * was successful.
		 */
		if (err) {
			DPRINTFN(0, "set address %d failed "
			    "(%s, ignored)\n", udev->address,
			    usbd_errstr(err));
		}
	} else {
		/* We are not self powered */
		udev->flags.self_powered = 0;

		/* Set unconfigured state */
		udev->curr_config_no = USB_UNCONFIG_NO;
		udev->curr_config_index = USB_UNCONFIG_INDEX;

		/* Setup USB descriptors */
		err = (usb_temp_setup_by_index_p) (udev, usb_template);
		if (err) {
			DPRINTFN(0, "setting up USB template failed maybe the USB "
			    "template module has not been loaded\n");
			goto done;
		}
	}

	usb_set_device_state(udev, USB_STATE_ADDRESSED);

	/* setup the device descriptor and the initial "wMaxPacketSize" */
	err = usbd_setup_device_desc(udev, NULL);

	if (err != 0) {
		/* try to enumerate two more times */
		err = usbd_req_re_enumerate(udev, NULL);
		if (err != 0) {
			err = usbd_req_re_enumerate(udev, NULL);
			if (err != 0) {
				goto done;
			}
		}
	}

	/*
	 * Setup temporary USB attach args so that we can figure out some
	 * basic quirks for this device.
	 */
	usb_init_attach_arg(udev, &uaa);

	if (usb_test_quirk(&uaa, UQ_BUS_POWERED)) {
		udev->flags.uq_bus_powered = 1;
	}
	if (usb_test_quirk(&uaa, UQ_NO_STRINGS)) {
		udev->flags.no_strings = 1;
	}
	/*
	 * Workaround for buggy USB devices.
	 *
	 * It appears that some string-less USB chips will crash and
	 * disappear if any attempts are made to read any string
	 * descriptors.
	 *
	 * Try to detect such chips by checking the strings in the USB
	 * device descriptor. If no strings are present there we
	 * simply disable all USB strings.
	 */

	/* Protect scratch area */
	do_unlock = usbd_ctrl_lock(udev);

	scratch_ptr = udev->scratch.data;

	if (udev->flags.no_strings) {
		err = USB_ERR_INVAL;
	} else if (udev->ddesc.iManufacturer ||
	    udev->ddesc.iProduct ||
	    udev->ddesc.iSerialNumber) {
		/* read out the language ID string */
		err = usbd_req_get_string_desc(udev, NULL,
		    (char *)scratch_ptr, 4, 0, USB_LANGUAGE_TABLE);
	} else {
		err = USB_ERR_INVAL;
	}

	if (err || (scratch_ptr[0] < 4)) {
		udev->flags.no_strings = 1;
	} else {
		uint16_t langid;
		uint16_t pref;
		uint16_t mask;
		uint8_t x;

		/* load preferred value and mask */
		pref = usb_lang_id;
		mask = usb_lang_mask;

		/* align length correctly */
		scratch_ptr[0] &= ~1U;

		/* fix compiler warning */
		langid = 0;

		/* search for preferred language */
		for (x = 2; (x < scratch_ptr[0]); x += 2) {
			langid = UGETW(scratch_ptr + x);
			if ((langid & mask) == pref)
				break;
		}
		if (x >= scratch_ptr[0]) {
			/* pick the first language as the default */
			DPRINTFN(1, "Using first language\n");
			langid = UGETW(scratch_ptr + 2);
		}

		DPRINTFN(1, "Language selected: 0x%04x\n", langid);
		udev->langid = langid;
	}

	if (do_unlock)
		usbd_ctrl_unlock(udev);

	/* assume 100mA bus powered for now. Changed when configured. */
	udev->power = USB_MIN_POWER;
	/* fetch the vendor and product strings from the device */
	usbd_set_device_strings(udev);

	if (udev->flags.usb_mode == USB_MODE_DEVICE) {
		/* USB device mode setup is complete */
		err = USB_ERR_NORMAL_COMPLETION;
		goto config_done;
	}


	/*
	 * Most USB devices should attach to config index 0 by
	 * default
	 */
	if (usb_test_quirk(&uaa, UQ_CFG_INDEX_0)) {
		config_index = 0;
		config_quirk = 1;
	} else if (usb_test_quirk(&uaa, UQ_CFG_INDEX_1)) {
		config_index = 1;
		config_quirk = 1;
	} else if (usb_test_quirk(&uaa, UQ_CFG_INDEX_2)) {
		config_index = 2;
		config_quirk = 1;
	} else if (usb_test_quirk(&uaa, UQ_CFG_INDEX_3)) {
		config_index = 3;
		config_quirk = 1;
	} else if (usb_test_quirk(&uaa, UQ_CFG_INDEX_4)) {
		config_index = 4;
		config_quirk = 1;
	} else {
		config_index = 0;
		config_quirk = 0;
	}

	set_config_failed = 0;
repeat_set_config:

	DPRINTF("setting config %u\n", config_index);

	/* get the USB device configured */
	err = usbd_set_config_index(udev, config_index);
	if (err) {
		if (udev->ddesc.bNumConfigurations != 0) {
			if (!set_config_failed) {
				set_config_failed = 1;
				/* XXX try to re-enumerate the device */
				err = usbd_req_re_enumerate(udev, NULL);
				if (err == 0)
					goto repeat_set_config;
			}
			DPRINTFN(0, "Failure selecting configuration index %u:"
			    "%s, port %u, addr %u (ignored)\n",
			    config_index, usbd_errstr(err), udev->port_no,
			    udev->address);
		}
		/*
		 * Some USB devices do not have any configurations. Ignore any
		 * set config failures!
		 */
		err = USB_ERR_NORMAL_COMPLETION;
		goto config_done;
	}
	if ((!config_quirk) && (config_index + 1 < udev->ddesc.bNumConfigurations)) {
		if ((udev->cdesc->bNumInterface < 2) &&
		    (usbd_get_no_descriptors(udev->cdesc, UDESC_ENDPOINT) == 0)) {
			DPRINTFN(0, "Found no endpoints, trying next config\n");
			config_index++;
			goto repeat_set_config;
		}
	}

config_done:
	DPRINTF("new dev (addr %d), udev=%p, parent_hub=%p\n",
	    udev->address, udev, udev->parent_hub);

	/* register our device - we are ready */
	usb_bus_port_set_device(bus, parent_hub ?
	    (parent_hub->hub->ports + port_index) : NULL, udev, device_index);

#if USB_HAVE_UGEN
	/* Symlink the ugen device name */
	udev->ugen_symlink = usb_alloc_symlink(udev->ugen_name);

	/* Announce device */
	PRINTK("%s: <%s> at %s\n", udev->ugen_name,
	    usb_get_manufacturer(udev),
	    device_get_nameunit(udev->bus->bdev));
#endif

#if USB_HAVE_DEVCTL
	usb_notify_addq("ATTACH", udev);
#endif
done:
	if (err) {
		/*
		 * Free USB device and all subdevices, if any.
		 */
		usb_free_device(udev, 0);
		udev = NULL;
	}
	return (udev);
}
#if USB_HAVE_UGEN
usb_destroy_dev(struct usb_fs_privdata *pd)
{
	int ret;

	if (pd == NULL)
		return;

	ret = unregister_driver(pd->cdev_name);
	if (ret < 0) {
		usb_err("unregister_driver() failed: %d\n", ret);
		return;
	}

	bsd_free(pd, M_USBDEV);
}
usb_cdev_create(struct usb_device *udev)
{
	struct usb_config_descriptor *cd;
	struct usb_endpoint_descriptor *ed;
	struct usb_descriptor *desc;
	struct usb_fs_privdata* pd;
	int inmode, outmode, inmask, outmask, mode;
	uint8_t ep;

	KASSERT(LIST_FIRST(&udev->pd_list) == NULL, ("stale cdev entries"));

	DPRINTFN(2, "Creating device nodes\n");

	if (usbd_get_mode(udev) == USB_MODE_DEVICE) {
		inmode = FWRITE;
		outmode = FREAD;
	} else {		 /* USB_MODE_HOST */
		inmode = FREAD;
		outmode = FWRITE;
	}

	inmask = 0;
	outmask = 0;
	desc = NULL;

	/*
	 * Collect all used endpoint numbers instead of just
	 * generating 16 static endpoints.
	 */
	cd = usbd_get_config_descriptor(udev);
	while ((desc = usb_desc_foreach(cd, desc))) {
		/* filter out all endpoint descriptors */
		if ((desc->bDescriptorType == UDESC_ENDPOINT) &&
		    (desc->bLength >= sizeof(*ed))) {
			ed = (struct usb_endpoint_descriptor *)desc;

			/* update masks */
			ep = ed->bEndpointAddress;
			if (UE_GET_DIR(ep)  == UE_DIR_OUT)
				outmask = (unsigned int)outmask | (1 << UE_GET_ADDR(ep));
			else
				inmask = (unsigned int)inmask | (1 << UE_GET_ADDR(ep));
		}
	}

	/* Create all available endpoints except EP0 */
	for (ep = 1; ep < 16; ep++) {
		mode = ((unsigned int)inmask & (1 << ep)) ? inmode : 0;
		mode = (unsigned int)mode | (((unsigned int)outmask & (1 << ep)) ? outmode : 0);
		if (mode == 0)
			continue;	/* no IN or OUT endpoint */

		pd = usb_make_dev(udev, NULL, ep, 0,
		    mode, UID_ROOT, GID_OPERATOR, 0600);

		if (pd != NULL)
			LIST_INSERT_HEAD(&udev->pd_list, pd, pd_next);
	}
}
usb_cdev_free(struct usb_device *udev)
{
	struct usb_fs_privdata* pd;

	DPRINTFN(2, "Freeing device nodes\n");

	while ((pd = LIST_FIRST(&udev->pd_list)) != NULL) {
		//KASSERT(pd->cdev->si_drv1 == pd, ("privdata corrupt"));

		LIST_REMOVE(pd, pd_next);

		usb_destroy_dev(pd);
	}
}
#endif
usb_free_device(struct usb_device *udev, uint8_t flag)
{
	struct usb_bus *bus;

	if (udev == NULL)
		return;		/* already freed */

	DPRINTFN(4, "udev=%p port=%d\n", udev, udev->port_no);

	bus = udev->bus;

	/* set DETACHED state to prevent any further references */
	usb_set_device_state(udev, USB_STATE_DETACHED);

#if USB_HAVE_DEVCTL
	usb_notify_addq("DETACH", udev);
#endif

#if USB_HAVE_UGEN
	if (!rebooting) {
		PRINTK("%s: <%s> at %s (disconnected)\n", udev->ugen_name,
		    usb_get_manufacturer(udev), device_get_nameunit(bus->bdev));
	}

	/* Destroy UGEN symlink, if any */
	if (udev->ugen_symlink) {
		usb_free_symlink(udev->ugen_symlink);
		udev->ugen_symlink = NULL;
	}

	usb_destroy_dev(udev->ctrl_dev);
#endif

	if (udev->flags.usb_mode == USB_MODE_DEVICE) {
		/* stop receiving any control transfers (Device Side Mode) */
		usbd_transfer_unsetup(udev->ctrl_xfer, USB_CTRL_XFER_MAX);
	}

	/* the following will get the device unconfigured in software */
	usb_unconfigure(udev, USB_UNCFG_FLAG_FREE_EP0);

	/* final device unregister after all character devices are closed */
	usb_bus_port_set_device(bus, udev->parent_hub ?
	    (udev->parent_hub->hub->ports + udev->port_index) : NULL,
	    NULL, USB_ROOT_HUB_ADDR);

	/* unsetup any leftover default USB transfers */
	usbd_transfer_unsetup(udev->ctrl_xfer, USB_CTRL_XFER_MAX);

	/* template unsetup, if any */
	(usb_temp_unsetup_p) (udev);

	/*
	 * Make sure that our clear-stall messages are not queued
	 * anywhere:
	 */
	USB_BUS_LOCK(udev->bus);
	usb_proc_mwait(USB_BUS_CS_PROC(udev->bus),
	    &udev->cs_msg[0], &udev->cs_msg[1]);
	USB_BUS_UNLOCK(udev->bus);

	/* wait for all references to go away */
	usb_wait_pending_refs(udev);

	sx_destroy(&udev->enum_sx);
	sx_destroy(&udev->sr_sx);
	sx_destroy(&udev->ctrl_sx);

	cv_destroy(&udev->ctrlreq_cv);
	cv_destroy(&udev->ref_cv);

	mtx_destroy(&udev->device_mtx);
#if USB_HAVE_UGEN
	KASSERT(LIST_FIRST(&udev->pd_list) == NULL, ("leaked cdev entries"));
#endif

	/* Uninitialise device */
	if (bus->methods->device_uninit != NULL)
		(bus->methods->device_uninit) (udev);

	/* free device */
	bsd_free(udev->serial, M_USB);
	udev->serial = NULL;
	bsd_free(udev->manufacturer, M_USB);
	udev->manufacturer = NULL;
	bsd_free(udev->product, M_USB);
	udev->product = NULL;
	bsd_free(udev, M_USB);
}
#ifdef USB_VERBOSE
#define	USB_KNOWNDEV_NOPROD	0x01	/* match on vendor only */
#include "implementation/usbdevs.h"
#include "usbdevs_data.h"
#endif					/* USB_VERBOSE */
#ifdef USB_VERBOSE
#endif
#ifdef USB_VERBOSE
#endif
#if USB_HAVE_DEVCTL
#if USB_HAVE_UGEN
#endif
#if USB_HAVE_UGEN
#endif
#if USB_HAVE_UGEN
#endif
#if USB_HAVE_UGEN
#endif
#if USB_HAVE_UGEN
#endif
#if USB_HAVE_UGEN
#endif
#endif
#if USB_HAVE_UGEN
usb_fifo_free_wrap(struct usb_device *udev,
    uint8_t iface_index, uint8_t flag)
{
	struct usb_fifo *f;
	uint16_t i;

	/*
	 * Free any USB FIFOs on the given interface:
	 */
	for (i = 0; i != USB_FIFO_MAX; i++) {
		f = udev->fifo[i];
		if (f == NULL) {
			continue;
		}
		/* Check if the interface index matches */
		if (iface_index == f->iface_index) {
			if (f->methods != &usb_ugen_methods) {
				/*
				 * Don't free any non-generic FIFOs in
				 * this case.
				 */
				continue;
			}
			if ((f->dev_ep_index == 0) &&
			    (f->fs_xfer == NULL)) {
				/* no need to free this FIFO */
				continue;
			}
		} else if (iface_index == USB_IFACE_INDEX_ANY) {
			if ((f->methods == &usb_ugen_methods) &&
			    (f->dev_ep_index == 0) &&
			    (!(flag & USB_UNCFG_FLAG_FREE_EP0)) &&
			    (f->fs_xfer == NULL)) {
				/* no need to free this FIFO */
				continue;
			}
		} else {
			/* no need to free this FIFO */
			continue;
		}
		/* free this FIFO */
		usb_fifo_free(f);
	}
}
#endif
#if USB_HAVE_UGEN
#endif
#if USB_HAVE_UGEN
#endif
#undef USB_DEBUG_VAR
