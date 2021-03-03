#include <common.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#include <dm/pinctrl.h>
#include "pinctrl-snapdragon.h"
#define GPIO_CONFIG_OFFSET(x)         ((x) * 0x1000)
#define TLMM_GPIO_PULL_MASK GENMASK(1, 0)
#define TLMM_FUNC_SEL_MASK GENMASK(5, 2)
#define TLMM_DRV_STRENGTH_MASK GENMASK(8, 6)
#define TLMM_GPIO_DISABLE BIT(9)
