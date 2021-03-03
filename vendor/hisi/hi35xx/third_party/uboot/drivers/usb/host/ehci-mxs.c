#include <common.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <errno.h>
#include "ehci.h"
#define	HW_DIGCTL_CTRL			0x8001c000
#define	HW_DIGCTL_CTRL_USB0_CLKGATE	(1 << 2)
#define	HW_DIGCTL_CTRL_USB1_CLKGATE	(1 << 16)
#ifdef CONFIG_EHCI_MXS_PORT0
#endif
#ifdef CONFIG_EHCI_MXS_PORT1
#endif
