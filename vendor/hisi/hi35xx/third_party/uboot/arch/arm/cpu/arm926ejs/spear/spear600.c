#include <common.h>
#include <asm/hardware.h>
#include <asm/io.h>
#include <asm/arch/spr_misc.h>
#include <asm/arch/spr_defs.h>
#if (CONFIG_DDR_HCLK)
#elif (CONFIG_DDR_2HCLK)
#elif (CONFIG_DDR_PLL2)
#endif
