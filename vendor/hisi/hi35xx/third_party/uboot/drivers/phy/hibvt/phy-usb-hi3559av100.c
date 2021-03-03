#include <asm/arch-hi3559av100/platform.h>
#include <dm.h>
#include <usb.h>
#include <usb/xhci.h>
#include "phy-hisi-usb.h"
#define SYS_STAT			0x8c
#define COMBPHY_MODE_MASK	(0x3 << 0)
#define PCIE_X2				(0x0 << 0)
#define PCIE_X1				(0x1 << 0)
#define USB3				(0x2 << 0)
#define USB_PORT0			0x38
#define P0_U3_PORT_DISABLE	(0x1 << 3)
#define USB_PORT1			0x3c
#define P1_U3_PORT_DISABLE	(0x1 << 3)
#define USB2_PHY_MASK			(0xf << 4)
#define PORT_CAP_DIR			(0x3 << 12)
#define PORT_SET_HOST			(0x1 << 12)
#define PORT_DISABLE_SUSPEND	(0x1 << 17)
#define XHCI_USB3OFFSET			16
#define COMBPHY_MODE_REG_OFFSET	12
