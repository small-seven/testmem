#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <env.h>
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
#include <power/pmic.h>
#include <power/pfuze100_pmic.h>
#include <asm/arch/mx6-ddr.h>
#define OPEN_PAD_CTRL  (PAD_CTL_ODE  | PAD_CTL_DSE_DISABLE | (0 << 12))
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |			\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define ENET_PAD_CTRL_PD  (PAD_CTL_PUS_100K_DOWN |		\
#define ENET_PAD_CTRL_CLK  ((PAD_CTL_PUS_100K_UP & ~PAD_CTL_PKE) | \
#define SPI_PAD_CTRL (PAD_CTL_HYS | PAD_CTL_SPEED_MED | \
#define I2C_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define I2C_PMIC	1
#define I2C_PAD MUX_PAD_CTRL(I2C_PAD_CTRL)
#define ETH_PHY_RESET	IMX_GPIO_NR(2, 4)
#ifdef CONFIG_TARGET_ZC5202
#define BOARD_NAME "EL6x-ZC5202"
#else
#define BOARD_NAME "EL6x-ZC5601"
#endif
#ifdef CONFIG_TARGET_ZC5202
#endif
#ifdef CONFIG_MXC_SPI
#ifdef CONFIG_TARGET_ZC5202
#endif
#ifdef CONFIG_TARGET_ZC5202
#endif
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#define USDHC2_CD_GPIO	IMX_GPIO_NR(1, 4)
#ifndef CONFIG_SPL_BUILD
#else
#endif
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_SPL_BUILD
#include <spl.h>
#include <linux/libfdt.h>
#endif
