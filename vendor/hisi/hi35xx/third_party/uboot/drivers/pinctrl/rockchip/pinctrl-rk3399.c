#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <regmap.h>
#include <syscon.h>
#include "pinctrl-rockchip.h"
#define RK3399_PULL_GRF_OFFSET		0xe040
#define RK3399_PULL_PMU_OFFSET		0x40
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
