#include <common.h>
#include <asm/processor.h>
#include <asm/mmu.h>
#include <asm/fsl_law.h>
#include <asm/io.h>
#ifdef CONFIG_A003399_NOR_WORKAROUND
#if defined(CONFIG_SYS_PPC_E500_DEBUG_TLB)
#endif
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_P1010_A003549
#endif
#ifdef CONFIG_A003399_NOR_WORKAROUND
#endif
#ifdef CONFIG_ARCH_QEMU_E500
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_P1010_A003549
#endif
#ifdef CONFIG_A003399_NOR_WORKAROUND
#define SRAM_BASE_ADDR	(0x00000000)
#endif
#if defined(CONFIG_SYS_PPC_E500_DEBUG_TLB) && \
#endif
