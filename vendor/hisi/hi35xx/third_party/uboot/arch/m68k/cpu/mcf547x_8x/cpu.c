#include <common.h>
#include <vsprintf.h>
#include <watchdog.h>
#include <command.h>
#include <netdev.h>
#include <asm/immap.h>
#include <asm/io.h>
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif /* CONFIG_DISPLAY_CPUINFO */
#if defined(CONFIG_HW_WATCHDOG)
#endif				/* CONFIG_HW_WATCHDOG */
#if defined(CONFIG_FSLDMAFEC) || defined(CONFIG_MCFFEC)
#if defined(CONFIG_FSLDMAFEC)
#endif
#if defined(CONFIG_MCFFEC)
#endif
#endif
