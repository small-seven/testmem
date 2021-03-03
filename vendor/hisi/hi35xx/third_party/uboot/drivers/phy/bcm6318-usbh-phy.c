#include <common.h>
#include <clk.h>
#include <dm.h>
#include <generic-phy.h>
#include <power-domain.h>
#include <reset.h>
#include <asm/io.h>
#include <dm/device.h>
#define USBH_SETUP_REG		0x00
#define USBH_SETUP_IOC		BIT(4)
#define USBH_PLL_REG		0x04
#define USBH_PLL_SUSP_EN	BIT(27)
#define USBH_PLL_IDDQ_PWRDN	BIT(31)
#define USBH_SWAP_REG		0x0c
#define USBH_SWAP_OHCI_DATA	BIT(0)
#define USBH_SWAP_OHCI_ENDIAN	BIT(1)
#define USBH_SWAP_EHCI_DATA	BIT(3)
#define USBH_SWAP_EHCI_ENDIAN	BIT(4)
#define USBH_SIM_REG		0x20
#define USBH_SIM_LADDR		BIT(5)
