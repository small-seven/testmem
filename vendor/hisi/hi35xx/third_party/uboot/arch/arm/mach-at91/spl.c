#include <common.h>
#include <asm/io.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_wdt.h>
#include <asm/arch/clk.h>
#include <spl.h>
#if !defined(CONFIG_WDT_AT91)
#endif
#if defined(CONFIG_SAMA5D2) || defined(CONFIG_SAMA5D3) || \
#include <asm/arch/sama5_boot.h>
#if defined(CONFIG_SYS_USE_MMC) || defined(CONFIG_SD_BOOT)
#if defined(CONFIG_SPL_OF_CONTROL)
#else
#endif
#endif
#if defined(CONFIG_SYS_USE_SERIALFLASH) || \
#endif
#else
#if defined(CONFIG_SYS_USE_MMC) || defined(CONFIG_SD_BOOT)
#elif defined(CONFIG_SYS_USE_NANDFLASH) || defined(CONFIG_NAND_BOOT)
#elif defined(CONFIG_SYS_USE_SERIALFLASH) || \
#endif
#endif
