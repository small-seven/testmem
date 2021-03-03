#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/video.h>
#include <asm/mach-imx/sata.h>
#include <asm/io.h>
#include <env.h>
#include <linux/sizes.h>
#include <common.h>
#include <miiphy.h>
#include <netdev.h>
#include <phy.h>
#include <i2c.h>
#include <power/pmic.h>
#include <power/pfuze100_pmic.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define I2C_PAD_CTRL	(PAD_CTL_PUS_100K_UP |			\
#define ETH_PHY_RESET		IMX_GPIO_NR(3, 29)
#define ETH_PHY_AR8035_POWER	IMX_GPIO_NR(7, 13)
#define REV_DETECTION		IMX_GPIO_NR(2, 28)
#ifdef CONFIG_DM_I2C
#define I2C1_SPEED_NON_DM	0
#define I2C2_SPEED_NON_DM	0
#else
#define I2C1_SPEED_NON_DM	CONFIG_SYS_MXC_I2C1_SPEED
#define I2C2_SPEED_NON_DM	CONFIG_SYS_MXC_I2C2_SPEED
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#ifdef CONFIG_DM_I2C
#else
#endif
#endif /* CONFIG_VIDEO_IPUV3 */
#ifdef CONFIG_SATA
#endif
#define PMIC_I2C_BUS		2
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#endif
#ifdef CONFIG_SPL_LOAD_FIT
#endif
