#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <regmap.h>
#include <syscon.h>
#include "pinctrl-rockchip.h"
#define RK3228_PULL_OFFSET		0x100
#define RK3228_DRV_GRF_OFFSET		0x200
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
