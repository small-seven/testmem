#include <common.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/arch/crm_regs.h>
#include <i2c.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <spl.h>
#include <asm/arch/mx6-ddr.h>
#include "novena.h"
#define UART_PAD_CTRL						\
#define USDHC_PAD_CTRL						\
#define ENET_PAD_CTRL						\
#define ENET_PHY_CFG_PAD_CTRL					\
#define RGMII_PAD_CTRL						\
#define SPI_PAD_CTRL						\
#define I2C_PAD_CTRL						\
#define BUTTON_PAD_CTRL						\
#define PC MUX_PAD_CTRL(I2C_PAD_CTRL)
#ifdef CONFIG_CMD_PCI
#else
#endif
#ifdef CONFIG_MXC_SPI
#else
#endif
#ifdef CONFIG_VIDEO
#else
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#ifdef CONFIG_BOARD_POSTCLK_INIT
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
