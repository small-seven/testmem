#include <common.h>
#include <dm.h>
#include <env.h>
#include <ns16550.h>
#include <netdev.h>
#include <serial.h>
#include <asm/io.h>
#include <asm/arch/mem.h>
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/gpio.h>
#include <i2c.h>
#include <twl4030.h>
#include <asm/mach-types.h>
#include <asm/omap_musb.h>
#include <linux/mtd/rawnand.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <linux/usb/musb.h>
#include "evm.h"
#define OMAP3EVM_GPIO_ETH_RST_GEN1 64
#define OMAP3EVM_GPIO_ETH_RST_GEN2 7
#if defined(CONFIG_CMD_NET)
#else /* !CONFIG_CMD_NET */
#if defined(CONFIG_STATIC_BOARD_REV)
#else
#endif /* CONFIG_STATIC_BOARD_REV */
#endif /* CONFIG_CMD_NET */
#if defined(CONFIG_USB_MUSB_GADGET) || defined(CONFIG_USB_MUSB_HOST)
#endif /* CONFIG_USB_MUSB_{GADGET,HOST} */
#if defined(CONFIG_SPL_OS_BOOT)
#endif /* CONFIG_SPL_OS_BOOT */
#if defined(CONFIG_SPL_BUILD)
#endif /* CONFIG_SPL_BUILD */
#if defined(CONFIG_USB_MUSB_OMAP2PLUS)
#if defined(CONFIG_USB_MUSB_HOST)
#elif defined(CONFIG_USB_MUSB_GADGET)
#else
#error "Please define either CONFIG_USB_MUSB_HOST or CONFIG_USB_MUSB_GADGET"
#endif /* CONFIG_USB_MUSB_{GADGET,HOST} */
#endif /* CONFIG_USB_MUSB_OMAP2PLUS */
#ifdef CONFIG_SYS_I2C_OMAP24XX
#endif
#if defined(CONFIG_CMD_NET)
#endif
#if defined(CONFIG_CMD_NET)
#endif
#if defined(CONFIG_USB_MUSB_OMAP2PLUS)
#endif
#if defined(CONFIG_USB_ETHER) && defined(CONFIG_USB_MUSB_GADGET)
#endif
#if defined(CONFIG_CMD_NET)
#if defined(CONFIG_SMC911X)
#else
#endif
#endif /* CONFIG_CMD_NET */
#if defined(CONFIG_MMC)
#endif /* CONFIG_MMC */
#if defined(CONFIG_USB_ETHER) && defined(CONFIG_USB_MUSB_GADGET) && !defined(CONFIG_CMD_NET)
#endif /* CONFIG_USB_ETHER */
