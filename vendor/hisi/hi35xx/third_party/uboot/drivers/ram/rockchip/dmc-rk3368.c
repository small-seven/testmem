#include <common.h>
#include <clk.h>
#include <dm.h>
#include <dt-bindings/memory/rk3368-dmc.h>
#include <dt-structs.h>
#include <ram.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_rk3368.h>
#include <asm/arch-rockchip/grf_rk3368.h>
#include <asm/arch-rockchip/ddr_rk3368.h>
#include <asm/arch-rockchip/sdram.h>
#include <asm/arch-rockchip/sdram_rk3288.h>
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#define DDR3_MR0_WR(n) \
#define DDR3_MR0_CL(n) \
#define DDR3_MR0_BL8 \
#define DDR3_MR0_DLL_RESET \
#define DDR3_MR1_RTT120OHM \
#define DDR3_MR2_TWL(n) \
#ifdef CONFIG_TPL_BUILD
#ifdef CONFIG_TARGET_EVB_PX5
#else
#endif
#endif
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifdef CONFIG_TPL_BUILD
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifdef CONFIG_TPL_BUILD
#endif
