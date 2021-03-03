#include <common.h>
#include <clk.h>
#include <dm.h>
#include <fdtdec.h>
#include <asm/arch/gpio.h>
#include <asm/arch/stm32.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <linux/io.h>
#define MODE_BITS(gpio_pin)		(gpio_pin * 2)
#define MODE_BITS_MASK			3
#define BSRR_BIT(gpio_pin, value)	BIT(gpio_pin + (value ? 0 : 16))
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
