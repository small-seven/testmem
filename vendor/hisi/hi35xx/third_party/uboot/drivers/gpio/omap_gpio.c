#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <malloc.h>
#define OMAP_GPIO_DIR_OUT	0
#define OMAP_GPIO_DIR_IN	1
#ifdef CONFIG_DM_GPIO
#define GPIO_PER_BANK			32
#endif
#ifndef CONFIG_DM_GPIO
int gpio_free(unsigned gpio)
{
	return 0;
}
#else /* new driver model interface CONFIG_DM_GPIO */
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#else
#endif
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#endif /* CONFIG_DM_GPIO */
