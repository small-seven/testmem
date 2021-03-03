#include <common.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <ram.h>
#include <regmap.h>
#include <reset.h>
#include <asm/io.h>
#include <asm/arch/scu_ast2500.h>
#include <asm/arch/sdram_ast2500.h>
#include <asm/arch/wdt.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <dt-bindings/clock/ast2500-scu.h>
#define DDR4_MR46_MODE		0x08000000
#define DDR4_MR5_MODE		0x400
#define DDR4_MR13_MODE		0x101
#define DDR4_MR02_MODE		0x410
#define DDR4_TRFC		0x45457188
#define PHY_CFG_SIZE		15
#define SDRAM_MAX_SIZE		(1024 * 1024 * 1024)
#define SDRAM_MIN_SIZE		(128 * 1024 * 1024)
#ifdef CONFIG_DUALX8_RAM
#endif
