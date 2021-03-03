#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <env.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <asm/arch/crm_regs.h>
#include <asm/io.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/arch/sys_proto.h>
#include <spl.h>
#include <linux/sizes.h>
#include <common.h>
#include <i2c.h>
#include <miiphy.h>
#include <netdev.h>
#include <power/pmic.h>
#include <power/pfuze3000_pmic.h>
#include <malloc.h>
#define UART_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define USDHC_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define I2C_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE |     \
#define ENET_CLK_PAD_CTRL  (PAD_CTL_SPEED_MED | \
#define ENET_RX_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |          \
#define WDOG_PAD_CTRL (PAD_CTL_PUE | PAD_CTL_PKE | PAD_CTL_SPEED_MED |	\
#define BOARD_DETECT_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define BOARD_DETECT_PAD_CFG (MUX_PAD_CTRL(BOARD_DETECT_PAD_CTRL) |	\
#ifdef CONFIG_SYS_I2C_MXC
#define PC MUX_PAD_CTRL(I2C_PAD_CTRL)
#endif
#ifdef CONFIG_POWER
#endif
#ifdef CONFIG_SYS_I2C_MXC
#endif
#define USDHC2_PWR_GPIO IMX_GPIO_NR(6, 1)
#define USDHC2_CD_GPIO	IMX_GPIO_NR(6, 2)
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#ifdef CONFIG_SPL_BUILD
#include <linux/libfdt.h>
#include <asm/arch/mx6-ddr.h>
#endif
