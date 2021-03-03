#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <env.h>
#include <linux/errno.h>
#include <linux/libfdt.h>
#include <asm/gpio.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/video.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <miiphy.h>
#include <net.h>
#include <netdev.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/crm_regs.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <i2c.h>
#include <input.h>
#include <pwm.h>
#include <version.h>
#include <stdlib.h>
#include "../common/ge_common.h"
#include "../common/vpd_reader.h"
#include "../../../drivers/net/e1000.h"
#define NC_PAD_CTRL (PAD_CTL_PUS_100K_UP |	\
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE |	\
#define ENET_CLK_PAD_CTRL (PAD_CTL_SPEED_MED | \
#define ENET_RX_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE | \
#define I2C_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define I2C_PAD MUX_PAD_CTRL(I2C_PAD_CTRL)
#if defined(CONFIG_VIDEO_IPUV3)
#define LVDS_POWER_GP IMX_GPIO_NR(3, 22)
#define LVDS_BACKLIGHT_GP IMX_GPIO_NR(1, 0)
#endif /* CONFIG_VIDEO_IPUV3 */
#define VPD_TYPE_INVALID 0x00
#define VPD_BLOCK_NETWORK 0x20
#define VPD_BLOCK_HWID 0x44
#define VPD_PRODUCT_B850 1
#define VPD_PRODUCT_B650 2
#define VPD_PRODUCT_B450 3
#define VPD_HAS_MAC1 0x1
#define VPD_HAS_MAC2 0x2
#define VPD_MAC_ADDRESS_LENGTH 6
#define SUS_S3_OUT	IMX_GPIO_NR(4, 11)
#define WIFI_EN	IMX_GPIO_NR(6, 14)
#if defined(CONFIG_VIDEO_IPUV3)
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#define I2C_PMIC                0x2
#define DA9063_I2C_ADDR         0x58
#define DA9063_REG_BCORE2_CFG   0x9D
#define DA9063_REG_BCORE1_CFG   0x9E
#define DA9063_REG_BPRO_CFG     0x9F
#define DA9063_REG_BIO_CFG      0xA0
#define DA9063_REG_BMEM_CFG     0xA1
#define DA9063_REG_BPERI_CFG    0xA2
#define DA9063_BUCK_MODE_MASK   0xC0
#define DA9063_BUCK_MODE_MANUAL 0x00
#define DA9063_BUCK_MODE_SLEEP  0x40
#define DA9063_BUCK_MODE_SYNC   0x80
#define DA9063_BUCK_MODE_AUTO   0xC0
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#endif
#ifdef CONFIG_VIDEO_IPUV3
#endif
