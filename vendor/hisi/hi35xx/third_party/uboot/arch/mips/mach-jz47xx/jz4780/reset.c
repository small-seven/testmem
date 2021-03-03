#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <mach/jz4780.h>
#define WDT_TDR		0x00
#define WDT_TCER	0x04
#define WDT_TCNT	0x08
#define WDT_TCSR	0x0C
#define WDT_TCSR_PRESCALE_BIT	3
#define WDT_TCSR_PRESCALE_MASK	(0x7 << WDT_TCSR_PRESCALE_BIT)
#define WDT_TCSR_EXT_EN		BIT(2)
#define WDT_TCSR_RTC_EN		BIT(1)
#define WDT_TCSR_PCK_EN		BIT(0)
#define WDT_TCER_TCEN		BIT(0)
