#include <common.h>
#include <asm/io.h>
#include <usb.h>
#include <usb/fusbh200.h>
#include <usb/fotg210.h>
#include "ehci.h"
#ifndef CONFIG_USB_EHCI_BASE_LIST
#define CONFIG_USB_EHCI_BASE_LIST	{ CONFIG_USB_EHCI_BASE }
#endif
