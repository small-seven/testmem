#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <dt-structs.h>
#include <errno.h>
#include <mapmem.h>
#include <syscon.h>
#include <bitfield.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_rk3368.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/io.h>
#include <dm/lists.h>
#include <dt-bindings/clock/rk3368-cru.h>
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#define OSC_HZ		(24 * 1000 * 1000)
#define APLL_L_HZ	(800 * 1000 * 1000)
#define APLL_B_HZ	(816 * 1000 * 1000)
#define GPLL_HZ		(576 * 1000 * 1000)
#define CPLL_HZ		(400 * 1000 * 1000)
#define DIV_TO_RATE(input_rate, div)    ((input_rate) / ((div) + 1))
#define PLL_DIVISORS(hz, _nr, _no) { \
#if IS_ENABLED(CONFIG_SPL_BUILD) || IS_ENABLED(CONFIG_TPL_BUILD)
#if !defined(CONFIG_TPL_BUILD)
#endif
#endif
#if IS_ENABLED(CONFIG_SPL_BUILD) || IS_ENABLED(CONFIG_TPL_BUILD)
#endif
#if IS_ENABLED(CONFIG_SPL_BUILD) || IS_ENABLED(CONFIG_TPL_BUILD)
#if !defined(CONFIG_TPL_BUILD)
#endif
#endif
#if !IS_ENABLED(CONFIG_SPL_BUILD) || CONFIG_IS_ENABLED(MMC_SUPPORT)
#endif
#if IS_ENABLED(CONFIG_TPL_BUILD)
#endif
#if CONFIG_IS_ENABLED(GMAC_ROCKCHIP)
#endif
#if !IS_ENABLED(CONFIG_SPL_BUILD) || CONFIG_IS_ENABLED(MMC_SUPPORT)
#endif
#if IS_ENABLED(CONFIG_TPL_BUILD)
#endif
#if !IS_ENABLED(CONFIG_SPL_BUILD) || CONFIG_IS_ENABLED(MMC_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(GMAC_ROCKCHIP)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if IS_ENABLED(CONFIG_SPL_BUILD) || IS_ENABLED(CONFIG_TPL_BUILD)
#endif
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(RESET_ROCKCHIP)
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
