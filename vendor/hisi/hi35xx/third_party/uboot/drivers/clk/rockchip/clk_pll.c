#include <bitfield.h>
#include <clk-uclass.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/hardware.h>
#include <div64.h>
#define PLL_MODE_MASK				0x3
#define PLL_RK3328_MODE_MASK			0x1
#define RK3036_PLLCON0_FBDIV_MASK		0xfff
#define RK3036_PLLCON0_FBDIV_SHIFT		0
#define RK3036_PLLCON0_POSTDIV1_MASK		0x7 << 12
#define RK3036_PLLCON0_POSTDIV1_SHIFT		12
#define RK3036_PLLCON1_REFDIV_MASK		0x3f
#define RK3036_PLLCON1_REFDIV_SHIFT		0
#define RK3036_PLLCON1_POSTDIV2_MASK		0x7 << 6
#define RK3036_PLLCON1_POSTDIV2_SHIFT		6
#define RK3036_PLLCON1_DSMPD_MASK		0x1 << 12
#define RK3036_PLLCON1_DSMPD_SHIFT		12
#define RK3036_PLLCON2_FRAC_MASK		0xffffff
#define RK3036_PLLCON2_FRAC_SHIFT		0
#define RK3036_PLLCON1_PWRDOWN_SHIT		13
#define MHZ		1000000
#define KHZ		1000
#define MIN_FOUTVCO_FREQ	(800 * MHZ)
#define MAX_FOUTVCO_FREQ	(2000 * MHZ)
