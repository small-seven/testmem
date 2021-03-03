#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <fsl_esdhc_imx.h>
#include <linux/bitops.h>
#include <miiphy.h>
#include <netdev.h>
#include <usb.h>
#include <usb/ehci-ci.h>
#ifdef CONFIG_NAND_MXS
#define GPMI_PAD_CTRL0 (PAD_CTL_PKE | PAD_CTL_PUE | PAD_CTL_PUS_100K_UP)
#define GPMI_PAD_CTRL1 (PAD_CTL_DSE_40ohm | PAD_CTL_SPEED_MED | \
#define GPMI_PAD_CTRL2 (GPMI_PAD_CTRL0 | GPMI_PAD_CTRL1)
#endif
#ifdef CONFIG_FEC_MXC
#define ENET_CLK_PAD_CTRL (PAD_CTL_DSE_40ohm   | PAD_CTL_SRE_FAST)
#define ENET_PAD_CTRL     (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE       | \
#define MDIO_PAD_CTRL     (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE      | \
#if defined(CONFIG_CI_UDC) && defined(CONFIG_USB_ETHER)
#endif
#endif /* CONFIG_FEC_MXC */
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_NAND_MXS
#endif
