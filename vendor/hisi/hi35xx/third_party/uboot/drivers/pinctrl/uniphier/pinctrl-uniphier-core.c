#include <common.h>
#include <dm.h>
#include <linux/io.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/sizes.h>
#include <dm/pinctrl.h>
#include "pinctrl-uniphier.h"
#define UNIPHIER_PINCTRL_PINMUX_BASE	0x1000
#define UNIPHIER_PINCTRL_LOAD_PINMUX	0x1700
#define UNIPHIER_PINCTRL_DRVCTRL_BASE	0x1800
#define UNIPHIER_PINCTRL_DRV2CTRL_BASE	0x1900
#define UNIPHIER_PINCTRL_DRV3CTRL_BASE	0x1980
#define UNIPHIER_PINCTRL_PUPDCTRL_BASE	0x1a00
#define UNIPHIER_PINCTRL_IECTRL		0x1d00
#if CONFIG_IS_ENABLED(PINCONF)
#endif /* CONFIG_IS_ENABLED(PINCONF) */
#if CONFIG_IS_ENABLED(PINCONF)
#endif
