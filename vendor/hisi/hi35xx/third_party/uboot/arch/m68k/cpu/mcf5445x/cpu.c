#include <common.h>
#include <vsprintf.h>
#include <watchdog.h>
#include <command.h>
#include <netdev.h>
#include <asm/immap.h>
#include <asm/io.h>
#if defined(CONFIG_DISPLAY_CPUINFO)
#ifdef CONFIG_PCI
#else
#endif
#endif /* CONFIG_DISPLAY_CPUINFO */
#if defined(CONFIG_MCFFEC)
#endif
