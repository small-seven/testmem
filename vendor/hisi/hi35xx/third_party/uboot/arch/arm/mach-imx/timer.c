#include <common.h>
#include <time.h>
#include <asm/io.h>
#include <div64.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#define GPTCR_SWR		(1 << 15)	/* Software reset */
#define GPTCR_24MEN	    (1 << 10)	/* Enable 24MHz clock input */
#define GPTCR_FRR		(1 << 9)	/* Freerun / restart */
#define GPTCR_CLKSOURCE_32	(4 << 6)	/* Clock source 32khz */
#define GPTCR_CLKSOURCE_OSC	(5 << 6)	/* Clock source OSC */
#define GPTCR_CLKSOURCE_PRE	(1 << 6)	/* Clock source PRECLK */
#define GPTCR_CLKSOURCE_MASK (0x7 << 6)
#define GPTCR_TEN		1		/* Timer enable */
#define GPTPR_PRESCALER24M_SHIFT 12
#define GPTPR_PRESCALER24M_MASK (0xF << GPTPR_PRESCALER24M_SHIFT)
#if defined(CONFIG_MX6)
#else
#endif
#ifdef CONFIG_MXC_GPT_HCLK
#else
#endif
#ifdef CONFIG_MXC_GPT_HCLK
#else
#endif
