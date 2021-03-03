#include <asm/io.h>
#include <asm/arch/at91_wdt.h>
#include <common.h>
#include <div64.h>
#include <dm.h>
#include <errno.h>
#include <wdt.h>
#define WDT_SEC2TICKS(s)	(((s) << 8) - 1)
