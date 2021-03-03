#include <common.h>
#include <asm/processor.h>
#include <asm/io.h>
#if defined(CONFIG_CPU_SH4) || defined(CONFIG_ARCH_RMOBILE)
#define TSTR	0x4
#define TCR0	0x10
#endif /* CONFIG_CPU_SH4 */
#define TCR_TPSC	0x07
#define TSTR_STR0	BIT(0)
