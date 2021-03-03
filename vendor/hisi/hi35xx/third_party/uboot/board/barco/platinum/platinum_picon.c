#include <common.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <i2c.h>
#include <miiphy.h>
#include "platinum.h"
#define GPIO_IP_NCONFIG		IMX_GPIO_NR(5, 18)
#define GPIO_HK_NCONFIG		IMX_GPIO_NR(7, 13)
#define GPIO_LS_NCONFIG		IMX_GPIO_NR(5, 19)
#define GPIO_I2C0_SEL0		IMX_GPIO_NR(5,  2)
#define GPIO_I2C0_SEL1		IMX_GPIO_NR(1, 11)
#define GPIO_I2C0_ENBN		IMX_GPIO_NR(1, 13)
#define GPIO_I2C2_SEL0		IMX_GPIO_NR(1, 17)
#define GPIO_I2C2_SEL1		IMX_GPIO_NR(1, 20)
#define GPIO_I2C2_ENBN		IMX_GPIO_NR(1, 14)
#define GPIO_USB_RESET		IMX_GPIO_NR(1,  5)
