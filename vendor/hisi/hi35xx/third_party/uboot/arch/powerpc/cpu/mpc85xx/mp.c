#include <common.h>
#include <cpu_func.h>
#include <env.h>
#include <asm/processor.h>
#include <env.h>
#include <ioports.h>
#include <lmb.h>
#include <asm/io.h>
#include <asm/mmu.h>
#include <asm/fsl_law.h>
#include <fsl_ddr_sdram.h>
#include "mp.h"
#ifdef CONFIG_FSL_CORENET
#else
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A004468
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A004468
#endif /* CONFIG_SYS_FSL_ERRATUM_A004468 */
#ifdef CONFIG_FSL_CORENET
#ifdef CONFIG_MPC8xxx_DISABLE_BPTR
#endif
#else
#ifdef CONFIG_MPC8xxx_DISABLE_BPTR
#endif
#endif
