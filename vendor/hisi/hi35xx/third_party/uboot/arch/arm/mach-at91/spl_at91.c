#include <common.h>
#include <asm/io.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91sam9_matrix.h>
#include <asm/arch/at91_pit.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/at91_wdt.h>
#include <asm/arch/clk.h>
#include <spl.h>
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if !defined(CONFIG_WDT_AT91)
#endif
#if defined(CONFIG_SYS_AT91_PLLB)
#endif
#if defined(CONFIG_AT91SAM9X5) || defined(CONFIG_AT91SAM9N12)
#else
#endif
#if defined(CONFIG_SPL_SERIAL_SUPPORT)
#endif
