#include <common.h>
#include <div64.h>
#include <time.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#define GPTCR_SWR		(1 << 15)	/* Software reset	*/
#define GPTCR_FRR		(1 << 8)	/* Freerun / restart	*/
#define GPTCR_CLKSOURCE_32	(4 << 1)	/* Clock source		*/
#define GPTCR_TEN		1		/* Timer enable		*/
#define timestamp	(gd->arch.tbl)
#define lastinc		(gd->arch.lastinc)
#ifdef CONFIG_MX27_TIMER_HIGH_PRECISION
#else
#define TICK_PER_TIME	((CONFIG_MX27_CLK32 + CONFIG_SYS_HZ / 2) / \
#define US_PER_TICK	(1000000 / CONFIG_MX27_CLK32)
#endif
