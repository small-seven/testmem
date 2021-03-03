#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#if defined(CONFIG_ARCH_MVEBU)
#include "../../../drivers/ddr/marvell/axp/xor.h"
#include "../../../drivers/ddr/marvell/axp/xor_regs.h"
#endif
#define REG_CPUCS_WIN_ENABLE		(1 << 0)
#define REG_CPUCS_WIN_WR_PROTECT	(1 << 1)
#define REG_CPUCS_WIN_WIN0_CS(x)	(((x) & 0x3) << 2)
#define REG_CPUCS_WIN_SIZE(x)		(((x) & 0xff) << 24)
#ifndef MVEBU_SDRAM_SIZE_MAX
#define MVEBU_SDRAM_SIZE_MAX		0xc0000000
#endif
#define SCRUB_MAGIC		0xbeefdead
#define SCRB_XOR_UNIT		0
#define SCRB_XOR_CHAN		1
#define SCRB_XOR_WIN		0
#define XEBARX_BASE_OFFS	16
#if defined(CONFIG_ARCH_MVEBU)
#else
#endif
#if defined(CONFIG_ARCH_MVEBU)
#endif
