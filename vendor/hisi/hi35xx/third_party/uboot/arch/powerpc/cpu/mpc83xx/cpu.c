#include <common.h>
#include <cpu_func.h>
#include <irq_func.h>
#include <vsprintf.h>
#include <watchdog.h>
#include <command.h>
#include <mpc83xx.h>
#include <asm/processor.h>
#include <linux/libfdt.h>
#include <tsec.h>
#include <netdev.h>
#include <fsl_esdhc.h>
#if defined(CONFIG_BOOTCOUNT_LIMIT) && !defined(CONFIG_ARCH_MPC831X)
#include <linux/immap_qe.h>
#include <asm/io.h>
#endif
#ifndef CONFIG_CPU_MPC83XX
#endif
#ifndef CONFIG_SYSRESET
#ifndef MPC83xx_RESET
#endif
#ifdef MPC83xx_RESET
#else	/* ! MPC83xx_RESET */
#endif	/* MPC83xx_RESET */
#endif
#ifndef CONFIG_TIMER
#endif
#if defined(CONFIG_WATCHDOG)
#endif
#ifndef CONFIG_DM_ETH
#if defined(CONFIG_UEC_ETH)
#endif
#if defined(CONFIG_TSEC_ENET)
#endif
#endif /* !CONFIG_DM_ETH */
#ifdef CONFIG_FSL_ESDHC
#else
#endif
