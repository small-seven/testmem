#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <dt-structs.h>
#include <errno.h>
#include <mapmem.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_rk3188.h>
#include <asm/arch-rockchip/grf_rk3188.h>
#include <asm/arch-rockchip/hardware.h>
#include <dt-bindings/clock/rk3188-cru.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/uclass-internal.h>
#include <linux/log2.h>
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#define DIV_TO_RATE(input_rate, div)	((input_rate) / ((div) + 1))
#define PLL_DIVISORS(hz, _nr, _no) {\
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifdef CONFIG_SPL_BUILD
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#endif
#if CONFIG_IS_ENABLED(RESET_ROCKCHIP)
#endif
