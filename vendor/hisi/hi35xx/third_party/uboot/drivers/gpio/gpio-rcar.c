#include <common.h>
#include <clk.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <errno.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include "../pinctrl/renesas/sh_pfc.h"
#define GPIO_IOINTSEL	0x00	/* General IO/Interrupt Switching Register */
#define GPIO_INOUTSEL	0x04	/* General Input/Output Switching Register */
#define GPIO_OUTDT	0x08	/* General Output Register */
#define GPIO_INDT	0x0c	/* General Input Register */
#define GPIO_INTDT	0x10	/* Interrupt Display Register */
#define GPIO_INTCLR	0x14	/* Interrupt Clear Register */
#define GPIO_INTMSK	0x18	/* Interrupt Mask Register */
#define GPIO_MSKCLR	0x1c	/* Interrupt Mask Clear Register */
#define GPIO_POSNEG	0x20	/* Positive/Negative Logic Select Register */
#define GPIO_EDGLEVEL	0x24	/* Edge/level Select Register */
#define GPIO_FILONOFF	0x28	/* Chattering Prevention On/Off Register */
#define GPIO_BOTHEDGE	0x4c	/* One Edge/Both Edge Select Register */
#define RCAR_MAX_GPIO_PER_BANK		32
static int rcar_gpio_free(struct udevice *dev, unsigned offset)
{
	return pinctrl_gpio_free(dev, offset);
}
