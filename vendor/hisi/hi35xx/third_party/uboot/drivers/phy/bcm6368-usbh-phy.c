#include <common.h>
#include <clk.h>
#include <dm.h>
#include <generic-phy.h>
#include <power-domain.h>
#include <reset.h>
#include <asm/io.h>
#include <dm/device.h>
#define USBH_PLL_REG		0x18
#define USBH_PLL_IDDQ_PWRDN	BIT(9)
#define USBH_PLL_PWRDN_DELAY	BIT(10)
#define USBH_SWAP_REG		0x1c
#define USBH_SWAP_OHCI_DATA	BIT(0)
#define USBH_SWAP_OHCI_ENDIAN	BIT(1)
#define USBH_SWAP_EHCI_DATA	BIT(3)
#define USBH_SWAP_EHCI_ENDIAN	BIT(4)
#define USBH_SETUP_REG		0x28
#define USBH_SETUP_IOC		BIT(4)
#define USBH_SETUP_IPP		BIT(5)
#if defined(CONFIG_POWER_DOMAIN)
#endif
#if defined(CONFIG_POWER_DOMAIN)
#endif
