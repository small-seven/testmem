#include <common.h>
#include <dm.h>
#include <generic-phy.h>
#include <reset.h>
#include <asm/io.h>
#include <dm/device.h>
#define USBH_SWAP_REG		0x00
#define USBH_SWAP_OHCI_DATA	BIT(0)
#define USBH_SWAP_OHCI_ENDIAN	BIT(1)
#define USBH_SWAP_EHCI_DATA	BIT(3)
#define USBH_SWAP_EHCI_ENDIAN	BIT(4)
#define USBH_TEST_REG		0x24
#define USBH_TEST_PORT_CTL	0x1c0020
