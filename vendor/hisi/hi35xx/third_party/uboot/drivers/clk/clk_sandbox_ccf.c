#include <common.h>
#include <dm.h>
#include <clk.h>
#include <asm/clk.h>
#include <clk-uclass.h>
#include <linux/clk-provider.h>
#include <sandbox-clk.h>
#define to_clk_gate2(_clk) container_of(_clk, struct clk_gate2, clk)
