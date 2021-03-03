#include <common.h>
#include <bitfield.h>
#include <clk-uclass.h>
#include <dm.h>
#include <div64.h>
#include <errno.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/arch/cru_rk3308.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/hardware.h>
#include <dm/lists.h>
#include <dt-bindings/clock/rk3308-cru.h>
#define DIV_TO_RATE(input_rate, div)    ((input_rate) / ((div) + 1))
#define RK3308_CPUCLK_RATE(_rate, _aclk_div, _pclk_div)         \
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(RESET_ROCKCHIP)
#endif
