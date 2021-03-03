#include <common.h>
#include <asm/io.h>
#include <malloc.h>
#include <clk-uclass.h>
#include <dm/device.h>
#include <linux/clk-provider.h>
#include <linux/iopoll.h>
#include <clk.h>
#include <div64.h>
#include "clk.h"
#define UBOOT_DM_CLK_IMX_PLL1443X "imx_clk_pll1443x"
#define UBOOT_DM_CLK_IMX_PLL1416X "imx_clk_pll1416x"
#define GNRL_CTL	0x0
#define DIV_CTL		0x4
#define LOCK_STATUS	BIT(31)
#define LOCK_SEL_MASK	BIT(29)
#define CLKE_MASK	BIT(11)
#define RST_MASK	BIT(9)
#define BYPASS_MASK	BIT(4)
#define MDIV_SHIFT	12
#define MDIV_MASK	GENMASK(21, 12)
#define PDIV_SHIFT	4
#define PDIV_MASK	GENMASK(9, 4)
#define SDIV_SHIFT	0
#define SDIV_MASK	GENMASK(2, 0)
#define KDIV_SHIFT	0
#define KDIV_MASK	GENMASK(15, 0)
#define LOCK_TIMEOUT_US		10000
#define to_clk_pll14xx(_clk) container_of(_clk, struct clk_pll14xx, clk)
