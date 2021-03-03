#include <common.h>
#include <dm.h>
#include <errno.h>
#include <wait_bit.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/clk.h>
#include <asm/arch/i2c.h>
#include <usb.h>
#include <i2c.h>
#define OTG_HOST_EN			(1 << 0) /* Enable host mode */
#define OTG_CLK_AHB_EN			(1 << 4) /* Enable AHB clock */
#define OTG_CLK_OTG_EN			(1 << 3) /* Enable OTG clock */
#define OTG_CLK_I2C_EN			(1 << 2) /* Enable I2C clock */
#define OTG_CLK_HOST_EN			(1 << 0) /* Enable host clock */
#define MC1_SPEED_REG			(1 << 0)
#define MC1_DAT_SE0			(1 << 2)
#define MC1_UART_EN			(1 << 6)
#define MC2_SPD_SUSP_CTRL		(1 << 1)
#define MC2_BI_DI			(1 << 2)
#define MC2_PSW_EN			(1 << 6)
#define OTG1_DP_PULLUP			(1 << 0)
#define OTG1_DM_PULLUP			(1 << 1)
#define OTG1_DP_PULLDOWN		(1 << 2)
#define OTG1_DM_PULLDOWN		(1 << 3)
#define OTG1_VBUS_DRV			(1 << 5)
#define ISP1301_I2C_ADDR		CONFIG_USB_ISP1301_I2C_ADDR
#define ISP1301_I2C_MODE_CONTROL_1_SET		0x04
#define ISP1301_I2C_MODE_CONTROL_1_CLR		0x05
#define ISP1301_I2C_MODE_CONTROL_2_SET		0x12
#define ISP1301_I2C_MODE_CONTROL_2_CLR		0x13
#define ISP1301_I2C_OTG_CONTROL_1_SET		0x06
#define ISP1301_I2C_OTG_CONTROL_1_CLR		0x07
#define ISP1301_I2C_INTERRUPT_LATCH_CLR		0x0B
#define ISP1301_I2C_INTERRUPT_FALLING_CLR	0x0D
#define ISP1301_I2C_INTERRUPT_RISING_CLR	0x0F
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#endif
