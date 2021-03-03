#include <common.h>
#include <irq_func.h>
#include <time.h>
#include <asm/timer.h>
#include <asm/immap.h>
#include <watchdog.h>
#ifndef CONFIG_SYS_WATCHDOG_FREQ
#define CONFIG_SYS_WATCHDOG_FREQ (CONFIG_SYS_HZ / 2)
#endif
#if defined(CONFIG_MCFTMR)
#ifndef CONFIG_SYS_UDELAY_BASE
#	error	"uDelay base not defined!"
#endif
#if !defined(CONFIG_SYS_TMR_BASE) || !defined(CONFIG_SYS_INTR_BASE) || !defined(CONFIG_SYS_TMRINTR_NO) || !defined(CONFIG_SYS_TMRINTR_MASK)
#	error	"TMR_BASE, INTR_BASE, TMRINTR_NO or TMRINTR_MASk not defined!"
#endif
#endif				/* CONFIG_MCFTMR */
#if defined(CONFIG_MCFPIT)
#if !defined(CONFIG_SYS_PIT_BASE)
#	error	"CONFIG_SYS_PIT_BASE not defined!"
#endif
#endif				/* CONFIG_MCFPIT */
