#include <common.h>
#include <dm.h>
#include <errno.h>
#include <pci.h>
#include <usb.h>
#include <asm/io.h>
#include "ohci.h"
static int ohci_pci_remove(struct udevice *dev)
{
	return ohci_deregister(dev);
}
