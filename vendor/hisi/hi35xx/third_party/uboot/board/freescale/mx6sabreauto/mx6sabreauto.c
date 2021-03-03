#include <common.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <env.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/spi.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/arch/sys_proto.h>
#include <i2c.h>
#include <input.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/mach-imx/video.h>
#include <asm/arch/crm_regs.h>
#include <pca953x.h>
#include <power/pmic.h>
#include <power/pfuze100_pmic.h>
#include "../common/pfuze.h"
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |			\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define I2C_PAD_CTRL	(PAD_CTL_PUS_100K_UP |			\
#define GPMI_PAD_CTRL0 (PAD_CTL_PKE | PAD_CTL_PUE | PAD_CTL_PUS_100K_UP)
#define GPMI_PAD_CTRL1 (PAD_CTL_DSE_40ohm | PAD_CTL_SPEED_MED | \
#define GPMI_PAD_CTRL2 (GPMI_PAD_CTRL0 | GPMI_PAD_CTRL1)
#define PC MUX_PAD_CTRL(I2C_PAD_CTRL)
#define WEIM_NOR_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |          \
#define I2C_PMIC	1
#ifndef CONFIG_SYS_FLASH_CFI
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#ifdef CONFIG_NAND_MXS
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#endif /* CONFIG_VIDEO_IPUV3 */
#ifdef CONFIG_NAND_MXS
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#ifndef CONFIG_SYS_FLASH_CFI
#endif
#ifdef CONFIG_VIDEO_IPUV3
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#ifdef CONFIG_USB_EHCI_MX6
#endif
#ifdef CONFIG_SPL_BUILD
#include <asm/arch/mx6-ddr.h>
#include <spl.h>
#include <linux/libfdt.h>
#ifdef CONFIG_SPL_OS_BOOT
#endif
#endif
#ifdef CONFIG_SPL_LOAD_FIT
#endif
