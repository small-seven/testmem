#include <common.h>
#include <asm/io.h>
#include <malloc.h>
#include <clk-uclass.h>
#include <dm/device.h>
#include <linux/clk-provider.h>
#include <clk.h>
#include "clk.h"
#define UBOOT_DM_CLK_IMX_GATE2 "imx_clk_gate2"
#define to_clk_gate2(_clk) container_of(_clk, struct clk_gate2, clk)
