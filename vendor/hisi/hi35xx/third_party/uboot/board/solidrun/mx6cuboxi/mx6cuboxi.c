#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/mxc_hdmi.h>
#include <env.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/sata.h>
#include <asm/mach-imx/video.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <malloc.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/arch/crm_regs.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <spl.h>
#include <usb.h>
#include <usb/ehci-ci.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |			\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define ENET_PAD_CTRL_PD  (PAD_CTL_PUS_100K_DOWN |		\
#define ENET_PAD_CTRL_CLK  ((PAD_CTL_PUS_100K_UP & ~PAD_CTL_PKE) | \
#define ETH_PHY_RESET	IMX_GPIO_NR(4, 15)
#define USB_H1_VBUS	IMX_GPIO_NR(1, 0)
#define MEM_STRIDE 0x4000000
#define USDHC2_CD_GPIO  IMX_GPIO_NR(1, 4)
#define ETH_PHY_MASK	((1 << 0x0) | (1 << 0x4))
#ifdef CONFIG_VIDEO_IPUV3
#endif /* CONFIG_VIDEO_IPUV3 */
#ifdef CONFIG_USB_EHCI_MX6
#endif
#ifdef CONFIG_CMD_SATA
#endif
#ifdef CONFIG_USB_EHCI_MX6
#endif
#ifdef CONFIG_VIDEO_IPUV3
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#ifdef CONFIG_SPL_BUILD
#include <asm/arch/mx6-ddr.h>
#endif
