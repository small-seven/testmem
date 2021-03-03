#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <regmap.h>
#include "pinctrl-rockchip.h"
#define RK3288_PULL_OFFSET		0x140
#define RK3288_PULL_PMU_OFFSET          0x64
#define RK3288_DRV_PMU_OFFSET		0x70
#define RK3288_DRV_GRF_OFFSET		0x1c0
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
