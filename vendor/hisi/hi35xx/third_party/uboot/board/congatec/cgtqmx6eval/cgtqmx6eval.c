#include <common.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/sata.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/crm_regs.h>
#include <env.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <i2c.h>
#include <input.h>
#include <power/pmic.h>
#include <power/pfuze100_pmic.h>
#include <linux/fb.h>
#include <ipu_pixfmt.h>
#include <malloc.h>
#include <miiphy.h>
#include <netdev.h>
#include <micrel.h>
#include <spi_flash.h>
#include <spi.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED |\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP  | PAD_CTL_SPEED_LOW |\
#define I2C_PAD_CTRL	(PAD_CTL_PKE | PAD_CTL_PUE |		\
#define SPI_PAD_CTRL (PAD_CTL_HYS |				\
#define MX6Q_QMX6_PFUZE_MUX		IMX_GPIO_NR(6, 9)
#define ENET_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |		\
#ifndef CONFIG_SPL_BUILD
#endif
#define PC MUX_PAD_CTRL(I2C_PAD_CTRL)
#define I2C_PMIC	1	/* I2C2 port is used to connect to the PMIC */
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#ifndef CONFIG_SPL_BUILD
#else
#endif
#endif
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_SATA
#endif
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#ifdef CONFIG_SPL_BUILD
#include <asm/arch/mx6-ddr.h>
#include <spl.h>
#include <linux/libfdt.h>
#include <spi_flash.h>
#include <spi.h>
#define CFG_MFG_ADDR_OFFSET	(spi->size - SZ_16K)
#endif
