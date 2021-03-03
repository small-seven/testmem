#include <common.h>
#include <asm/io.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_pit.h>
#include <asm/arch/at91_pmc.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/at91_wdt.h>
#include <asm/arch/clk.h>
#include <spl.h>
#if defined(CONFIG_SAMA5D2)
#endif
#if defined(CONFIG_SPL_AT91_MCK_BYPASS)
#else
#endif
#if !defined(CONFIG_SAMA5D2)
#endif
#if !defined(CONFIG_SAMA5D4) && !defined(CONFIG_SAMA5D2)
#endif
#ifdef CONFIG_SAMA5D2
#endif
#if !defined(CONFIG_WDT_AT91)
#endif
