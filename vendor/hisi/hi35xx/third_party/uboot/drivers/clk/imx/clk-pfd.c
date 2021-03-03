#include <common.h>
#include <asm/io.h>
#include <malloc.h>
#include <clk-uclass.h>
#include <dm/device.h>
#include <linux/clk-provider.h>
#include <div64.h>
#include <clk.h>
#include "clk.h"
#define UBOOT_DM_CLK_IMX_PFD "imx_clk_pfd"
#define to_clk_pfd(_clk) container_of(_clk, struct clk_pfd, clk)
#define SET	0x4
#define CLR	0x8
#define OTG	0xc
