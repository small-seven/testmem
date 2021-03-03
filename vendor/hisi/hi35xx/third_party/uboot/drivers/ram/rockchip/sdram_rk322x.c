#include <common.h>
#include <clk.h>
#include <dm.h>
#include <dt-structs.h>
#include <errno.h>
#include <ram.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_rk322x.h>
#include <asm/arch-rockchip/grf_rk322x.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/arch-rockchip/sdram_rk322x.h>
#include <asm/arch-rockchip/uart.h>
#include <asm/arch-rockchip/sdram.h>
#include <asm/types.h>
#include <linux/err.h>
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifdef CONFIG_TPL_BUILD
#define TEST_PATTEN	0x5aa5f00f
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#endif /* CONFIG_TPL_BUILD */
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifdef CONFIG_TPL_BUILD
#endif
#ifdef CONFIG_TPL_BUILD
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#else
#endif
#ifdef CONFIG_TPL_BUILD
#endif
#ifdef CONFIG_TPL_BUILD
#endif
