#include <common.h>
#include <asm/io.h>
#include <malloc.h>
#include <clk-uclass.h>
#include <dm/device.h>
#include <dm/uclass.h>
#include <clk.h>
#include "clk.h"
#define UBOOT_DM_CLK_IMX_PLLV3 "imx_clk_pllv3"
#define to_clk_pllv3(_clk) container_of(_clk, struct clk_pllv3, clk)
