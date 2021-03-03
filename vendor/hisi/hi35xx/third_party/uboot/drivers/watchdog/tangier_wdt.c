#include <common.h>
#include <dm.h>
#include <wdt.h>
#include <div64.h>
#include <asm/scu.h>
#define WDT_PRETIMEOUT		15
#define WDT_TIMEOUT_MIN		(1 + WDT_PRETIMEOUT)
#define WDT_TIMEOUT_MAX		170
