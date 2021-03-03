#include <clk.h>
#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <ram.h>
#include <asm/arch/misc.h>
#include <asm/sections.h>
#include <dm/uclass.h>
#include <linux/io.h>
#include <dt-bindings/clock/mt7629-clk.h>
#define L2_CFG_BASE		0x10200000
#define L2_CFG_SIZE		0x1000
#define L2_SHARE_CFG_MP0	0x7f0
#define L2_SHARE_MODE_OFF	BIT(8)
