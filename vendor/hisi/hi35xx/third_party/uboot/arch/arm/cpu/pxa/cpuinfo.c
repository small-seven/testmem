#include <common.h>
#include <asm/io.h>
#include <errno.h>
#include <linux/compiler.h>
#ifdef CONFIG_CPU_PXA25X
#if ((CONFIG_SYS_INIT_SP_ADDR) != 0xfffff800)
#error "Init SP address must be set to 0xfffff800 for PXA250"
#endif
#endif
#define	CPU_MASK_PXA_PRODID	0x000003f0
#define	CPU_MASK_PXA_REVID	0x0000000f
#define	CPU_MASK_PRODREV	(CPU_MASK_PXA_PRODID | CPU_MASK_PXA_REVID)
#define	CPU_VALUE_PXA25X	0x100
#define	CPU_VALUE_PXA27X	0x110
#ifdef	CONFIG_DISPLAY_CPUINFO
#ifdef	CONFIG_CPU_PXA26X
#else
#endif
#endif
