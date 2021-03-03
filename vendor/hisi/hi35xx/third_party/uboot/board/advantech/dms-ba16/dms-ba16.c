#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/video.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/crm_regs.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <i2c.h>
#include <input.h>
#include <pwm.h>
#define NC_PAD_CTRL (PAD_CTL_PUS_100K_UP |	\
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |			\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE |	\
#define ENET_CLK_PAD_CTRL (PAD_CTL_SPEED_MED | \
#define ENET_RX_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE | \
#define SPI_PAD_CTRL (PAD_CTL_HYS | PAD_CTL_SPEED_MED | \
#define I2C_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define I2C_PAD MUX_PAD_CTRL(I2C_PAD_CTRL)
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#define USDHC2_CD_GPIO	IMX_GPIO_NR(1, 4)
#define USDHC4_CD_GPIO	IMX_GPIO_NR(6, 11)
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#define LVDS_POWER_GP IMX_GPIO_NR(3, 22)
#define LVDS_BACKLIGHT_GP IMX_GPIO_NR(1, 0)
#endif /* CONFIG_VIDEO_IPUV3 */
#define SUS_S3_OUT	IMX_GPIO_NR(4, 11)
#define WIFI_EN	IMX_GPIO_NR(6, 14)
#if defined(CONFIG_VIDEO_IPUV3)
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#endif
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#define DA9063_ADDR 0x58
#define BCORE2_CONF 0x9D
#define BCORE1_CONF 0x9E
#define BPRO_CONF 0x9F
#define BIO_CONF 0xA0
#define BMEM_CONF 0xA1
#define BPERI_CONF 0xA2
#define MODE_BIT_H 7
#define MODE_BIT_L 6
#ifdef CONFIG_CMD_BMODE
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#endif
#ifdef CONFIG_SATA
#endif
