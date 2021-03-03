#include <common.h>
#include <vsprintf.h>
#include <watchdog.h>
#include <command.h>
#include <asm/immap.h>
#include <asm/io.h>
#include <netdev.h>
#include "cpu.h"
#ifdef	CONFIG_M5208
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif /* CONFIG_DISPLAY_CPUINFO */
#if defined(CONFIG_WATCHDOG)
#endif				/* #ifdef CONFIG_WATCHDOG */
#endif				/* #ifdef CONFIG_M5208 */
#ifdef  CONFIG_M5271
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif /* CONFIG_DISPLAY_CPUINFO */
#if defined(CONFIG_WATCHDOG)
#endif				/* #ifdef CONFIG_WATCHDOG */
#endif
#ifdef	CONFIG_M5272
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif /* CONFIG_DISPLAY_CPUINFO */
#if defined(CONFIG_WATCHDOG)
#endif				/* #ifdef CONFIG_WATCHDOG */
#endif				/* #ifdef CONFIG_M5272 */
#ifdef	CONFIG_M5275
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif /* CONFIG_DISPLAY_CPUINFO */
#if defined(CONFIG_WATCHDOG)
#endif				/* #ifdef CONFIG_WATCHDOG */
#endif				/* #ifdef CONFIG_M5275 */
#ifdef	CONFIG_M5282
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif /* CONFIG_DISPLAY_CPUINFO */
#endif
#ifdef CONFIG_M5249
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif /* CONFIG_DISPLAY_CPUINFO */
#endif
#ifdef CONFIG_M5253
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif /* CONFIG_DISPLAY_CPUINFO */
#endif
#if defined(CONFIG_MCFFEC)
#endif
