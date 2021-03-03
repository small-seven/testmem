#include <common.h>
#include <bitfield.h>
#include <clk-uclass.h>
#include <div64.h>
#include <dm.h>
#include <dt-structs.h>
#include <errno.h>
#include <mapmem.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_rk3288.h>
#include <asm/arch-rockchip/grf_rk3288.h>
#include <asm/arch-rockchip/hardware.h>
#include <dt-bindings/clock/rk3288-cru.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/uclass-internal.h>
#include <linux/log2.h>
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#define DIV_TO_RATE(input_rate, div)	((input_rate) / ((div) + 1))
#define PLL_DIVISORS(hz, _nr, _no) {\
#ifndef CONFIG_SPL_BUILD
#define VCO_MAX_KHZ	2200000
#define VCO_MIN_KHZ	440000
#define FREF_MAX_KHZ	2200000
#define FREF_MIN_KHZ	269
#endif /* CONFIG_SPL_BUILD */
#ifndef CONFIG_SPL_BUILD
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifdef CONFIG_SPL_BUILD
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#endif
#if CONFIG_IS_ENABLED(RESET_ROCKCHIP)
#endif
