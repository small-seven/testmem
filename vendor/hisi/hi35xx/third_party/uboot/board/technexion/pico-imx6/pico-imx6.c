#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/mach-imx/video.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/io.h>
#include <linux/sizes.h>
#include <common.h>
#include <miiphy.h>
#include <netdev.h>
#include <phy.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define ETH_PHY_RESET		IMX_GPIO_NR(1, 26)
#define LVDS0_EN		IMX_GPIO_NR(2, 8)
#define LVDS0_BL_EN		IMX_GPIO_NR(2, 9)
#if defined(CONFIG_VIDEO_IPUV3)
#endif /* CONFIG_VIDEO_IPUV3 */
#if defined(CONFIG_VIDEO_IPUV3)
#endif
