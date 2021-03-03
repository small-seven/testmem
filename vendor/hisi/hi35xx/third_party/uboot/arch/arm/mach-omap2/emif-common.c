#include <common.h>
#include <asm/emif.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/omap_common.h>
#include <asm/omap_sec_common.h>
#include <asm/utils.h>
#include <linux/compiler.h>
#include <asm/ti-common/ti-edma3.h>
#ifndef CONFIG_OMAP44XX
#if defined(CONFIG_TI_EDMA3) && !defined(CONFIG_DMA)
#else
#endif
#ifdef CONFIG_DRA7XX
#endif
#endif
#ifndef CONFIG_SYS_EMIF_PRECALCULATED_TIMING_REGS
#define print_timing_reg(reg) debug(#reg" - 0x%08x\n", (reg))
#endif /* CONFIG_SYS_EMIF_PRECALCULATED_TIMING_REGS */
#ifdef CONFIG_SYS_AUTOMATIC_SDRAM_DETECTION
#endif /* CONFIG_SYS_AUTOMATIC_SDRAM_DETECTION */
#ifdef CONFIG_SYS_EMIF_PRECALCULATED_TIMING_REGS
#else
#endif /* CONFIG_SYS_EMIF_PRECALCULATED_TIMING_REGS */
#ifndef CONFIG_OMAP44XX
#endif
#ifdef CONFIG_OMAP54XX
#endif
#ifdef CONFIG_SYS_EMIF_PRECALCULATED_TIMING_REGS
#else
#endif
#if defined(CONFIG_TI_SECURE_DEVICE)
#endif
