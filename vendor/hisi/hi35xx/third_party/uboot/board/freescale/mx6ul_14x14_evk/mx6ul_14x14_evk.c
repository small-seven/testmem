#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/mx6ul_pins.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/io.h>
#include <common.h>
#include <env.h>
#include <fsl_esdhc_imx.h>
#include <i2c.h>
#include <miiphy.h>
#include <linux/sizes.h>
#include <mmc.h>
#include <netdev.h>
#include <power/pmic.h>
#include <power/pfuze3000_pmic.h>
#include "../common/pfuze.h"
#include <usb.h>
#include <usb/ehci-ci.h>
#define UART_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define USDHC_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define USDHC_DAT3_CD_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |	\
#define I2C_PAD_CTRL    (PAD_CTL_PKE | PAD_CTL_PUE |            \
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE |     \
#define LCD_PAD_CTRL    (PAD_CTL_HYS | PAD_CTL_PUS_100K_UP | PAD_CTL_PUE | \
#define MDIO_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE |     \
#define ENET_CLK_PAD_CTRL  (PAD_CTL_DSE_40ohm   | PAD_CTL_SRE_FAST)
#define OTG_ID_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
#ifdef CONFIG_DM_PMIC
#endif
#if defined(CONFIG_MX6UL_14X14_EVK_EMMC_REWORK)
#else
#endif
#ifdef CONFIG_FSL_QSPI
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#if defined(CONFIG_MX6UL_14X14_EVK_EMMC_REWORK)
#else
#endif
#define USDHC1_CD_GPIO	IMX_GPIO_NR(1, 19)
#define USDHC1_PWR_GPIO	IMX_GPIO_NR(1, 9)
#define USDHC2_CD_GPIO	IMX_GPIO_NR(4, 5)
#define USDHC2_PWR_GPIO	IMX_GPIO_NR(4, 10)
#if defined(CONFIG_MX6UL_14X14_EVK_EMMC_REWORK)
#else
#endif
#if defined(CONFIG_MX6UL_14X14_EVK_EMMC_REWORK)
#else
#endif
#endif
#ifdef CONFIG_USB_EHCI_MX6
#ifndef CONFIG_DM_USB
#define USB_OTHERREGS_OFFSET	0x800
#define UCTRL_PWR_POL		(1 << 9)
#endif
#endif
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_DM_VIDEO
#else
#endif
#ifdef	CONFIG_FEC_MXC
#endif
#ifdef CONFIG_USB_EHCI_MX6
#ifndef CONFIG_DM_USB
#endif
#endif
#ifdef CONFIG_FSL_QSPI
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#ifdef CONFIG_SPL_BUILD
#include <linux/libfdt.h>
#include <spl.h>
#include <asm/arch/mx6-ddr.h>
#ifdef CONFIG_TARGET_MX6UL_9X9_EVK
#else
#endif
#ifdef CONFIG_TARGET_MX6UL_9X9_EVK
#else
#endif
#endif
