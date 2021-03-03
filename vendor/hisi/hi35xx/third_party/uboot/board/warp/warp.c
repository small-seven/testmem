#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/io.h>
#include <linux/sizes.h>
#include <common.h>
#include <watchdog.h>
#include <fsl_esdhc_imx.h>
#include <i2c.h>
#include <mmc.h>
#include <usb.h>
#include <power/pmic.h>
#include <power/max77696_pmic.h>
#define UART_PAD_CTRL (PAD_CTL_PUS_100K_UP | \
#define USDHC_PAD_CTRL (PAD_CTL_PUS_22K_UP | \
#define I2C_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define I2C_PMIC	0
#define PC	MUX_PAD_CTRL(I2C_PAD_CTRL)
#ifdef CONFIG_HW_WATCHDOG
#endif
