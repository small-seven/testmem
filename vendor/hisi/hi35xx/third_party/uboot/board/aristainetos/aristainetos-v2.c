#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <env.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/video.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/crm_regs.h>
#include <linux/fb.h>
#include <ipu_pixfmt.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <pwm.h>
#include <micrel.h>
#include <spi.h>
#include <video.h>
#include <../drivers/video/imx/ipu.h>
#if defined(CONFIG_VIDEO_BMP_LOGO)
#endif
#define USDHC2_PAD_CTRL (PAD_CTL_SPEED_LOW |			\
#if (CONFIG_SYS_BOARD_VERSION == 2)
#elif (CONFIG_SYS_BOARD_VERSION == 3)
#endif
#define SOFT_RESET_GPIO		IMX_GPIO_NR(7, 13)
#define SD2_DRIVER_ENABLE	IMX_GPIO_NR(7, 8)
#if (CONFIG_SYS_BOARD_VERSION == 2)
#elif (CONFIG_SYS_BOARD_VERSION == 3)
#endif
#if (CONFIG_SYS_BOARD_VERSION == 2)
#elif (CONFIG_SYS_BOARD_VERSION == 3)
#endif
#if (CONFIG_SYS_BOARD_VERSION == 2)
#endif
#if (CONFIG_SYS_BOARD_VERSION == 2)
#elif (CONFIG_SYS_BOARD_VERSION == 3)
#endif
#if (CONFIG_SYS_BOARD_VERSION == 2)
#endif
#if (CONFIG_SYS_BOARD_VERSION == 2)
#elif (CONFIG_SYS_BOARD_VERSION == 3)
#endif
#if defined(CONFIG_VIDEO_BMP_LOGO)
#endif
#if (CONFIG_SYS_BOARD_VERSION == 2)
#elif (CONFIG_SYS_BOARD_VERSION == 3)
#endif
