#include <common.h>
#include <bitfield.h>
#include <clk-uclass.h>
#include <dm.h>
#include <errno.h>
#include <syscon.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_rk3328.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/arch-rockchip/grf_rk3328.h>
#include <asm/io.h>
#include <dm/lists.h>
#include <dt-bindings/clock/rk3328-cru.h>
#define RATE_TO_DIV(input_rate, output_rate) \
#define DIV_TO_RATE(input_rate, div)    ((input_rate) / ((div) + 1))
#define PLL_DIVISORS(hz, _refdiv, _postdiv1, _postdiv2) {\
#define VCO_MAX_KHZ	(3200 * (MHz / KHz))
#define VCO_MIN_KHZ	(800 * (MHz / KHz))
#define OUTPUT_MAX_KHZ	(3200 * (MHz / KHz))
#define OUTPUT_MIN_KHZ	(16 * (MHz / KHz))
#define PLL_DIV_MIN	16
#define PLL_DIV_MAX	3200
#if CONFIG_IS_ENABLED(RESET_ROCKCHIP)
#endif
