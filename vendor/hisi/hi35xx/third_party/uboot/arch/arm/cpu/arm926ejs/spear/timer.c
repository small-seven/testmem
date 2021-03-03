#include <common.h>
#include <time.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/spr_gpt.h>
#include <asm/arch/spr_misc.h>
#define GPT_RESOLUTION	(CONFIG_SPEAR_HZ_CLOCK / CONFIG_SPEAR_HZ)
#define READ_TIMER()	(readl(&gpt_regs_p->count) & GPT_FREE_RUNNING)
#define timestamp gd->arch.tbl
#define lastdec gd->arch.lastinc
#if defined(CONFIG_SPEAR3XX)
#elif defined(CONFIG_SPEAR600)
#else
# error Incorrect config. Can only be SPEAR{600|300|310|320}
#endif
