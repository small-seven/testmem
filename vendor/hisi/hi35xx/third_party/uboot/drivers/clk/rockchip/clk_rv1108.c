#include <common.h>
#include <bitfield.h>
#include <clk-uclass.h>
#include <dm.h>
#include <errno.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_rv1108.h>
#include <asm/arch-rockchip/hardware.h>
#include <dm/lists.h>
#include <dt-bindings/clock/rv1108-cru.h>
#define DIV_TO_RATE(input_rate, div)	((input_rate) / ((div) + 1))
#define PLL_DIVISORS(hz, _refdiv, _postdiv1, _postdiv2) {\
#if CONFIG_IS_ENABLED(RESET_ROCKCHIP)
#endif
