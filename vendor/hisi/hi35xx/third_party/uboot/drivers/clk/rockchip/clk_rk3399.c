#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <dt-structs.h>
#include <errno.h>
#include <mapmem.h>
#include <syscon.h>
#include <bitfield.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_rk3399.h>
#include <asm/arch-rockchip/hardware.h>
#include <dm/lists.h>
#include <dt-bindings/clock/rk3399-cru.h>
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#define RATE_TO_DIV(input_rate, output_rate) \
#define DIV_TO_RATE(input_rate, div)		((input_rate) / ((div) + 1))
#define PLL_DIVISORS(hz, _refdiv, _postdiv1, _postdiv2) {\
#if defined(CONFIG_SPL_BUILD)
#else
#endif
#define VCO_MAX_KHZ	(3200 * (MHz / KHz))
#define VCO_MIN_KHZ	(800 * (MHz / KHz))
#define OUTPUT_MAX_KHZ	(3200 * (MHz / KHz))
#define OUTPUT_MIN_KHZ	(16 * (MHz / KHz))
#define PLL_DIV_MIN	16
#define PLL_DIV_MAX	3200
#define I2C_CLK_REG_MASK(bus) \
#define I2C_CLK_REG_VALUE(bus, clk_div) \
#define I2C_CLK_DIV_VALUE(con, bus) \
#define I2C_PMUCLK_REG_MASK(bus) \
#define I2C_PMUCLK_REG_VALUE(bus, clk_div) \
#define PMUSGRF_DDR_RGN_CON16 0xff330040
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_SPL_BUILD
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#endif
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(RESET_ROCKCHIP)
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA) || !defined(CONFIG_SPL_BUILD)
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(CONFIG_RESET_ROCKCHIP)
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
