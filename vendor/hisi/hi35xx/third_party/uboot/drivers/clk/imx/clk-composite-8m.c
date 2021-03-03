#include <common.h>
#include <asm/io.h>
#include <malloc.h>
#include <clk-uclass.h>
#include <dm/device.h>
#include <linux/clk-provider.h>
#include <clk.h>
#include "clk.h"
#define UBOOT_DM_CLK_IMX_COMPOSITE "imx_clk_composite"
#define PCG_PREDIV_SHIFT	16
#define PCG_PREDIV_WIDTH	3
#define PCG_PREDIV_MAX		8
#define PCG_DIV_SHIFT		0
#define PCG_DIV_WIDTH		6
#define PCG_DIV_MAX		64
#define PCG_PCS_SHIFT		24
#define PCG_PCS_MASK		0x7
#define PCG_CGC_SHIFT		28
