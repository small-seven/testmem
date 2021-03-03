#include <common.h>
#include <dm.h>
#include <ns16550.h>
#include <serial.h>
#include <asm/io.h>
#include <asm/omap_musb.h>
#include <asm/arch/am35x_def.h>
#include <asm/arch/mem.h>
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/musb.h>
#include <asm/mach-types.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <linux/usb/musb.h>
#include <i2c.h>
#include "am3517evm.h"
#define AM3517_IP_SW_RESET	0x48002598
#define CPGMACSS_SW_RST		(1 << 1)
#define PHY_GPIO		30
#if defined(CONFIG_SPL_BUILD)
#if defined(CONFIG_SPL_OS_BOOT)
#endif
#endif
#ifdef CONFIG_USB_MUSB_AM35X
#if defined(CONFIG_USB_MUSB_HOST)
#elif defined(CONFIG_USB_MUSB_GADGET)
#else
#error "Please define either CONFIG_USB_MUSB_HOST or CONFIG_USB_MUSB_GADGET"
#endif
#else
#define am3517_evm_musb_init() do {} while (0)
#endif
#if defined(CONFIG_USB_ETHER) && defined(CONFIG_USB_MUSB_GADGET)
#endif
