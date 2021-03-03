#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <regmap.h>
#include <syscon.h>
#include "pinctrl-rockchip.h"
#define RK3128_PULL_OFFSET		0x118
#define RK3128_PULL_PINS_PER_REG	16
#define RK3128_PULL_BANK_STRIDE		8
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
