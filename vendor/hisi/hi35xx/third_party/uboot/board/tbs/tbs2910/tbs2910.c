#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/video.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/crm_regs.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#ifdef CONFIG_FSL_ESDHC_IMX
#endif /* CONFIG_FSL_ESDHC_IMX */
#ifdef CONFIG_VIDEO_IPUV3
#endif /* CONFIG_VIDEO_IPUV3 */
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_VIDEO_IPUV3
#endif
#ifdef CONFIG_CMD_BMODE
#endif
