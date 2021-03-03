#include <common.h>
#include <cpu_func.h>
#include <malloc.h>
#include <errno.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/mach-types.h>
#include <asm/arch/systimer.h>
#include <asm/arch/sysctrl.h>
#include <asm/arch/wdt.h>
#include "../drivers/mmc/arm_pl180_mmci.h"
#if defined(CONFIG_SHOW_BOOT_PROGRESS)
#endif
#ifdef CONFIG_SMC911X
#endif
#ifdef CONFIG_ARM_PL180_MMCI
#endif
#ifdef CONFIG_ARMV7_NONSEC
#endif
