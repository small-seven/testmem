#include <common.h>
#include <env.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/sys_proto.h>
#include <malloc.h>
#include <asm/arch/mx6-pins.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/sata.h>
#include <asm/mach-imx/spi.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/video.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <micrel.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/mxc_hdmi.h>
#include <i2c.h>
#include <input.h>
#include <netdev.h>
#include <usb/ehci-ci.h>
#define GP_USB_OTG_PWR	IMX_GPIO_NR(3, 22)
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |			\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define SPI_PAD_CTRL (PAD_CTL_HYS | PAD_CTL_SPEED_MED |		\
#define BUTTON_PAD_CTRL (PAD_CTL_PUS_100K_UP |			\
#define I2C_PAD_CTRL	(PAD_CTL_PUS_100K_UP |			\
#define RGB_PAD_CTRL	PAD_CTL_DSE_120ohm
#define WEAK_PULLUP	(PAD_CTL_PUS_100K_UP |			\
#define WEAK_PULLDOWN	(PAD_CTL_PUS_100K_DOWN |		\
#define OUTPUT_40OHM (PAD_CTL_SPEED_MED|PAD_CTL_DSE_40ohm)
#define not_octal(gp) ((((0x##gp >> 4) & 0xf) * 10) + ((0x##gp & 0xf)))
#define _I2C_PADS_INFO_CPU(cpu, i2cnum, scl_pad, scl_bank, scl_gp,	       \
#define I2C_PADS_INFO_CPU(cpu, i2cnum, scl_pad, scl_bank, scl_gp,	       \
#if defined(CONFIG_MX6QDL)
#define I2C_PADS_INFO_ENTRY(i2cnum, scl_pad, scl_bank, scl_gp,		\
#define I2C_PADS_INFO_ENTRY_SPACING 2
#define IOMUX_PAD_CTRL(name, pad_ctrl) \
#else
#define I2C_PADS_INFO_ENTRY(i2cnum, scl_pad, scl_bank, scl_gp,		\
#define I2C_PADS_INFO_ENTRY_SPACING 1
#define IOMUX_PAD_CTRL(name, pad_ctrl) NEW_PAD_CTRL(MX6_PAD_##name, pad_ctrl)
#endif
#define I2C_BUS_CNT    3
#define WL12XX_WL_IRQ_GP	IMX_GPIO_NR(6, 14)
#define WL12XX_WL_ENABLE_GP	IMX_GPIO_NR(6, 15)
#define WL12XX_BT_ENABLE_GP	IMX_GPIO_NR(6, 16)
#ifdef CONFIG_USB_EHCI_MX6
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_CI_UDC
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#define RGB_BACKLIGHT_GP IMX_GPIO_NR(1, 21)
#define LVDS_BACKLIGHT_GP IMX_GPIO_NR(1, 18)
#endif
#define WL12XX_WL_IRQ_GP	IMX_GPIO_NR(6, 14)
#if defined(CONFIG_VIDEO_IPUV3)
#endif
#if defined(CONFIG_MX6QDL)
#endif
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_SATA
#endif
#ifdef CONFIG_PREBOOT
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_PREBOOT
#endif
#ifdef CONFIG_CMD_BMODE
#endif
