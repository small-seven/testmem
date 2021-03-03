#include <common.h>
#include <irq_func.h>
#include <asm/timer.h>
#include <asm/immap.h>
#include <asm/io.h>
#if defined(CONFIG_SLTTMR)
#ifndef CONFIG_SYS_UDELAY_BASE
#	error	"uDelay base not defined!"
#endif
#if !defined(CONFIG_SYS_TMR_BASE) || !defined(CONFIG_SYS_INTR_BASE) || !defined(CONFIG_SYS_TMRINTR_NO) || !defined(CONFIG_SYS_TMRINTR_MASK)
#	error	"TMR_BASE, INTR_BASE, TMRINTR_NO or TMRINTR_MASk not defined!"
#endif
#endif				/* CONFIG_SLTTMR */
