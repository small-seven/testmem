#include "usb_init.h"
#include "usb_api_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
typedef struct usb_info {
	bool b_init;
	controller_type ctype;
	device_type dtype;
} usb_info_t;
#ifdef LOSCFG_DRIVERS_USB_HOST_EHCI
#endif
#if defined (LOSCFG_DRIVERS_USB_HOST_XHCI)
#endif
#ifdef LOSCFG_DRIVERS_USB_HOST_DRIVER
#endif
#ifdef LOSCFG_DRIVERS_USB_4G_MODEM
#endif
#if defined (LOSCFG_DRIVERS_USB_SERIAL) || defined (LOSCFG_DRIVERS_USB_4G_MODEM)
#endif
#ifdef LOSCFG_DRIVERS_USB_MASS_STORAGE
#endif
#ifdef LOSCFG_DRIVERS_USB_ETHERNET
#endif
#ifdef LOSCFG_DRIVERS_USB_RNDIS_HOST
#endif
#ifdef LOSCFG_DRIVERS_USB_WIRELESS
#endif
#ifdef LOSCFG_DRIVERS_USB_HID_CLASS
#endif
#ifdef LOSCFG_DRIVERS_USB
#endif
#ifdef LOSCFG_USB_DEBUG
#endif
#ifdef LOSCFG_USB_DEBUG
#endif
#ifdef LOSCFG_DRIVERS_USB
#endif
#if defined (LOSCFG_DRIVERS_USB_HOST_XHCI)
#endif
#ifdef LOSCFG_DRIVERS_USB_HOST_EHCI
#endif
usb_deinit(void)
{
	uint32_t ret = LOS_OK;

	dprintf("******** %s in **********\n\n", __FUNCTION__);
	mtx_lock(&usb_mtx);

	if (usb_info.b_init == false) {
		dprintf("******** %s out, no init **********\n\n", __FUNCTION__);
		goto err;
	}

	if (usb_info.ctype == HOST) {
		dprintf("******** %s fail, host not support **********\n\n", __FUNCTION__);
		goto err;
	}

	if (ret) {
		dprintf("******** %s fail, %d **********\n\n", __FUNCTION__, ret);
		goto err;
	}

	usb_dev_uninit(NULL);

	dprintf(" ** %s uninit success **\n", dev_name_get());
	usbinfo_clean();
	mtx_unlock(&usb_mtx);
	return (LOS_OK);

err:
	mtx_unlock(&usb_mtx);
	return (LOS_NOK);
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
