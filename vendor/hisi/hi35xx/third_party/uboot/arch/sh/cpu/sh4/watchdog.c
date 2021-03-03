#include <common.h>
#include <asm/processor.h>
#include <asm/system.h>
#include <asm/io.h>
#define WDT_BASE	WTCNT
#define WDT_WD		(1 << 6)
#define WDT_RST_P	(0)
#define WDT_RST_M	(1 << 5)
#define WDT_ENABLE	(1 << 7)
#if defined(CONFIG_WATCHDOG)
#endif
