#include <common.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/armv8/mmu.h>
#include <asm/io.h>
#include <asm/arch/mc_me_regs.h>
#include "cpu.h"
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#define S32V234_IRAM_BASE        0x3e800000UL
#define S32V234_IRAM_SIZE        0x800000UL
#define S32V234_DRAM_BASE1       0x80000000UL
#define S32V234_DRAM_SIZE1       0x40000000UL
#define S32V234_DRAM_BASE2       0xC0000000UL
#define S32V234_DRAM_SIZE2       0x20000000UL
#define S32V234_PERIPH_BASE      0x40000000UL
#define S32V234_PERIPH_SIZE      0x40000000UL
#endif
#if defined(CONFIG_ARCH_EARLY_INIT_R)
#endif /* CONFIG_ARCH_EARLY_INIT_R */
