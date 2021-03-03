#include <common.h>
#include <dm.h>
#include <hwspinlock.h>
#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <dm/lists.h>
#include <dm/pinctrl.h>
#define MAX_PINS_ONE_IP			70
#define MODE_BITS_MASK			3
#define OSPEED_MASK			3
#define PUPD_MASK			3
#define OTYPE_MSK			1
#define AFR_MASK			0xF
#ifndef CONFIG_SPL_BUILD
#define PINMUX_MODE_COUNT		5
#endif
#if CONFIG_IS_ENABLED(PINCTRL_FULL)
#else /* PINCTRL_FULL */
#endif /* PINCTRL_FULL */
#if CONFIG_IS_ENABLED(PINCTRL_FULL)
#else /* PINCTRL_FULL */
#endif /* PINCTRL_FULL */
#ifndef CONFIG_SPL_BUILD
#endif
