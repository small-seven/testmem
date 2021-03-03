#include <common.h>
#include <usb.h>
#include <usb/ulpi.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/ehci.h>
#include <asm/ehci-omap.h>
#include "ehci.h"
#ifdef CONFIG_USB_ULPI
#else
#endif
#if defined(CONFIG_OMAP_EHCI_PHY1_RESET_GPIO) || \
#ifdef CONFIG_OMAP_EHCI_PHY1_RESET_GPIO
#endif
#ifdef CONFIG_OMAP_EHCI_PHY2_RESET_GPIO
#endif
#ifdef CONFIG_OMAP_EHCI_PHY3_RESET_GPIO
#endif
#else
#define omap_ehci_phy_reset(on, delay)	do {} while (0)
#endif
