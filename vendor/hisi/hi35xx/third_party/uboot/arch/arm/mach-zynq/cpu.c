#include <common.h>
#include <cpu_func.h>
#include <zynqpl.h>
#include <asm/io.h>
#include <asm/arch/clk.h>
#include <asm/arch/hardware.h>
#include <asm/arch/ps7_init_gpl.h>
#include <asm/arch/sys_proto.h>
#define ZYNQ_SILICON_VER_MASK	0xF0000000
#define ZYNQ_SILICON_VER_SHIFT	28
#if (defined(CONFIG_FPGA) && !defined(CONFIG_SPL_BUILD)) || \
#endif
#if defined(CONFIG_FPGA)
#endif
#ifndef CONFIG_SPL_BUILD
#if (CONFIG_SYS_SDRAM_BASE == 0)
#endif
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#endif
#if defined(CONFIG_ARCH_EARLY_INIT_R)
#if (defined(CONFIG_FPGA) && !defined(CONFIG_SPL_BUILD)) || \
#endif
#endif
#ifdef CONFIG_DISPLAY_CPUINFO
#endif
