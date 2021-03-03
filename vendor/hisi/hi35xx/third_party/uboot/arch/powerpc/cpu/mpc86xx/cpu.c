#include <common.h>
#include <cpu_func.h>
#include <vsprintf.h>
#include <watchdog.h>
#include <command.h>
#include <asm/cache.h>
#include <asm/mmu.h>
#include <mpc86xx.h>
#include <asm/fsl_law.h>
#include <asm/ppc.h>
#ifndef CONFIG_MP
#endif
#if defined(CONFIG_ARCH_MPC8610)
#elif defined(CONFIG_ARCH_MPC8641)
#endif
#if defined(CONFIG_WATCHDOG)
#if defined(CONFIG_ARCH_MPC8610)
#endif
#endif	/* CONFIG_WATCHDOG */
