#include <common.h>
#include <asm/io.h>
#include <asm/arch/sysmap.h>
#define EN_MASK		0x08000000	/* Enable timer */
#define SRSTEN_MASK	0x04000000	/* Enable soft reset */
#define CLKS_SHIFT	20		/* Clock period shift */
#define LD_SHIFT	0		/* Reload value shift */
