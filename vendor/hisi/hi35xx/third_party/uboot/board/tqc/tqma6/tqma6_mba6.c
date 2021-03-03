#include <init.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/sys_proto.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <common.h>
#include <fsl_esdhc_imx.h>
#include <linux/libfdt.h>
#include <malloc.h>
#include <i2c.h>
#include <micrel.h>
#include <miiphy.h>
#include <mmc.h>
#include <netdev.h>
#include "tqma6_bb.h"
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED | \
#define USDHC_CLK_PAD_CTRL (PAD_CTL_PUS_47K_UP  | PAD_CTL_SPEED_LOW | \
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP  | PAD_CTL_SPEED_LOW | \
#define GPIO_OUT_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_LOW | \
#define GPIO_IN_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_LOW | \
#define SPI_PAD_CTRL (PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED | \
#define I2C_PAD_CTRL	(PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED | \
#if defined(CONFIG_TQMA6Q)
#define IOMUX_SW_PAD_CTRL_GRP_DDR_TYPE_RGMII	0x02e0790
#define IOMUX_SW_PAD_CTRL_GRP_RGMII_TERM	0x02e07ac
#elif defined(CONFIG_TQMA6S) || defined(CONFIG_TQMA6DL)
#define IOMUX_SW_PAD_CTRL_GRP_DDR_TYPE_RGMII	0x02e0768
#define IOMUX_SW_PAD_CTRL_GRP_RGMII_TERM	0x02e0788
#else
#error "need to select module"
#endif
#define ENET_RX_PAD_CTRL	(PAD_CTL_DSE_34ohm)
#define ENET_TX_PAD_CTRL	(PAD_CTL_PUS_100K_UP | PAD_CTL_DSE_34ohm)
#define ENET_CLK_PAD_CTRL	(PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_HIGH | \
#define ENET_MDIO_PAD_CTRL	(PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED | \
#define IOMUX_SW_PAD_CTRL_GRP_RGMII_TERM_DISABLE	0x00000000
#define IOMUX_SW_PAD_CTRL_GRP_DDR_TYPE_RGMII_1P2V	0x00080000
#define IOMUX_SW_PAD_CTRL_GRP_DDR_TYPE_RGMII_1P5V	0x000C0000
#define ENET_PHY_RESET_GPIO IMX_GPIO_NR(1, 25)
#define USDHC2_CD_GPIO	IMX_GPIO_NR(1, 4)
#define USDHC2_WP_GPIO	IMX_GPIO_NR(1, 2)
#if defined(CONFIG_TQMA6Q)
#define MBA6X_KSZ9031_CTRL_SKEW	0x0032
#define MBA6X_KSZ9031_CLK_SKEW	0x03ff
#define MBA6X_KSZ9031_RX_SKEW	0x3333
#define MBA6X_KSZ9031_TX_SKEW	0x2036
#elif defined(CONFIG_TQMA6S) || defined(CONFIG_TQMA6DL)
#define MBA6X_KSZ9031_CTRL_SKEW	0x0030
#define MBA6X_KSZ9031_CLK_SKEW	0x03ff
#define MBA6X_KSZ9031_RX_SKEW	0x3333
#define MBA6X_KSZ9031_TX_SKEW	0x2052
#else
#error
#endif
#if defined(CONFIG_OF_BOARD_SETUP) && defined(CONFIG_OF_LIBFDT)
#endif /* defined(CONFIG_OF_BOARD_SETUP) && defined(CONFIG_OF_LIBFDT) */
