#include <init.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/sys_proto.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <common.h>
#include <fsl_esdhc_imx.h>
#include <linux/libfdt.h>
#include <malloc.h>
#include <i2c.h>
#include <miiphy.h>
#include <mmc.h>
#include <netdev.h>
#include "tqma6_bb.h"
#define UART4_PAD_CTRL (			\
#define USDHC2_PAD_CTRL (			\
#define USDHC2_CLK_PAD_CTRL (			\
#define USDHC2_CD_GPIO IMX_GPIO_NR(1, 4)
#define USDHC2_WP_GPIO IMX_GPIO_NR(1, 2)
#define ENET_PAD_CTRL (				\
#define ENET_PHY_RESET_GPIO IMX_GPIO_NR(1, 8)
#define GPIO_PAD_CTRL (				\
#define GPIO_OD_PAD_CTRL (			\
#define GPIO_USB_H_PWR		IMX_GPIO_NR(1, 0)
#define GPIO_USB_OTG_PWR	IMX_GPIO_NR(3, 22)
#define GPIO_PCIE_RST		IMX_GPIO_NR(6, 7)
#define GPIO_UART1_PWRON	IMX_GPIO_NR(5, 8)
#define GPIO_UART2_PWRON	IMX_GPIO_NR(5, 10)
#define GPIO_UART3_PWRON	IMX_GPIO_NR(5, 12)
#define WRU4_USB_H1_PWR		IMX_GPIO_NR(1, 0)
#define WRU4_USB_OTG_PWR	IMX_GPIO_NR(3, 22)
#if defined(CONFIG_OF_BOARD_SETUP) && defined(CONFIG_OF_LIBFDT)
#endif /* defined(CONFIG_OF_BOARD_SETUP) && defined(CONFIG_OF_LIBFDT) */
