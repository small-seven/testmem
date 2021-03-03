#include <common.h>
#include <spl.h>
#include <version.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/spr_defs.h>
#include <asm/arch/spr_misc.h>
#include <asm/arch/spr_syscntl.h>
#include <linux/mtd/st_smi.h>
#if (CONFIG_DDR_HCLK)
#elif (CONFIG_DDR_2HCLK)
#elif (CONFIG_DDR_PLL2)
#else
#error "please define one of CONFIG_DDR_(HCLK|2HCLK|PLL2)"
#endif
#if defined(CONFIG_SPEAR600)
#elif defined(CONFIG_SPEAR300)
#elif defined(CONFIG_SPEAR310)
#elif defined(CONFIG_SPEAR320)
#endif
#if defined(CONFIG_SPL_SYS_THUMB_BUILD)
#else
#endif
