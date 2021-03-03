#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/spi.h>
#include <asm/mach-imx/video.h>
#include <i2c.h>
#include <input.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/crm_regs.h>
#include <linux/fb.h>
#include <ipu_pixfmt.h>
#include <asm/io.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |			\
#define USDHC_PAD_CLK_CTRL (PAD_CTL_SPEED_LOW |		\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define ENET_PAD_CTRL_PD  (PAD_CTL_PUS_100K_DOWN |		\
#define ENET_PAD_CTRL_CLK  ((PAD_CTL_PUS_100K_UP & ~PAD_CTL_PKE) | \
#define I2C_PAD_CTRL	(PAD_CTL_PUS_100K_UP |			\
#define SPI_PAD_CTRL (PAD_CTL_HYS | PAD_CTL_SPEED_MED | \
#define BOARD_IS_MARSBOARD	0
#define BOARD_IS_RIOTBOARD	1
#ifdef CONFIG_FSL_ESDHC_IMX
#define USDHC2_CD_GPIO	IMX_GPIO_NR(1, 4)
#define USDHC3_CD_GPIO	IMX_GPIO_NR(7, 0)
#endif
#ifdef CONFIG_MXC_SPI
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#endif /* CONFIG_VIDEO_IPUV3 */
#if defined(CONFIG_VIDEO_IPUV3)
#endif
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_SPL_BUILD
#include <spl.h>
#ifdef CONFIG_SPL_SERIAL_SUPPORT
#endif
#endif
