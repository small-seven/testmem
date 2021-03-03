#include <common.h>
#include <irq_func.h>
#include <asm/arcregs.h>
#include <asm/ptrace.h>
#define E1_MASK		(1 << 1)	/* Level 1 interrupts enable */
#define E2_MASK		(1 << 2)	/* Level 2 interrupts enable */
#ifdef CONFIG_ISA_ARCV2
#endif
