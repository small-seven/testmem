#include <common.h>
#include <dm.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux-mx53.h>
#include <asm/mach-imx/mx5_video.h>
#include <asm/mach-imx/video.h>
#include <asm/gpio.h>
#include <asm/spl.h>
#include <env.h>
#include <fdt_support.h>
#include <fsl_esdhc_imx.h>
#include <gzip.h>
#include <i2c.h>
#include <ipu_pixfmt.h>
#include <linux/errno.h>
#include <linux/fb.h>
#include <mmc.h>
#include <netdev.h>
#include <spl.h>
#include <splash.h>
#include <usb/ehci-ci.h>
#include <video_console.h>
#ifdef CONFIG_FSL_ESDHC_IMX
#define SD_CMD_PAD_CTRL		(PAD_CTL_HYS | PAD_CTL_DSE_HIGH | \
#define SD_PAD_CTRL		(PAD_CTL_HYS | PAD_CTL_PUS_47K_UP | \
#endif
#ifdef CONFIG_SPLASH_SCREEN
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#endif
#define I2C_PAD_CTRL	(PAD_CTL_SRE_FAST | PAD_CTL_DSE_HIGH | \
#ifdef CONFIG_SPL_BUILD
#endif
