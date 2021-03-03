#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <regmap.h>
#include <syscon.h>
#include "pinctrl-rockchip.h"
#define RK3308_PULL_OFFSET		0xa0
#define RK3308_DRV_GRF_OFFSET		0x100
#define RK3308_SCHMITT_PINS_PER_REG	8
#define RK3308_SCHMITT_BANK_STRIDE	16
#define RK3308_SCHMITT_GRF_OFFSET	0x1a0
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
