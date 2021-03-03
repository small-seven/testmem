#include <common.h>
#include <errno.h>
#include <linux/bitops.h>
#include <asm/io.h>
#include <asm/arch/sci/sci.h>
#include <misc.h>
#include "pinctrl-imx.h"
#define PADRING_IFMUX_EN_SHIFT		31
#define PADRING_IFMUX_EN_MASK		BIT(31)
#define PADRING_GP_EN_SHIFT		30
#define PADRING_GP_EN_MASK		BIT(30)
#define PADRING_IFMUX_SHIFT		27
#define PADRING_IFMUX_MASK		GENMASK(29, 27)
