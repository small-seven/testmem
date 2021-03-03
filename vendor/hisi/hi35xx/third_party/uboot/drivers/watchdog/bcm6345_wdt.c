#include <common.h>
#include <dm.h>
#include <wdt.h>
#include <clk.h>
#include <asm/io.h>
#define WDT_VAL_REG		0x0
#define WDT_VAL_MIN		0x00000002
#define WDT_VAL_MAX		0xfffffffe
#define WDT_CTL_REG		0x4
#define WDT_CTL_START1_MASK	0x0000ff00
#define WDT_CTL_START2_MASK	0x000000ff
#define WDT_CTL_STOP1_MASK	0x0000ee00
#define WDT_CTL_STOP2_MASK	0x000000ee
