#include <common.h>
#include <dm.h>
#include <env.h>
#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/sys_proto.h>
#include <asm/bootm.h>
#include <asm/gpio.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/sata.h>
#include <asm/mach-imx/video.h>
#include <cpu.h>
#include <dm/platform_data/serial_mxc.h>
#include <fsl_esdhc_imx.h>
#include <imx_thermal.h>
#include <miiphy.h>
#include <netdev.h>
#include <cpu.h>
#include "../common/tdx-cfg-block.h"
#ifdef CONFIG_TDX_CMD_IMX_MFGR
#include "pf0100.h"
#endif
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |			\
#define USDHC_EMMC_PAD_CTRL (PAD_CTL_PUS_47K_UP |		\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define WEAK_PULLUP	(PAD_CTL_PUS_100K_UP |			\
#define NO_PULLUP	(					\
#define WEAK_PULLDOWN	(PAD_CTL_PUS_100K_DOWN |		\
#define OUTPUT_RGB (PAD_CTL_SPEED_MED|PAD_CTL_DSE_60ohm|PAD_CTL_SRE_FAST)
#if defined(CONFIG_FSL_ESDHC_IMX) && defined(CONFIG_SPL_BUILD)
#	define GPIO_MMC_CD IMX_GPIO_NR(2, 5)
#endif /* CONFIG_FSL_ESDHC_IMX & CONFIG_SPL_BUILD */
#	define GPIO_USBH_EN IMX_GPIO_NR(3, 31)
#define UCR3		0x88	/* FIFO Control Register */
#define UCR3_RI		BIT(8)	/* RIDELT DTE mode */
#define UCR3_DCD	BIT(9)	/* DCDDELT DTE mode */
#define UFCR		0x90	/* FIFO Control Register */
#define UFCR_DCEDTE	BIT(6)	/* DCE=0 */
#ifdef CONFIG_USB_EHCI_MX6
#endif
#if defined(CONFIG_FSL_ESDHC_IMX) && defined(CONFIG_SPL_BUILD)
#endif /* CONFIG_FSL_ESDHC_IMX & CONFIG_SPL_BUILD */
#ifdef CONFIG_FEC_MXC
#endif /* CONFIG_FEC_MXC */
#if defined(CONFIG_VIDEO_IPUV3)
#define RGB_BACKLIGHT_GP IMX_GPIO_NR(3, 26)
#define RGB_BACKLIGHTPWM_GP IMX_GPIO_NR(2, 9)
#endif /* defined(CONFIG_VIDEO_IPUV3) */
#if defined(CONFIG_VIDEO_IPUV3)
#endif
#ifdef CONFIG_TDX_CMD_IMX_MFGR
#endif
#ifdef CONFIG_SATA
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#if defined(CONFIG_REVISION_TAG) && \
#endif
#ifdef CONFIG_CMD_USB_SDP
#endif /* CONFIG_CMD_USB_SDP */
#endif /* CONFIG_BOARD_LATE_INIT */
#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_LDO_BYPASS_CHECK
#endif
#ifdef CONFIG_SPL_BUILD
#include <spl.h>
#include <linux/libfdt.h>
#include "asm/arch/mx6dl-ddr.h"
#include "asm/arch/iomux.h"
#include "asm/arch/crm_regs.h"
#define GPIO_NRESET IMX_GPIO_NR(6, 27)
#define IMX_RESET_CAUSE_POR 0x00011
#endif /* CONFIG_SPL_BUILD */
