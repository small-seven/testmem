#include <common.h>
#include <bitfield.h>
#include <clk-uclass.h>
#include <dm.h>
#include <errno.h>
#include <syscon.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_px30.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/io.h>
#include <dm/lists.h>
#include <dt-bindings/clock/px30-cru.h>
#define PX30_VOP_PLL_LIMIT			600000000
#define PX30_PLL_RATE(_rate, _refdiv, _fbdiv, _postdiv1,	\
#define PX30_CPUCLK_RATE(_rate, _aclk_div, _pclk_div)		\
#define DIV_TO_RATE(input_rate, div)    ((input_rate) / ((div) + 1))
#define PX30_CLK_DUMP(_id, _name, _iscru)	\
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(RESET_ROCKCHIP)
#endif
