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
#define UART_PAD_CTRL  (PAD_CTL_PKE         | PAD_CTL_PUE       | \
#ifdef CONFIG_NAND_MXS
#define NAND_PAD_CTRL (PAD_CTL_DSE_48ohm | PAD_CTL_SRE_SLOW | PAD_CTL_HYS)
#define NAND_PAD_READY0_CTRL (PAD_CTL_DSE_48ohm | PAD_CTL_PUS_22K_UP)
#define NANDREADYPC MUX_PAD_CTRL(NAND_PAD_READY0_CTRL)
#endif /* CONFIG_NAND_MXS */
#ifdef CONFIG_FEC_MXC
#define ENET_CLK_PAD_CTRL (PAD_CTL_DSE_40ohm   | PAD_CTL_SRE_FAST)
#define ENET_PAD_CTRL     (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE       | \
#define MDIO_PAD_CTRL     (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE      | \
#endif /* CONFIG_FEC_MXC */
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_NAND_MXS
#endif
#ifdef CONFIG_FEC_MXC
#endif
