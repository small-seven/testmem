#include <common.h>
#include <asm/io.h>
#include <asm/types.h>
#include <mach/tlb.h>
#include <mach/ddr.h>
#if defined(CONFIG_SOC_OCELOT) || defined(CONFIG_SOC_JR2) || \
#endif
#if (CONFIG_SYS_TEXT_BASE != 0x20000000)
#else
#endif
