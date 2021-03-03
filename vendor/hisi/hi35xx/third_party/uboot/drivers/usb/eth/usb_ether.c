#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <usb.h>
#include <dm/device-internal.h>
#include "usb_ether.h"
#ifdef CONFIG_DM_ETH
#define USB_BULK_RECV_TIMEOUT 500
#else
typedef void (*usb_eth_before_probe)(void);
typedef int (*usb_eth_probe)(struct usb_device *dev, unsigned int ifnum,
			struct ueth_data *ss);
typedef int (*usb_eth_get_info)(struct usb_device *dev, struct ueth_data *ss,
			struct eth_device *dev_desc);

struct usb_eth_prob_dev {
	usb_eth_before_probe	before_probe; /* optional */
	usb_eth_probe			probe;
	usb_eth_get_info		get_info;
};
#ifdef CONFIG_USB_ETHER_ASIX
#endif
#ifdef CONFIG_USB_ETHER_ASIX88179
#endif
#ifdef CONFIG_USB_ETHER_MCS7830
#endif
#ifdef CONFIG_USB_ETHER_SMSC95XX
#endif
#ifdef CONFIG_USB_ETHER_RTL8152
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#else
#endif
#endif
