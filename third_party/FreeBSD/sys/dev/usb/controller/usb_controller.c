#include "implementation/global_implementation.h"
#if USB_HAVE_DEVICE_TOPOLOGY
#include "implementation/usb_btree.h"
#endif
#undef	USB_DEBUG_VAR
#define	USB_DEBUG_VAR   usb_ctrl_debug
#ifdef LOSCFG_USB_DEBUG
#endif
#if USB_HAVE_ROOT_MOUNT_HOLD
#endif
#if USB_HAVE_DEVICE_TOPOLOGY
#endif
#if USB_HAVE_DEVICE_TOPOLOGY
#endif
#if USB_HAVE_ROOT_MOUNT_HOLD
#endif
#if USB_HAVE_DEVICE_TOPOLOGY
#endif
usb_detach(device_t dev)
{
	struct usb_bus *bus = (struct usb_bus *)device_get_softc(dev);

	DPRINTF("\n");

	if (bus == NULL) {
		/* was never setup properly */
		return (0);
	}
	/* Stop power watchdog */
	callout_drain(&bus->power_wdog);

#if USB_HAVE_ROOT_MOUNT_HOLD
	/* Let the USB explore process detach all devices. */
	usb_root_mount_rel(bus);
#endif

	USB_BUS_LOCK(bus);

	/* Queue detach job */
	(void)usb_proc_msignal(USB_BUS_EXPLORE_PROC(bus),
	    &bus->detach_msg[0], &bus->detach_msg[1]);

	/* Wait for detach to complete */
	usb_proc_mwait(USB_BUS_EXPLORE_PROC(bus),
	    &bus->detach_msg[0], &bus->detach_msg[1]);

	USB_BUS_UNLOCK(bus);

#if USB_HAVE_PER_BUS_PROCESS
	/* Get rid of USB callback processes */

	usb_proc_free(USB_BUS_GIANT_PROC(bus));
	usb_proc_free(USB_BUS_NON_GIANT_ISOC_PROC(bus));
	usb_proc_free(USB_BUS_NON_GIANT_BULK_PROC(bus));

	/* Get rid of USB explore process */

	usb_proc_free(USB_BUS_EXPLORE_PROC(bus));

	/* Get rid of control transfer process */

	usb_proc_free(USB_BUS_CONTROL_XFER_PROC(bus));
#endif

#if USB_HAVE_PF
	usbpf_detach(bus);
#endif

#if USB_HAVE_DEVICE_TOPOLOGY
	usbd_free_bt_node(hub_tree);
	hub_tree = NULL;
#endif

	return (0);
}
#ifdef DDB
#endif
#if USB_HAVE_POWERD
#endif
#if USB_HAVE_ROOT_MOUNT_HOLD
#endif
usb_bus_detach(struct usb_proc_msg *pm)
{
	struct usb_bus *bus;
	struct usb_device *udev;
	device_t dev;

	bus = ((struct usb_bus_msg *)pm)->bus;
	udev = bus->devices[USB_ROOT_HUB_ADDR];
	dev = bus->bdev;
	/* clear the softc */
	device_set_softc(dev, NULL);
	USB_BUS_UNLOCK(bus);

	/* detach children first */
	mtx_lock(&Giant);
	(void)bus_generic_detach(dev);
	mtx_unlock(&Giant);

	/*
	 * Free USB device and all subdevices, if any.
	 */
	usb_free_device(udev, 0);

	USB_BUS_LOCK(bus);
	/* clear bdev variable last */
	bus->bdev = NULL;
}
#if USB_HAVE_ROOT_MOUNT_HOLD
#endif
#if USB_HAVE_ROOT_MOUNT_HOLD
#endif
#if USB_HAVE_PF
#endif
#if USB_HAVE_PER_BUS_PROCESS
#endif
#if USB_HAVE_BUSDMA
usb_bus_mem_flush_all_cb(struct usb_bus *bus, struct usb_page_cache *pc,
    struct usb_page *pg, usb_size_t nsize, usb_size_t align)
{
	usb_pc_cpu_flush(pc);
}
#endif
#if USB_HAVE_BUSDMA
usb_bus_mem_flush_all(struct usb_bus *bus, usb_bus_mem_cb_t *cb)
{
	if (cb) {
		cb(bus, &usb_bus_mem_flush_all_cb);
	}
}
#endif
#if USB_HAVE_BUSDMA
usb_bus_mem_alloc_all_cb(struct usb_bus *bus, struct usb_page_cache *pc,
    struct usb_page *pg, usb_size_t nsize, usb_size_t align)
{
	/* need to initialize the page cache */
	pc->tag_parent = bus->dma_parent_tag;

	if (usb_pc_alloc_mem(pc, pg, nsize, align)) {
		bus->alloc_failed = 1;
	}
}
#endif
usb_bus_mem_alloc_all(struct usb_bus *bus, bus_dma_tag_t dmat,
    usb_bus_mem_cb_t *cb)
{
	bus->alloc_failed = 0;

	mtx_init(&bus->bus_mtx, device_get_nameunit(bus->parent),
	    "usb_def_mtx", MTX_DEF | MTX_RECURSE);

	mtx_init(&bus->bus_spin_lock, device_get_nameunit(bus->parent),
	    "usb_spin_mtx", MTX_SPIN | MTX_RECURSE);

	callout_init_mtx(&bus->power_wdog,
	    &bus->bus_mtx, 0);

	TAILQ_INIT(&bus->intr_q.head);

#if USB_HAVE_BUSDMA
	usb_dma_tag_setup(bus->dma_parent_tag, bus->dma_tags,
	    dmat, &bus->bus_mtx, NULL, bus->dma_bits, USB_BUS_DMA_TAG_MAX);
#endif
	if ((bus->devices_max > USB_MAX_DEVICES) ||
	    (bus->devices_max < USB_MIN_DEVICES) ||
	    (bus->devices == NULL)) {
		DPRINTFN(0, "Devices field has not been "
		    "initialised properly\n");
		bus->alloc_failed = 1;		/* failure */
	}
#if USB_HAVE_BUSDMA
	if (cb) {
		cb(bus, &usb_bus_mem_alloc_all_cb);
	}
#endif
	if (bus->alloc_failed) {
		usb_bus_mem_free_all(bus, cb);
	}
	return (bus->alloc_failed);
}
#if USB_HAVE_BUSDMA
usb_bus_mem_free_all_cb(struct usb_bus *bus, struct usb_page_cache *pc,
    struct usb_page *pg, usb_size_t nsize, usb_size_t align)
{
	usb_pc_free_mem(pc);
}
#endif
usb_bus_mem_free_all(struct usb_bus *bus, usb_bus_mem_cb_t *cb)
{
#if USB_HAVE_BUSDMA
	if (cb) {
		cb(bus, &usb_bus_mem_free_all_cb);
	}
	usb_dma_tag_unsetup(bus->dma_parent_tag);
#endif

	mtx_destroy(&bus->bus_mtx);
	mtx_destroy(&bus->bus_spin_lock);
}
#undef	USB_DEBUG_VAR
