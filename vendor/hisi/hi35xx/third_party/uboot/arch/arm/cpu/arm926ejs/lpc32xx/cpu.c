#include <common.h>
#include <cpu_func.h>
#include <netdev.h>
#include <asm/arch/cpu.h>
#include <asm/arch/clk.h>
#include <asm/arch/wdt.h>
#include <asm/arch/sys_proto.h>
#include <asm/io.h>
#if defined(CONFIG_ARCH_CPU_INIT)
#else
#error "You have to select CONFIG_ARCH_CPU_INIT"
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif
#ifdef CONFIG_LPC32XX_ETH
#endif
