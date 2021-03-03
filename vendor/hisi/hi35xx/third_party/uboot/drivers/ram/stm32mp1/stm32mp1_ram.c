#include <common.h>
#include <clk.h>
#include <dm.h>
#include <ram.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include "stm32mp1_ddr.h"
#define PARAM(x, y) \
#define CTL_PARAM(x) PARAM("st,ctl-"#x, c_##x)
#define PHY_PARAM(x) PARAM("st,phy-"#x, p_##x)
#if !defined(CONFIG_STM32MP1_TRUSTED) && \
#else
#endif
