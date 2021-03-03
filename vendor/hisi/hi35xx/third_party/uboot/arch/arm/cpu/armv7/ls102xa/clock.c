#include <common.h>
#include <asm/io.h>
#include <asm/arch/immap_ls102xa.h>
#include <asm/arch/clock.h>
#include <fsl_ifc.h>
#ifndef CONFIG_SYS_FSL_NUM_CC_PLLS
#define CONFIG_SYS_FSL_NUM_CC_PLLS      2
#endif
#ifdef CONFIG_DDR_CLK_FREQ
#else
#endif
#if defined(CONFIG_FSL_IFC)
#endif
#if defined(CONFIG_FSL_ESDHC)
#endif
