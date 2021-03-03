#include <common.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/spi.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <mmc.h>
#include <i2c.h>
#include <fsl_esdhc_imx.h>
#include <nand.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/arch/sys_proto.h>
#include <asm/sections.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |			\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define SPI_PAD_CTRL (PAD_CTL_HYS | PAD_CTL_SPEED_MED | \
#define I2C_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define I2C_PAD MUX_PAD_CTRL(I2C_PAD_CTRL)
#define ASRC_PAD_CTRL (PAD_CTL_HYS | PAD_CTL_PUS_100K_UP  |	\
#define NAND_PAD_CTRL (PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED | \
#define ENET_PHY_RESET_GPIO IMX_GPIO_NR(1, 14)
#define USDHC1_CD_GPIO	IMX_GPIO_NR(6, 31)
#define USER_LED	IMX_GPIO_NR(1, 4)
#define IMX6Q_DRIVE_STRENGTH	0x30
#ifdef CONFIG_CMD_NAND
#endif
#ifndef CONFIG_CMD_NAND
#endif
#if !defined(CONFIG_CMD_NAND) && !defined(CONFIG_SPL_BUILD)
#endif
#ifndef CONFIG_SPL_BUILD
#ifndef CONFIG_CMD_NAND
#endif
#else
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_SYS_I2C_MXC
#endif
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_SPL_BUILD
#include <spl.h>
#include <linux/libfdt.h>
#ifdef CONFIG_CMD_NAND
#endif
#endif
