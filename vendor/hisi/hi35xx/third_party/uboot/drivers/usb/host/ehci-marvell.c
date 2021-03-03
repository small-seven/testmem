#include <common.h>
#include <asm/io.h>
#include <usb.h>
#include "ehci.h"
#include <linux/mbus.h>
#include <asm/arch/cpu.h>
#include <dm.h>
#if defined(CONFIG_KIRKWOOD)
#include <asm/arch/soc.h>
#elif defined(CONFIG_ORION5X)
#include <asm/arch/orion5x.h>
#endif
#define USB_WINDOW_CTRL(i)	(0x320 + ((i) << 4))
#define USB_WINDOW_BASE(i)	(0x324 + ((i) << 4))
#define USB_TARGET_DRAM		0x0
#define USB2_SBUSCFG_OFF	0x90
#define USB_SBUSCFG_BAWR_OFF	0x6
#define USB_SBUSCFG_BARD_OFF	0x3
#define USB_SBUSCFG_AHBBRST_OFF	0x0
#define USB_SBUSCFG_BAWR_ALIGN_64B	0x4
#define USB_SBUSCFG_BARD_ALIGN_64B	0x4
#define USB_SBUSCFG_AHBBRST_INCR16	0x7
#if CONFIG_IS_ENABLED(DM_USB)
#else
#define MVUSB_BASE(port)	MVUSB0_BASE
#endif /* CONFIG_IS_ENABLED(DM_USB) */
