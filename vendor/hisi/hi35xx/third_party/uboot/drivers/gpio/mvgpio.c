#include <common.h>
#include <asm/io.h>
#include <linux/errno.h>
#include "mvgpio.h"
#include <asm/gpio.h>
#ifndef MV_MAX_GPIO
#define MV_MAX_GPIO	128
#endif
int gpio_free(unsigned gpio)
{
	return 0;
}
