#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/mx6ul_pins.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/io.h>
#include <common.h>
#include <env.h>
#include <fsl_esdhc_imx.h>
#include <i2c.h>
#include <miiphy.h>
#include <mmc.h>
#include <netdev.h>
#include <usb.h>
#include <usb/ehci-ci.h>
#define UART_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define USDHC_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define I2C_PAD_CTRL    (PAD_CTL_PKE | PAD_CTL_PUE |            \
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE |     \
#define MDIO_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE |     \
#define ENET_CLK_PAD_CTRL  (PAD_CTL_DSE_40ohm   | PAD_CTL_SRE_FAST)
#define ENET_RX_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |          \
#define OTGID_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define PC MUX_PAD_CTRL(I2C_PAD_CTRL)
#define USDHC2_PWR_GPIO	IMX_GPIO_NR(1, 9)
#define USB_OTHERREGS_OFFSET	0x800
#define UCTRL_PWR_POL		(1 << 9)
#define ENET_PHY_RESET_GPIO IMX_GPIO_NR(4, 17)
