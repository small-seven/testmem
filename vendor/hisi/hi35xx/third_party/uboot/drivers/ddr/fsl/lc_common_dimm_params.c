#include <common.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr.h>
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#ifdef CONFIG_SYS_FSL_DDR3
#else
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#endif
#else	/* for DDR1 and DDR2 */
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR1) || defined(CONFIG_SYS_FSL_DDR2)
#endif
#ifndef CONFIG_FSL_DDR_FIRST_SLOT_QUAD_CAPABLE
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR1) || defined(CONFIG_SYS_FSL_DDR2)
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR1) || defined(CONFIG_SYS_FSL_DDR2)
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#if defined(CONFIG_SYS_FSL_DDR2)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
