#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <malloc.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <dm/device-internal.h>
#define S5P_GPIO_GET_PIN(x)	(x % GPIO_PER_BANK)
#define CON_MASK(val)			(0xf << ((val) << 2))
#define CON_SFR(gpio, cfg)		((cfg) << ((gpio) << 2))
#define CON_SFR_UNSHIFT(val, gpio)	((val) >> ((gpio) << 2))
#define DAT_MASK(gpio)			(0x1 << (gpio))
#define DAT_SET(gpio)			(0x1 << (gpio))
#define PULL_MASK(gpio)		(0x3 << ((gpio) << 1))
#define PULL_MODE(gpio, pull)		((pull) << ((gpio) << 1))
#define DRV_MASK(gpio)			(0x3 << ((gpio) << 1))
#define DRV_SET(gpio, mode)		((mode) << ((gpio) << 1))
#define RATE_MASK(gpio)		(0x1 << (gpio + 16))
#define RATE_SET(gpio)			(0x1 << (gpio + 16))
#ifdef CONFIG_SPL_BUILD
#else
#endif /* CONFIG_SPL_BUILD */
#ifndef CONFIG_SPL_BUILD
#endif /* nCONFIG_SPL_BUILD */
#ifndef CONFIG_SPL_BUILD
#endif
