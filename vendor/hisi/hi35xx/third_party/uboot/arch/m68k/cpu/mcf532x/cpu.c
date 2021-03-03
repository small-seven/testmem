#include <common.h>
#include <vsprintf.h>
#include <watchdog.h>
#include <command.h>
#include <netdev.h>
#include <asm/immap.h>
#include <asm/io.h>
#if defined(CONFIG_DISPLAY_CPUINFO)
#ifdef CONFIG_MCF5301x
#endif
#ifdef CONFIG_MCF532x
#endif
#endif /* CONFIG_DISPLAY_CPUINFO */
#if defined(CONFIG_WATCHDOG)
#ifdef CONFIG_M5329
#else
#endif
#endif				/* CONFIG_WATCHDOG */
#if defined(CONFIG_MCFFEC)
#endif
