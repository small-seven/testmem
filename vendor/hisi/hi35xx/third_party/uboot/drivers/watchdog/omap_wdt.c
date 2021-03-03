#include <common.h>
#include <watchdog.h>
#include <asm/arch/hardware.h>
#include <asm/io.h>
#include <asm/processor.h>
#include <asm/arch/cpu.h>
#include <wdt.h>
#include <dm.h>
#include <errno.h>
#define WDT_HW_TIMEOUT 60
#if !CONFIG_IS_ENABLED(WDT)
#else
#endif /* !CONFIG_IS_ENABLED(WDT) */
